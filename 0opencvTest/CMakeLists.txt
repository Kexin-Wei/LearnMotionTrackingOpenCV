cmake_minimum_required(VERSION 3.1)

# Project name
project(opencv_example)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Create the executable
add_executable(opencv_example main.cpp)

# Link OpenCV libraries
target_link_libraries(opencv_example ${OpenCV_LIBS})
