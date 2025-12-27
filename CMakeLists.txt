cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
)
# Find system OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Determine application type
if(APPLE)
    set(APP_TYPE MACOSX_BUNDLE)
elseif(WIN32)
    # We use a console application by default on Windows to avoid unresolved WinMain.
    # If a GUI-only app is desired, use WIN32 here and change main() to WinMain() or use linker flags.
    set(APP_TYPE "")
endif()

# Add the application
add_executable(${PROJECT_NAME} ${APP_TYPE} ${PROJECT_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE source "${CMAKE_CURRENT_BINARY_DIR}")

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            MACOSX_BUNDLE_BUNDLE_NAME "GameDevelopmentProject"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.user.GameDevelopmentProject"
            MACOSX_BUNDLE_BUNDLE_VERSION "${CMAKE_PROJECT_VERSION}"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "${CMAKE_PROJECT_VERSION}"
    )
endif()

# Add GLFW library
add_subdirectory(thirdparty/glfw-3.4 "${CMAKE_CURRENT_BINARY_DIR}/glfw_build")
target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/glfw-3.4/include)

# Add Glew library
add_compile_definitions(GLEW_NO_GLU)
set(BUILD_UTILS OFF CACHE BOOL "utilities" FORCE)
add_subdirectory(thirdparty/glew/build/cmake "${CMAKE_CURRENT_BINARY_DIR}/glew_build")
target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/glew/include)
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