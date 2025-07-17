#include <imgui.h>

#include "panels/home_window.h"
#include "panels/settings_window.h"
#include "panels/about_window.h"
#include "panels/demo_button_window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

int main(int, char **) {
  // 初始化GLFW
  if (!glfwInit())
    return 1;

  // 设置OpenGL版本
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // 创建窗口
  GLFWwindow *window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
  if (window == NULL)
    return 1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // 启用垂直同步

  // 初始化ImGui上下文
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();

  // 初始化ImGui平台/渲染器绑定
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  // 页面枚举
  enum class Page { Home, Settings, About, DemoButton };
  Page currentPage = Page::Home;

  // 主循环
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // 顶部导航栏
    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("Pages")) {
        if (ImGui::MenuItem("Home", NULL, currentPage == Page::Home))
          currentPage = Page::Home;
        if (ImGui::MenuItem("Settings", NULL, currentPage == Page::Settings))
          currentPage = Page::Settings;
        if (ImGui::MenuItem("About", NULL, currentPage == Page::About))
          currentPage = Page::About;
        if (ImGui::MenuItem("DemoButton", NULL,
                            currentPage == Page::DemoButton))
          currentPage = Page::DemoButton;
        ImGui::EndMenu();
      }
      ImGui::EndMainMenuBar();
    }

    // 页面内容分离
    switch (currentPage) {
    case Page::Home:
      ShowHomeWindow();
      break;
    case Page::Settings:
      ShowSettingsWindow();
      break;
    case Page::About:
      ShowAboutWindow();
      break;
    case Page::DemoButton:
      ShowDemoButtonWindow();
      break;
    }

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // 清理
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
