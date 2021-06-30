cmake_minimum_required(VERSION 3.13)
project(EternalEngine)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(SRC
"Game.cpp"
"SceneManagement/Scene.cpp"
"Systems/SystemManager.cpp"
"Systems/RenderSystem.cpp"
"Components/ComponentFactory.cpp"
)

if(WIN32 OR UNIX)
    set(USE_GL3 1)
    set(USE_GLEW 1)
    set(USE_GLFW 1)
endif()

if (USE_GL3)
    find_package(OpenGL REQUIRED)
    set(SRC ${SRC} GL3/MeshRenderer.cpp GL3/Viewport.cpp)
    add_compile_definitions(USE_GL3)
endif()

if(USE_GLEW)
    find_package(GLEW REQUIRED)
    add_compile_definitions(USE_GLEW)
    if (NOT GLEW_LIBRARIES)
        find_library(GLEW_LIBRARIES glew32)
    endif()
endif()

if (USE_GLFW)
    find_package(glfw3 REQUIRED)
    set(SRC ${SRC} Platforms/WindowGLFW.cpp)
    add_compile_definitions(USE_GLFW)
    find_library(GLFW_LIBRARY glfw)
    if (NOT GLFW_LIBRARY)
        find_library(GLFW_LIBRARY glfw3)
    endif()
endif()

add_library(EternalEngine SHARED ${SRC})

set(ETERNALENGINE_INCLUDE_DIR
${CMAKE_CURRENT_SOURCE_DIR}/include
${OPENGL_INCLUDE_DIR} 
${GLFW3_INCLUDE_DIR} 
${GLEW_INCLUDE_DIR}
)

set(ETERNALENGINE_LIBRARIES
"EternalEngine" "${OPENGL_LIBRARIES}"  "${GLEW_LIBRARIES}"  "${GLFW_LIBRARY}"
)

target_compile_features(EternalEngine PUBLIC cxx_std_17)

target_include_directories(EternalEngine PRIVATE ${ETERNALENGINE_INCLUDE_DIR} )

target_link_libraries(${ETERNALENGINE_LIBRARIES})

set(ETERNALENGINE_LIBRARIES ${ETERNALENGINE_LIBRARIES} PARENT_SCOPE)
set(ETERNALENGINE_INCLUDE_DIR ${ETERNALENGINE_INCLUDE_DIR} PARENT_SCOPE)