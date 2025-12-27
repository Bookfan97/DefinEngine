cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project (GameDevelopmentProject)

set(PROJECT_SOURCE_FILES
        source/main.cpp
)
# Find system OpenGL
find_package(OpenGL REQUIRED)

# Determine application type
if(APPLE)
    set(APP_TYPE MACOSX_BUNDLE)
elseif(WIN32)
    set(APP_TYPE WIN32)
    add_definitions(-DGLEW_STATIC)
endif()

# Add the application
include_directories(source)
add_executable(${PROJECT_NAME} ${APP_TYPE} ${PROJECT_SOURCE_FILES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            MACOSX_BUNDLE_BUNDLE_NAME "GameDevelopmentProject"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.user.GameDevelopmentProject"
            MACOSX_BUNDLE_BUNDLE_VERSION "0.0.1"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "0.0.1"
    )
endif()

# Add GLFW library
add_subdirectory(thirdparty/glfw-3.4 "${CMAKE_CURRENT_BINARY_DIR}/glfw_build")
include_directories(thirdparty/glfw-3.4/include)

# Add Glew library
add_compile_definitions(GLEW_NO_GLU)
set(BUILD_UTILS OFF CACHE BOOL "utilities" FORCE)
add_subdirectory(thirdparty/glew/build/cmake "${CMAKE_CURRENT_BINARY_DIR}/glew_build")
include_directories(thirdparty/glew/include)
set_property(TARGET glew_s PROPERTY FOLDER GLEW)
set_property(TARGET glew PROPERTY FOLDER GLEW)

# Link all thirdparty libraries
target_link_libraries(${PROJECT_NAME}
        glfw
        glew_s
        OpenGL::GL
)