#include "settings_window.h"
#include <imgui.h>

void ShowSettingsWindow() {
    ImGui::Begin("Settings");
    ImGui::Text("Settings page content.");
    static bool option = false;
    ImGui::Checkbox("Enable Option", &option);
    ImGui::End();
}
