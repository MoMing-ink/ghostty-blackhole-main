// gl_texture.cpp  PBO-based D3D11-staging -> OpenGL texture upload
// Double-buffered PBO pipeline for async GPU DMA transfer.
#include "gl_texture.h"
#include <cstdio>
#include <cstring>
#include <cstddef>   // ptrdiff_t

// ---- OpenGL 1.2+ constants not in minimal gl.h ----
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE        0x812F
#endif
#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT             0x80E1
#endif
#ifndef GL_RGBA8
#define GL_RGBA8                0x8058
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER
#define GL_PIXEL_UNPACK_BUFFER  0x88EC
#endif
#ifndef GL_STREAM_DRAW
#define GL_STREAM_DRAW          0x88E0
#endif
#ifndef GL_WRITE_ONLY
#define GL_WRITE_ONLY           0x88B9
#endif
#ifndef GLsizeiptr
#define GLsizeiptr ptrdiff_t
#endif

// ---- PBO function pointers (loaded via wglGetProcAddress) ----
typedef void   (WINAPI *PFN_glGenBuffers)(GLsizei, GLuint*);
typedef void   (WINAPI *PFN_glBindBuffer)(GLenum, GLuint);
typedef void   (WINAPI *PFN_glBufferData)(GLenum, GLsizeiptr, const void*, GLenum);
typedef void*  (WINAPI *PFN_glMapBuffer)(GLenum, GLenum);
typedef GLboolean (WINAPI *PFN_glUnmapBuffer)(GLenum);
typedef void   (WINAPI *PFN_glDeleteBuffers)(GLsizei, const GLuint*);

static PFN_glGenBuffers    p_glGenBuffers    = nullptr;
static PFN_glBindBuffer    p_glBindBuffer    = nullptr;
static PFN_glBufferData    p_glBufferData    = nullptr;
static PFN_glMapBuffer     p_glMapBuffer     = nullptr;
static PFN_glUnmapBuffer   p_glUnmapBuffer   = nullptr;
static PFN_glDeleteBuffers p_glDeleteBuffers = nullptr;
static bool pboFuncsLoaded = false;

static bool loadPBOFunctions() {
    if (pboFuncsLoaded) return true;
    p_glGenBuffers    = (PFN_glGenBuffers)    wglGetProcAddress("glGenBuffers");
    p_glBindBuffer    = (PFN_glBindBuffer)    wglGetProcAddress("glBindBuffer");
    p_glBufferData    = (PFN_glBufferData)    wglGetProcAddress("glBufferData");
    p_glMapBuffer     = (PFN_glMapBuffer)     wglGetProcAddress("glMapBuffer");
    p_glUnmapBuffer   = (PFN_glUnmapBuffer)   wglGetProcAddress("glUnmapBuffer");
    p_glDeleteBuffers = (PFN_glDeleteBuffers) wglGetProcAddress("glDeleteBuffers");

    pboFuncsLoaded = (p_glGenBuffers && p_glBindBuffer && p_glBufferData &&
                      p_glMapBuffer && p_glUnmapBuffer && p_glDeleteBuffers);
    if (!pboFuncsLoaded)
        fprintf(stderr, "[PBO] Failed to load PBO functions\n");
    return pboFuncsLoaded;
}

// ---- Public API ----

bool GLTex_Init(GLTextureUpload& gt, int width, int height) {
    gt.active = false;
    if (!loadPBOFunctions()) return false;

    gt.width  = width;
    gt.height = height;

    // Create GL texture
    glGenTextures(1, &gt.tex);
    glBindTexture(GL_TEXTURE_2D, gt.tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // Allocate texture storage
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0,
                 GL_BGRA_EXT, GL_UNSIGNED_BYTE, nullptr);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Create 2 PBOs (double-buffered)
    GLsizeiptr bufSize = (GLsizeiptr)width * height * 4;
    for (int i = 0; i < 2; i++) {
        p_glGenBuffers(1, &gt.pbo[i]);
        p_glBindBuffer(GL_PIXEL_UNPACK_BUFFER, gt.pbo[i]);
        p_glBufferData(GL_PIXEL_UNPACK_BUFFER, bufSize, nullptr, GL_STREAM_DRAW);
    }
    p_glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    gt.pboIdx = 0;
    gt.active = true;
    fprintf(stderr, "[PBO] Texture ready: %dx%d (double-buffered PBO)\n",
            width, height);
    return true;
}

void GLTex_Upload(GLTextureUpload& gt, const void* data, int stride) {
    if (!gt.active || !data) return;

    int idx = gt.pboIdx;
    gt.pboIdx = (idx + 1) % 2;  // swap for next frame

    p_glBindBuffer(GL_PIXEL_UNPACK_BUFFER, gt.pbo[idx]);

    // Orphan old buffer data, get new storage
    GLsizeiptr bufSize = (GLsizeiptr)gt.height * stride;
    p_glBufferData(GL_PIXEL_UNPACK_BUFFER, bufSize, nullptr, GL_STREAM_DRAW);

    // Map and copy
    void* ptr = p_glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
    if (ptr) {
        const unsigned char* src = (const unsigned char*)data;
        unsigned char*       dst = (unsigned char*)ptr;
        if (stride == gt.width * 4) {
            memcpy(dst, src, bufSize);
        } else {
            for (int y = 0; y < gt.height; y++) {
                memcpy(dst, src, gt.width * 4);
                src += stride;
                dst += gt.width * 4;
            }
        }
        p_glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    }

    // Upload from PBO to GL texture (async DMA)
    glBindTexture(GL_TEXTURE_2D, gt.tex);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, gt.width, gt.height,
                    GL_BGRA_EXT, GL_UNSIGNED_BYTE, nullptr);
    glBindTexture(GL_TEXTURE_2D, 0);

    p_glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

bool GLTex_Resize(GLTextureUpload& gt, int width, int height) {
    if (!gt.active) return GLTex_Init(gt, width, height);

    // Delete old texture and PBOs
    glDeleteTextures(1, &gt.tex);
    p_glDeleteBuffers(2, gt.pbo);
    gt.tex = 0;
    gt.pbo[0] = gt.pbo[1] = 0;
    gt.active = false;

    return GLTex_Init(gt, width, height);
}

GLuint GLTex_GetTexture(const GLTextureUpload& gt) {
    return gt.tex;
}

void GLTex_Shutdown(GLTextureUpload& gt) {
    if (gt.tex) { glDeleteTextures(1, &gt.tex); gt.tex = 0; }
    if (gt.pbo[0] && pboFuncsLoaded) {
        p_glDeleteBuffers(2, gt.pbo);
        gt.pbo[0] = gt.pbo[1] = 0;
    }
    gt.active = false;
}