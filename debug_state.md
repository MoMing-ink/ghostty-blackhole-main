# Debug State 鈥?Blackhole v4: WGC + PBO 鏋舵瀯杩佺Щ

## 瀹炴柦缁撴灉

### 缂栬瘧 鉁?- 闆惰鍛婇浂閿欒閫氳繃
- 3 婧愭枃浠堕摼鎺? main.cpp + capture_wgc.cpp + gl_texture.cpp
- 渚濊禆搴? glfw + opengl32 + d3d11 + dxgi + gdi32 + runtimeobject

### 鏋舵瀯鍙樻洿

**鏃ф灦鏋?(v3) 鈥?宸插垹闄わ細**
```
DXGI Desktop Duplication (screen_capture)
    鈫?AcquireNextFrame / ReleaseFrame
    鈫?CopyResource 鈫?shared D3D11 texture
    鈫?WGL_NV_DX_interop2 (NVIDIA only) 鈫?OpenGL texture
    鈫?blackhole.glsl 鈫?绐楀彛
```
- `src/screen_capture.h` / `.cpp` 鈥?宸插垹闄?- `src/gl_interop.h` / `.cpp` 鈥?宸插垹闄?- SPIR-V 缂栬瘧璺緞 鈥?宸插垹闄わ紝鍙繚鐣?GLSL

**鏂版灦鏋?(v4) 鈥?璺?GPU锛?*
```
Windows Graphics Capture (capture_wgc)
    鈫?TryGetNextFrame 鈫?ID3D11Texture2D
    鈫?CopyResource 鈫?staging texture (D3D11_USAGE_STAGING)
    鈫?Map 鈫?memcpy 鈫?PBO 鈫?glTexSubImage2D
    鈫?OpenGL texture 鈫?blackhole.glsl 鈫?绐楀彛
```
- `src/capture_wgc.h` / `.cpp` 鈥?鏂板缓锛歐GC 鎹曡幏妯″潡
- `src/gl_texture.h` / `.cpp` 鈥?鏂板缓锛歅BO 寮傛涓婁紶妯″潡

### 鍏抽敭鏀硅繘

| 闂 (v3) | 瑙ｅ喅 (v4) |
|-----------|----------|
| WGL_NV_DX_interop2 浠?NVIDIA | PBO 涓婁紶锛岃法鎵€鏈?GPU锛圢VIDIA/AMD/Intel锛?|
| DXGI Duplication ACCESS_LOST | WGC 鏃犳闂 |
| 鏃?WS_EX_LAYERED | WS_EX_LAYERED + LWA_COLORKEY 鐪熼€忔槑鍙犲姞 |
| SPIR-V 缂栬瘧姘歌繙澶辫触 | 鍒犻櫎 SPIR-V 璺緞锛屼粎 GLSL |
| 鏃?resize 澶勭悊 | resize 妫€娴?+ 鑷姩閲嶅缓绾圭悊 |
| 鍙嶉寰幆椋庨櫓 | WDA_EXCLUDEFROMCAPTURE 淇濇姢 |

### 鏂板鍔熻兘

- **resize 妫€娴?*锛氭瘡甯ф鏌?WGC 甯у昂瀵革紝鍙樺寲鏃惰嚜鍔ㄩ噸寤?staging/绾圭悊/PBO
- **WS_EX_LAYERED**锛氱獥鍙ｄ娇鐢?LWA_COLORKEY 瀹炵幇鐪熼€忔槑鍙犲姞
- **double-buffered PBO**锛歡lBufferData orphan + 鍙岀紦鍐诧紝GPU DMA 涓?CPU 鍐欏叆骞惰

### 鎬ц兘鐗瑰緛
- 姣忓抚涓€娆?GPU CopyResource锛圵GC frame 鈫?staging锛寏0.1ms锛?- 姣忓抚涓€娆?CPU memcpy锛坰taging 鈫?PBO锛?MB @ 1080p锛寏1ms锛?- PBO 涓婁紶寮傛锛坓lTexSubImage2D 浣跨敤 DMA锛屼笉闃诲 CPU锛?- 鎬讳綋锛殈1-2ms per frame锛?0fps 涓?12% 鏃堕棿棰勭畻

### 寰呴獙璇?- 鈿狅笍 闇€瑕佸疄闄呰繍琛岄獙璇?WGC 姝ｅ父宸ヤ綔
- 鈿狅笍 闇€瑕侀獙璇?PBO 涓婁紶鍦ㄥ叏鍒嗚鲸鐜囦笅鎬ц兘
- 鈿狅笍 闇€瑕侀獙璇?WS_EX_LAYERED 閫忔槑鍙犲姞鏁堟灉
- 鈿狅笍 闇€瑕侀獙璇?resize 澶勭悊锛堝鎺ユ樉绀哄櫒鍦烘櫙锛?
## 淇敼鏂囦欢姹囨€?
| 鏂囦欢 | 鎿嶄綔 | 璇存槑 |
|------|------|------|
| `src/capture_wgc.h` | 鏂板缓 | WGC 鎹曡幏鎺ュ彛 |
| `src/capture_wgc.cpp` | 鏂板缓 | WGC + D3D11 staging 瀹炵幇 |
| `src/gl_texture.h` | 鏂板缓 | PBO 绾圭悊涓婁紶鎺ュ彛 |
| `src/gl_texture.cpp` | 鏂板缓 | Double-buffered PBO 瀹炵幇 |
| `src/main.cpp` | 閲嶅啓 | 闆嗘垚 WGC+PBO锛屽垹闄?DXGI/WGL/SPIR-V |
| `CMakeLists.txt` | 淇敼 | 鏂版簮鏂囦欢 + runtimeobject 搴?|
| `src/screen_capture.h` | 鍒犻櫎 | 鏃?DXGI 鎹曡幏 |
| `src/screen_capture.cpp` | 鍒犻櫎 | 鏃?DXGI 鎹曡幏 |
| `src/gl_interop.h` | 鍒犻櫎 | 鏃?WGL interop (NVIDIA only) |
| `src/gl_interop.cpp` | 鍒犻櫎 | 鏃?WGL interop (NVIDIA only) |

## 鏈慨鏀规枃浠?- `blackhole.glsl` 鈥?淇濈暀瀹屾暣鐗╃悊妯℃嫙
- `shaders/vert.glsl` 鈥?涓嶅彉
- `shaders/frag_desktop_header.glsl` 鈥?涓嶅彉
- `shaders/frag_simple.glsl` 鈥?涓嶅彉
- `shaders/frag_header.glsl` 鈥?涓嶅彉

## 淇敼鍑芥暟

| 鍑芥暟 | 鏂囦欢 | 鎿嶄綔 |
|------|------|------|
| `WGC_Init()` | capture_wgc.cpp | 鏂板 鈥?D3D11 + WGC 浼氳瘽鍒濆鍖?|
| `WGC_GetFrame()` | capture_wgc.cpp | 鏂板 鈥?TryGetNextFrame 鑾峰彇鎹曡幏甯?|
| `WGC_CopyToStaging()` | capture_wgc.cpp | 鏂板 鈥?CopyResource + Map 鍒?CPU |
| `WGC_UnmapStaging()` | capture_wgc.cpp | 鏂板 鈥?Unmap staging |
| `WGC_Release()` | capture_wgc.cpp | 鏂板 鈥?閲婃斁鎵€鏈?WGC/D3D11 璧勬簮 |
| `GLTex_Init()` | gl_texture.cpp | 鏂板 鈥?GL 绾圭悊 + 鍙?PBO 鍒濆鍖?|
| `GLTex_Upload()` | gl_texture.cpp | 鏂板 鈥?PBO orphan+map+copy+涓婁紶 |
| `GLTex_Resize()` | gl_texture.cpp | 鏂板 鈥?閲嶅缓绾圭悊/PBO锛坮esize 鍦烘櫙锛?|
| `GLTex_Shutdown()` | gl_texture.cpp | 鏂板 鈥?閲婃斁 GL 璧勬簮 |
| `main()` | main.cpp | 閲嶅啓 鈥?鏂扮绾块泦鎴?|

## 椋庨櫓楠岃瘉

| 椋庨櫓 | 鐘舵€?|
|------|------|
| WGC TryGetNextFrame 鍙敤鎬?| 鈿狅笍 闇€杩愯鏃堕獙璇?|
| CreateDirect3D11DeviceFromDXGIDevice dll 鍔犺浇 | 鈿狅笍 闇€杩愯鏃堕獙璇?|
| PBO 鍙岀紦鍐蹭笂浼犳€ц兘 | 鈿狅笍 闇€杩愯鏃堕獙璇?|
| WS_EX_LAYERED 閫忔槑鏁堟灉 | 鈿狅笍 闇€杩愯鏃堕獙璇?|
| resize 鑷姩閲嶅缓 | 鈿狅笍 闇€杩愯鏃堕獙璇?|
| 鍐呭瓨娉勬紡 | 鉁?姣忎釜 Release/Shutdown 閰嶅妫€鏌?|