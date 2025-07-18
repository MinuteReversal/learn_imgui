# LearnImGui

## install vscode extensions

```shell
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension twxs.cmake
code --install-extension vadimcn.vscode-lldb
```

## install vcpkg

```shell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
```

## install dependencies

```shell
./vcpkg install imgui glfw3 cpr
```

```shell
rm -rf build/*
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/Users/zhuang/Documents/github/vcpkg/scripts/buildsystems/vcpkg.cmake
```

## 编译

```shell
cmake --build . --config Debug
```

<kbd>F1</kbd> -> <kbd>F7</kbd> CMake: Build

```txt
project_root/
├── main.cpp
├── CMakeLists.txt
├── widgets/                # ImGui自定义控件/封装
│   ├── widgets.h
│   └── widgets.cpp
├── pages/               # 各功能面板
│   ├── main_menu.h
│   ├── main_menu.cpp
│   └── settings_panel.cpp
├── stores/               # 业务逻辑/数据
│   └── app_stores.h
├── platform/             # 平台/渲染相关
│   └── window_glfw.cpp
└── ...
```

ImGui 推荐“即时模式+模块化+状态分离”的 C++工程结构。

## hpp

.hpp 文件本质上就是 C++ 的头文件，和 .h 类似，但通常用于区分“C++头文件”与“C 头文件”。

.h：可以用于 C 或 C++头文件（历史上 C 用得多）。
.hpp：专门用于 C++头文件，表示这里面是 C++语法（如 class、namespace、模板等）。
.hpp 不是 .h + .cpp 的意思，而是“header plus plus”，即“C++头文件”。

常见用法：

.hpp 里写声明（类、函数、模板等），.cpp 里写实现。
也有项目用 .h 作为 C++头文件，这只是风格不同。
总结：.hpp 只是 C++头文件的另一种命名方式，和 .h 功能一样，但更明确区分 C 和 C++。

## C++ 命名规范表：

| 类型          | 推荐命名风格            | 示例                            |
| ------------- | ----------------------- | ------------------------------- |
| 全局常量      | 全大写+下划线           | const int MAX_LENGTH = 100;     |
| 局部常量      | 小写+下划线/驼峰        | const int max_length = 100;     |
| 变量          | 小写+下划线/驼峰        | int user_count; float speed;    |
| 方法/函数     | 小写+下划线/驼峰        | void update(); int getValue();  |
| 类/结构体     | 大驼峰（首字母大写）    | class UserManager; struct Vec3; |
| 枚举类型      | 大驼峰                  | enum class ColorType {};        |
| 枚举成员      | 全大写+下划线           | RED, GREEN, BLUE                |
| 静态/全局变量 | g\_前缀+小写下划线      | static int g_max_count;         |
| 文件          | 全小写+下划线/.hpp/.cpp | user_manager.hpp, main.cpp      |
| 文件夹        | 全小写+下划线           | widgets/, pages/, stores/       |

说明：

- 常量（const/constexpr/宏）用全大写+下划线，如 MAX_SIZE、DEFAULT_PORT。
- 其它类型命名规则同前表。

## 连接cpp文件
```cmake
add_executable(LearnImGui
    main.cpp
    widgets/my_button.cpp
    widgets/my_custom_panel.cpp
    panels/home_window.cpp
    panels/settings_window.cpp
    panels/about_window.cpp
    panels/demo_button_window.cpp
    panels/custom_panel_test_window.cpp
)
target_link_libraries(LearnImGui PRIVATE imgui::imgui glfw OpenGL::GL)