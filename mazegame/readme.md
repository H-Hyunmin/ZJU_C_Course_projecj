# LibGraphics vscode makefile

## makefile配置

```
# exe文件名
APP     := main.exe

# 所有c源文件所在文件夹（可递归搜索4层），.表示当前文件夹
SRC     := .

# 编译得到的.o文件所在文件夹，不要和SRC一样
OBJ     := ./obj

# 编译得到的exe文件所在文件夹，不要和SRC一样
BIN     := ./bin

```

- 构建： `make build`
- 清除： `make clean`

## vscode配置

1. gcc环境配置

    下载mingw64，添加环境变量mingw64\bin，并把mingw64\bin\mingw32-make.exe复制一份到make.exe

2. .vscode/launch.json

    ```jsonc
    // Line11 Line31 修改exe文件路径
    "program": "${workspaceFolder}\\bin\\main.exe"
    ```

3. .vscode/c_cpp_properties.json

    ```jsonc
    // Line13 修改mingw路径
    "compilerPath": "C:/xxx/mingw64/bin/gcc.exe",
    ```

4. 
    - 调试： Run
    - 调试： Build & Run

    - 构建： 菜单 > Terminal > Run Task... > Build
    - 清除： 菜单 > Terminal > Run Task... > Clean
