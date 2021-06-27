cmake_minimum_required(VERSION 3.13)
project(EternalEngineSRC)
add_library(EternalEngineSRC OBJECT "Entity.cpp")
target_include_directories(EternalEngineSRC PRIVATE "include/")