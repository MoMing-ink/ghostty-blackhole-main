// capture_wgc.h  Windows Graphics Capture (no DXGI Duplication)
// WGC captures monitor desktop into D3D11 textures.
// Cross-GPU: works on NVIDIA / AMD / Intel.
#pragma once
#include <d3d11.h>

struct WGCCapture {
    ID3D11Device*        d3dDev     = nullptr;
    ID3D11DeviceContext* d3dCtx     = nullptr;

    // WinRT capture objects (opaque IUnknown*)
    IUnknown*            framePool   = nullptr;
    IUnknown*            session     = nullptr;
    IUnknown*            captureItem = nullptr;

    // Staging texture for GPU-CPU readback
    ID3D11Texture2D*     stagingTex = nullptr;

    // 预创建的 fence query: 复用避免每帧 CreateQuery/Release 的 D3D11 内核调用开销
    // 减少 GPU 同步点的帧时长波动 (缓解轻微卡顿)
    ID3D11Query*         frameFence = nullptr;

    int width  = 0;
    int height = 0;
    bool active = false;
};

// Init: creates D3D11 device + WGC session for primary monitor
bool WGC_Init(WGCCapture& wgc);

// Get latest captured frame (caller must Release)
ID3D11Texture2D* WGC_GetFrame(WGCCapture& wgc);

// Copy frame to staging, then Map for CPU read
bool WGC_CopyToStaging(WGCCapture& wgc, ID3D11Texture2D* srcTex,
                       D3D11_MAPPED_SUBRESOURCE& mapped);

void WGC_UnmapStaging(WGCCapture& wgc);

void WGC_Release(WGCCapture& wgc);