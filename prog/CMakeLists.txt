cmake_minimum_required(VERSION 3.0.0...3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lab8)

add_executable(prog
./main.cpp
./hash.cpp
./task1.cpp
)

set_target_properties(prog PROPERTIES CXX_STANDARD 17)
set_target_properties(prog PROPERTIES CXX_STANDARD_REQUIRED ON)
