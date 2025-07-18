#include "my_button.h"
#include <imgui.h>
#include <string>

bool MyButton(const std::string &label, ImVec2 size) {
  return ImGui::Button(label.c_str(), size);
}