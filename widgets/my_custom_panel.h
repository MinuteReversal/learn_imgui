#pragma once
#include <imgui.h>
#include <functional>
#include <string>

void MyCustomPanel(const std::string& title, int value, std::function<void()> onClick);