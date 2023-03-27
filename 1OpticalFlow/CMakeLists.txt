cmake_minimum_required(VERSION 3.5)

project(optical_flow)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV directory: " ${OpenCV_INCLUDE_DIRS})
add_executable(optical_flow main.cpp)

target_link_libraries(optical_flow ${OpenCV_LIBS})
