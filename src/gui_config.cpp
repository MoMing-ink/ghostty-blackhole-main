// gui_config.cpp — ImGui config panel
#include "gui_config.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <cstdio>

bool GUI_ShowConfigPanel(BlackholeConfig& cfg) {
    // ---- Create a small config window ----
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* win = glfwCreateWindow(520, 420, "Black Hole Config", nullptr, nullptr);
    if (!win) return true; // fallback: start immediately
    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);

    // Setup ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = nullptr; // no ini file
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(win, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool done = false;
    while (!glfwWindowShouldClose(win) && !done) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ---- Config Panel ----
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(520, 420));
        ImGui::Begin("Black Hole Settings", nullptr,
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

        ImGui::TextColored(ImVec4(0.4f, 0.7f, 1.0f, 1.0f), "Black Hole Desktop Overlay");
        ImGui::Separator();
        ImGui::Spacing();

        // Mode selection
        ImGui::Text("Mode:");
        ImGui::SameLine();
        const char* modes[] = { "Always On", "Idle Detection" };
        ImGui::Combo("##mode", &cfg.mode, modes, 2);

        // Idle timeout (only for idle mode)
        if (cfg.mode == 1) {
            ImGui::Spacing();
            ImGui::Text("Idle timeout: %d seconds (%d min)", cfg.idleSec, cfg.idleSec / 60);
            ImGui::SliderInt("##timeout", &cfg.idleSec, 10, 1800);
        }

        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        // Start button
        ImGui::SetCursorPosX(200);
        if (ImGui::Button("START", ImVec2(120, 40))) {
            cfg.confirmed = true;
            done = true;
        }

        ImGui::Spacing();
        ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "ESC to exit | Press START to launch");

        ImGui::End();
        ImGui::Render();

        glClearColor(0.1f, 0.1f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(win);

        if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            break;
    }

    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(win);

    return cfg.confirmed;
}