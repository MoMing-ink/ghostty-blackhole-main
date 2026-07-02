// gui_config.cpp  Preset definitions + config file I/O
// ImGui config panel has been replaced by Qt QML UI (Blakhole_UI/)
// This file now only provides data structures and file persistence
#include "gui_config.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

static void SetAutoStart(bool enable) {
    HKEY hKey;
    const char* keyPath = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    if (RegOpenKeyExA(HKEY_CURRENT_USER, keyPath, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (enable) {
            // 开机自启由 QML UI (BlackHole.exe) 通过 QSettings 写入 "BlackHole" 项管理
            // 渲染器进程 (blackhole_render.exe) 不直接处理自启, 此函数仅作历史兼容保留
            RegSetValueExA(hKey, "BlackholeScreensaver", 0, REG_SZ, (const BYTE*)exePath, strlen(exePath) + 1);
        } else {
            RegDeleteValueA(hKey, "BlackholeScreensaver");
        }
        RegCloseKey(hKey);
    }
}

static const DiskPreset DEFAULT_PRESETS[16] = {
    // 原始8个
    {5500, 1.50f, 0.35f, 1.8f, 8.0f, 0.90f, 0.60f, 2.5f, 2.2f, 1.6f, 7.0f, 5.0f, 1.40f, 0.0f},   // Inferno
    {4500, 1.52f, 0.10f, 2.2f, 7.0f, 0.85f, 0.35f, 2.0f, 1.4f, 0.5f, 7.0f, 5.0f, 1.20f, 0.0f},   // Gargantua
    {3800, 0.55f,-0.30f, 2.2f, 6.0f, 0.45f, 0.90f, 3.5f, 1.6f, 0.4f, 3.0f, 2.5f, 1.10f, 0.0f},   // M87* Donut
    {6500, 0.30f, 0.00f, 3.0f,10.0f, 0.50f, 0.80f, 2.5f, 1.0f, 1.1f, 7.0f, 5.0f, 1.00f, 0.0f},   // Face-on Ember
    {15000,1.30f, 0.35f, 3.0f,14.0f, 0.35f, 1.00f, 4.0f, 1.2f, 1.3f, 8.0f, 5.0f, 0.80f, 0.0f},   // Quasar
    {18000,1.05f, 0.55f, 3.0f,16.0f, 0.30f, 1.00f, 5.0f, 1.0f, 1.5f, 9.0f, 6.0f, 0.75f, 0.0f},   // Blazar
    {5500, 1.50f, 0.35f, 1.8f, 8.0f, 0.00f, 1.00f, 2.5f, 0.0f, 1.6f, 7.0f, 5.0f, 1.00f, 0.6f},   // Pure Lens
    {5500, 1.50f, 0.35f, 1.8f, 8.0f, 0.90f, 0.60f, 2.5f, 2.2f, 1.6f, 7.0f, 5.0f, 1.40f, 0.0f},   // Inferno 2
    // 新增8个
    {3200, 1.45f, 0.60f, 2.0f, 9.0f, 0.95f, 0.20f, 1.5f, 3.0f, 2.0f, 5.0f, 4.0f, 1.60f, 0.0f},   // Crimson Vortex
    {8000, 1.20f,-0.50f, 2.5f, 7.0f, 0.70f, 0.75f, 2.8f, 1.8f, 1.4f, 8.0f, 5.5f, 1.30f, 0.0f},   // Azure Spiral
    {2500, 1.55f, 0.20f, 1.6f, 6.0f, 0.60f, 0.10f, 1.2f, 2.6f, 1.8f, 4.0f, 3.0f, 1.50f, 0.0f},   // Ruby Ring
    {12000,0.80f, 0.45f, 2.8f,12.0f, 0.40f, 0.95f, 3.5f, 1.5f, 1.2f, 8.5f, 5.0f, 0.90f, 0.0f},   // Ghost Halo
    {5000, 0.10f, 0.00f, 2.0f, 9.0f, 0.85f, 0.50f, 2.0f, 1.3f, 1.5f, 6.0f, 4.5f, 1.10f, 0.0f},   // Top-down Galaxy
    {22000,1.40f, 0.70f, 3.5f,18.0f, 0.25f, 1.00f, 4.5f, 0.9f, 1.7f,10.0f, 6.5f, 0.70f, 0.0f},   // White Dwarf Beam
    {4200, 1.48f, 0.15f, 1.9f, 7.5f, 0.80f, 0.45f, 2.2f, 2.0f, 0.8f, 6.5f, 4.8f, 1.25f, 0.0f},   // Solar Forge
    {9000, 0.45f,-0.15f, 2.6f,11.0f, 0.55f, 0.85f, 3.0f, 1.1f, 1.3f, 7.5f, 5.2f, 1.05f, 0.0f},   // Obsidian Eye
};

void InitDefaultPresets(BlackholeConfig& cfg) {
    cfg.presetCount = 16;
    for (int i = 0; i < 16; i++) cfg.presets[i] = DEFAULT_PRESETS[i];
}

// ---- Save/Load presets to local file ----
void SavePresetsToFile(const BlackholeConfig& cfg, const char names[64][64]) {
    // 更新注册表开机自启设置
    SetAutoStart(cfg.autoStart);

    FILE* f = fopen("blackhole_presets.txt", "w");
    if (!f) return;
    fprintf(f, "# Blackhole Presets v4\n");
    fprintf(f, "%d %d %.3f %d %d %d\n", cfg.mode, cfg.idleSec, cfg.slotSec, cfg.playMode, (int)cfg.videoAsIdle, (int)cfg.autoStart);
    fprintf(f, "%d\n", cfg.presetCount);
    for (int i = 0; i < cfg.presetCount; i++) {
        const DiskPreset& p = cfg.presets[i];
        fprintf(f, "%s\n", names[i]);
        fprintf(f, "%.0f %.2f %.2f %.1f %.1f %.2f %.2f %.1f %.2f %.2f %.1f %.1f %.2f %.3f\n",
            p.temp, p.incl, p.roll, p.inner, p.outer,
            p.opac, p.dopp, p.beam, p.gain, p.contr,
            p.wind, p.speed, p.expo, p.star);
    }
    fclose(f);
}

bool LoadPresetsFromFile(BlackholeConfig& cfg, char names[64][64]) {
    FILE* f = fopen("blackhole_presets.txt", "r");
    if (!f) return false;
    char line[256];
    if (!fgets(line, sizeof(line), f)) { fclose(f); return false; } // skip comment
    // 检查版本号：低于 v4 则用新默认预设
    if (!strstr(line, "v4")) {
        fclose(f);
        InitDefaultPresets(cfg);
        return false;
    }
    if (!fgets(line, sizeof(line), f)) { fclose(f); return false; }
    // Try v3 format (mode idleSec slotSec playMode videoAsIdle autoStart)
    int mode=1, idle=300, pmode=1, vidAsIdle=0, autoSt=0; float ss=5.25f;
    int nf = sscanf(line, "%d %d %f %d %d %d", &mode, &idle, &ss, &pmode, &vidAsIdle, &autoSt);
    if (nf >= 3) {
        cfg.mode = mode; cfg.idleSec = idle; cfg.slotSec = ss; cfg.playMode = pmode;
        cfg.videoAsIdle = (nf >= 5) ? (bool)vidAsIdle : false;
        cfg.autoStart = (nf >= 6) ? (bool)autoSt : false;
        if (!fgets(line, sizeof(line), f)) { fclose(f); return false; }
    } else {
        cfg.mode = 1; cfg.idleSec = 300; cfg.slotSec = 5.25f; cfg.playMode = 1;
        cfg.videoAsIdle = false; cfg.autoStart = false;
    }
    int count = atoi(line);
    if (count < 1 || count > 64) { fclose(f); return false; }
    for (int i = 0; i < count; i++) {
        if (!fgets(line, sizeof(line), f)) break;
        line[strcspn(line, "\r\n")] = 0;
        strncpy(names[i], line, 63);
        names[i][63] = 0;
        if (!fgets(line, sizeof(line), f)) break;
        DiskPreset& p = cfg.presets[i];
        sscanf(line, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f",
            &p.temp, &p.incl, &p.roll, &p.inner, &p.outer,
            &p.opac, &p.dopp, &p.beam, &p.gain, &p.contr,
            &p.wind, &p.speed, &p.expo, &p.star);
    }
    cfg.presetCount = count;
    fclose(f);
    return true;
}
