#include "about_window.h"
#include <imgui.h>

void ShowAboutWindow() {
    ImGui::Begin("About");
    ImGui::Text("ImGui Example\nAuthor: MinuteReversal");
    ImGui::End();
}
