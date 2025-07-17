# LearnImGui

## install vscode extensions

```shell
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension twxs.cmake
code --install-extension vadimcn.vscode-lldb
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
├── imgui/                # ImGui自定义控件/封装
│   ├── widgets.h
│   └── widgets.cpp
├── panels/               # 各功能面板
│   ├── main_menu.h
│   ├── main_menu.cpp
│   └── settings_panel.cpp
├── stores/               # 业务逻辑/数据
│   └── app_stores.h
├── platform/             # 平台/渲染相关
│   └── window_glfw.cpp
└── ...
```

ImGui推荐“即时模式+模块化+状态分离”的C++工程结构。

## hpp
.hpp 文件本质上就是 C++ 的头文件，和 .h 类似，但通常用于区分“C++头文件”与“C头文件”。

.h：可以用于C或C++头文件（历史上C用得多）。
.hpp：专门用于C++头文件，表示这里面是C++语法（如class、namespace、模板等）。
.hpp 不是 .h + .cpp 的意思，而是“header plus plus”，即“C++头文件”。

常见用法：

.hpp 里写声明（类、函数、模板等），.cpp 里写实现。
也有项目用 .h 作为C++头文件，这只是风格不同。
总结：.hpp 只是C++头文件的另一种命名方式，和 .h 功能一样，但更明确区分C和C++。