cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(prog VERSION 0.0.1)


find_package(OpenCV REQUIRED)


add_executable(prog 
./main.cpp
)


target_link_libraries(prog ${OpenCV_LIBS})

add_custom_command(
	TARGET prog POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	"${CMAKE_SOURCE_DIR}/image.png"
	"${CMAKE_BINARY_DIR}/image.png"
	COMMENT "Copying image to build directory..."
)

set_target_properties(prog PROPERTIES CXX_STANDARD 17)
set_target_properties(prog PROPERTIES CXX_STANDARD_REQUIRED ON)
