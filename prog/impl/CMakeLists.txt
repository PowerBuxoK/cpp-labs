cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library(tasks 
./task1.cpp
./task2.cpp
./task3.cpp
./task4.cpp
./task5.cpp
./task6.cpp
./task7.cpp
./task8.cpp
)


target_include_directories(tasks PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(tasks PROPERTIES CXX_STANDARD 17)
set_target_properties(tasks PROPERTIES CXX_STANDARD_REQUIRED ON)
