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
    - Windows: `.\build\Debug\DefinEngine.exe`
    - Linux/macOS: `./build/DefinEngine`

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

### Versioning

This project follows [Semantic Versioning 2.0.0](https://semver.org/). We use [Conventional Commits](https://www.conventionalcommits.org/) to automatically drive version bumps and generate changelogs.

- **MAJOR** version for incompatible API changes.
- **MINOR** version for new functionality in a backwards compatible manner.
- **PATCH** version for backwards compatible bug fixes.

The version is automatically extracted from git tags during the CMake configuration process and is available in the code via `version.h`.

### Releases

Official releases can be found on the [GitHub Releases](https://github.com/user/DefinEngine/releases) page. Each release includes:
- Source code (zip and tar.gz)
- Platform-specific binaries (Windows ZIP, Linux TGZ, macOS DMG)
- Automatically generated release notes

### Contributing

We follow the [Conventional Commits](https://www.conventionalcommits.org/) specification for our commit messages. This allows us to automate the versioning and release process.

#### Commit Format

Each commit message consists of a **header**, a **body**, and a **footer**. The header has a special format that includes a **type**, a **scope**, and a **subject**:

```
<type>(<scope>): <subject>
<BLANK LINE>
<body>
<BLANK LINE>
<footer>
```

#### Commit Types

- **feat**: A new feature (corresponds to a `MINOR` version bump)
- **fix**: A bug fix (corresponds to a `PATCH` version bump)
- **docs**: Documentation only changes
- **style**: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
- **refactor**: A code change that neither fixes a bug nor adds a feature
- **perf**: A code change that improves performance
- **test**: Adding missing tests or correcting existing tests
- **build**: Changes that affect the build system or external dependencies
- **ci**: Changes to our CI configuration files and scripts
- **chore**: Other changes that don't modify src or test files
- **revert**: Reverts a previous commit

**BREAKING CHANGE**: A commit that has a footer `BREAKING CHANGE:`, or appends a `!` after the type/scope, introduces a breaking API change (corresponds to a `MAJOR` version bump).

#### Examples

- `feat(renderer): add support for shadow mapping`
- `fix(input): resolve memory leak in keyboard handler`
- `feat(physics)!: upgrade to new physics engine API`
- `docs: update build instructions in README`

#### Tools

We recommend using [Commitizen](https://github.com/commitizen/cz-cli) to help you write conventional commit messages.

### FAQ

**Q: How do I trigger a new release?**
A: Simply push a commit with `feat` or `fix` type to the `main` branch. Semantic-release will take care of the rest.

**Q: What if I don't want to trigger a release?**
A: Use `chore`, `docs`, `style`, `refactor`, `perf`, `test`, `build`, or `ci` types for your commits.

**Q: Where can I see the current version?**
A: The version is displayed during the CMake configuration step and is also available in `source/version.h` (generated during build).

### License

*TODO: Add license information.*
