// gui_config.h — ImGui config panel for blackhole parameters
#pragma once

struct BlackholeConfig {
    int  mode      = 0;    // 0=always, 1=idle
    int  idleSec   = 300;  // idle timeout in seconds
    bool confirmed = false;
};

// Show config panel. Returns true when user clicks Start.
bool GUI_ShowConfigPanel(BlackholeConfig& cfg);