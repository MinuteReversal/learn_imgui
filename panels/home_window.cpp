#include "home_window.h"
#include <imgui.h>

void ShowHomeWindow() {
    ImGui::Begin("Home");
    ImGui::Text("Welcome to the Home page!");
    ImGui::End();
}
