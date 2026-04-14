find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(task3
./main.cpp
)

target_link_libraries(task3 ${OpenCV_LIBS})
target_link_libraries(task3 ${OpenSSL_LIBRARIES})

set_target_properties(task3 PROPERTIES CXX_STANDARD 17)
set_target_properties(task3 PROPERTIES CXX_STANDARD_REQUIRED ON)

target_link_libraries(task3 OpenSSL::SSL OpenSSL::Crypto)
