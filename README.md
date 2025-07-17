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

F1-> CMake: Build Debug
