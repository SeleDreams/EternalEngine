cmake_minimum_required(VERSION 3.13)
project(EternalEngineSRC)
set(SRC
"Scene.cpp"
"Game.cpp"
"SystemManager.cpp"
)
if(WIN32 OR UNIX)
    set(USE_GL3 1)
    set(USE_GLEW 1)
    set(USE_GLFW 1)
    add_compile_definitions(USE_GL3 USE_GLEW USE_GLFW)
endif()

if (USE_GL3)
    set(SRC ${SRC} GL3/MeshRenderer.cpp GL3/Viewport.cpp)
endif()

if (USE_GLFW)
    set(SRC ${SRC} Platforms/WindowGLFW.cpp)
endif()
add_library(EternalEngineSRC OBJECT ${SRC})

target_compile_features(EternalEngineSRC PRIVATE cxx_std_17)
target_include_directories(EternalEngineSRC PRIVATE "include/")