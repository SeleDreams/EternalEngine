cmake_minimum_required(VERSION 3.13)
project(MyGame)

include_directories(libs/3rdparty/entt/single_include)
add_subdirectory(Engine/src)
add_executable(MyGame "Game/main.cpp")
target_include_directories(MyGame PRIVATE ${ETERNALENGINE_INCLUDE_DIR})
target_link_libraries(MyGame ${ETERNALENGINE_LIBRARIES})
