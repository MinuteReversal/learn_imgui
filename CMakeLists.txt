cmake_minimum_required(VERSION 3.10)

project(LearnImGui)
set(CMAKE_CXX_STANDARD 17)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(LearnImGui
    main.cpp
    panels/home_window.cpp
    panels/settings_window.cpp
    panels/about_window.cpp
    panels/demo_button_window.cpp
)
target_link_libraries(LearnImGui PRIVATE imgui::imgui glfw OpenGL::GL)