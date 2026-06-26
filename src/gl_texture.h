// gl_texture.h  Cross-vendor D3D11-to-OpenGL texture upload via PBO
// Replaces WGL_NV_DX_interop2 (NVIDIA-only) with portable PBO path.
// Works on NVIDIA / AMD / Intel.
#pragma once
#include <GL/gl.h>

struct GLTextureUpload {
    GLuint tex      = 0;    // OpenGL texture (GL_TEXTURE_2D)
    GLuint pbo[2]   = {0, 0}; // double-buffered PBOs
    int    pboIdx   = 0;    // current write PBO index
    int    width    = 0;
    int    height   = 0;
    bool   active   = false;
};

// Init: create GL texture + 2 PBOs
bool GLTex_Init(GLTextureUpload& gt, int width, int height);

// Upload RGBA8 data to GL texture (async via PBO)
void GLTex_Upload(GLTextureUpload& gt, const void* data, int stride);

// Reinitialize texture on resize
bool GLTex_Resize(GLTextureUpload& gt, int width, int height);

GLuint GLTex_GetTexture(const GLTextureUpload& gt);

void GLTex_Shutdown(GLTextureUpload& gt);