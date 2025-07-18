#include "custom_panel_test_window.h"
#include <imgui.h>
#include "../widgets/my_custom_panel.h"
#include <string>

void ShowCustomPanelTestWindow() {
    static int value = 42;
    static bool show_popup = false;
    MyCustomPanel("Custom Panel Demo", value, [&](){ show_popup = true; });
    if (show_popup) {
        ImGui::OpenPopup("ClickedPopup");
        show_popup = false;
    }
    if (ImGui::BeginPopup("ClickedPopup")) {
        ImGui::Text("Button was clicked!");
        if (ImGui::Button("Close")) ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
}
