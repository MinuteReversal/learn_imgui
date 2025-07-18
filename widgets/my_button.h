// widgets.h
#pragma once
#include <imgui.h>
#include <string>

// 返回 true 表示被点击
bool MyButton(const std::string &label, ImVec2 size = ImVec2(0, 0));