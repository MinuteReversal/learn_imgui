#include "demo_button_window.h"
#include <imgui.h>

void ShowDemoButtonWindow() {
    ImGui::Begin("DemoButton");
    if (ImGui::Button("Click Me!")) {
        ImGui::OpenPopup("Clicked");
    }
    if (ImGui::BeginPopup("Clicked")) {
        ImGui::Text("Button was clicked!");
        if (ImGui::Button("Close")) ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();
}
