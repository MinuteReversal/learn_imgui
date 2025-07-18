#include "my_custom_panel.h"
#include <functional>

void MyCustomPanel(const std::string& title, int value, std::function<void()> onClick) {
    ImGui::Begin(title.c_str());
    ImGui::Text("Value: %d", value);
    if (ImGui::Button("Do Something")) {
        if (onClick) onClick(); // 事件回调
    }
    ImGui::End();
}