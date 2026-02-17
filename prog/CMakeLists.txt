cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(prog VERSION 0.0.1)

add_executable(prog 
./main.cpp
)

set_target_properties(prog PROPERTIES CXX_STANDARD 17)
set_target_properties(prog PROPERTIES CXX_STANDARD_REQUIRED ON)
