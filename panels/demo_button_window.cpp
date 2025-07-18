
#include "demo_button_window.h"
#include <imgui.h>
#include <string>
#include "../widgets/my_button.h"

void ShowDemoButtonWindow() {
    ImGui::Begin("DemoButton");
    if (MyButton("Click Me!")) {
        ImGui::OpenPopup("Clicked");
    }
    if (ImGui::BeginPopup("Clicked")) {
        ImGui::Text("Button was clicked!");
        if (MyButton("Close")) ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();
}
