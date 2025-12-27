# Basic Game Engine

A basic C++ game engine project using OpenGL, GLFW, and GLEW.

### Overview

This project serves as a starting point for developing a game engine or graphics application. It sets up a basic window with an OpenGL context and renders a simple triangle.

### Requirements

- **C++ Compiler**: Supports C++17 (e.g., GCC 7+, Clang 5+, MSVC 2017+)
- **CMake**: Version 3.10 or higher
- **Graphics Drivers**: Support for OpenGL 3.3 Core Profile
- **Dependencies**: Included in the `thirdparty/` directory (GLFW 3.4, GLEW)

### Setup & Run

#### Using CMake

1.  **Generate build files**:
    ```powershell
    cmake -B build
    ```
2.  **Build the project**:
    ```powershell
    cmake --build build
    ```
3.  **Run the application**:
    - Windows: `.\build\Debug\GameDevelopmentProject.exe`
    - Linux/macOS: `./build/GameDevelopmentProject`

### Scripts

The following scripts are provided to simplify project generation for specific IDEs:

- `gen_proj_vs2022.bat`: Generates a Visual Studio 2022 solution in the `build/` directory.
- `gen_proj_xcode.sh`: Generates an Xcode project in the `build/` directory (macOS only).

### Project Structure

- `source/`: Contains the C++ source code.
    - `main.cpp`: Entry point of the application.
- `thirdparty/`: Contains third-party libraries.
    - `glfw-3.4/`: GLFW library for window management and input.
    - `glew/`: GLEW library for OpenGL extension loading.
- `CMakeLists.txt`: Main CMake configuration file.

### Environment Variables

*No specific environment variables are required at this time.*

### Tests

*TODO: Add testing framework and unit tests.*

### License

*TODO: Add license information.*
