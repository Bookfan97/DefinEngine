cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GitVersion)
get_version_from_git()

project (GameDevelopmentProject VERSION ${CMAKE_PROJECT_VERSION})

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/source/version.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

set(PROJECT_SOURCE_FILES
        source/main.cpp
        source/game.cpp
        source/game.h
        source/TestObject.cpp
        source/TestObject.h
        engine/source/Engine.cpp
        engine/source/Engine.h
        engine/source/Application.cpp
        engine/source/Application.h
        engine/source/eng.h
        engine/source/input/InputManager.cpp
        engine/source/input/InputManager.h
        engine/source/graphics/ShaderProgram.cpp
        engine/source/graphics/ShaderProgram.h
        engine/source/graphics/GraphicsAPI.cpp
        engine/source/graphics/GraphicsAPI.h
        engine/source/graphics/VertexLayout.h
        engine/source/render/Mesh.cpp
        engine/source/render/Mesh.h
        engine/source/render/Material.cpp
        engine/source/render/Material.h
        engine/source/render/RenderQueue.cpp
        engine/source/render/RenderQueue.h
        engine/source/scene/GameObject.cpp
        engine/source/scene/GameObject.h
        engine/source/scene/Scene.cpp
        engine/source/scene/Scene.h
)
# Find system OpenGL
if(NOT APPLE)
    set(OpenGL_GL_PREFERENCE GLVND)
endif()
find_package(OpenGL REQUIRED)

# Determine application type
if(APPLE)
    set(APP_TYPE MACOSX_BUNDLE)
elseif(WIN32)
    # We use a console application by default on Windows to avoid unresolved WinMain.
    # If a GUI-only app is desired, use WIN32 here and change main() to WinMain() or use linker flags.
    set(APP_TYPE ""
            engine/source/scene/GameObject.cpp
            engine/source/scene/GameObject.h
            engine/source/scene/Scene.cpp
            engine/source/scene/Scene.h
            source/TestObject.cpp
            source/TestObject.h)
endif()

# Add the application
add_executable(${PROJECT_NAME} ${APP_TYPE} ${PROJECT_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE source engine/source "${CMAKE_CURRENT_BINARY_DIR}")

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            MACOSX_BUNDLE_BUNDLE_NAME "GameDevelopmentProject"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.user.GameDevelopmentProject"
            MACOSX_BUNDLE_BUNDLE_VERSION "${CMAKE_PROJECT_VERSION}"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "${CMAKE_PROJECT_VERSION}"
    )
endif()

# Add GLFW library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(engine/thirdparty/glfw-3.4 "${CMAKE_CURRENT_BINARY_DIR}/glfw_build")
target_include_directories(${PROJECT_NAME} PRIVATE engine/thirdparty/glfw-3.4/include)

# Add Glew library
add_compile_definitions(GLEW_NO_GLU)
set(BUILD_UTILS OFF CACHE BOOL "utilities" FORCE)
add_subdirectory(engine/thirdparty/glew/build/cmake "${CMAKE_CURRENT_BINARY_DIR}/glew_build")
target_include_directories(${PROJECT_NAME} PRIVATE engine/thirdparty/glew/include)
set_property(TARGET glew_s PROPERTY FOLDER GLEW)
set_property(TARGET glew PROPERTY FOLDER GLEW)

# Link all thirdparty libraries
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE GLEW_STATIC)
endif()

if(UNIX AND NOT APPLE)
    set(EXTRA_LIBS ${CMAKE_DL_LIBS} pthread)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        glew_s
        OpenGL::GL
        ${EXTRA_LIBS}
)

# Installation and CPack
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "User")
set(CPACK_PACKAGE_VERSION_MAJOR "${CMAKE_PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CMAKE_PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${CMAKE_PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A basic C++ game engine project")

if(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif(WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

include(CPack)