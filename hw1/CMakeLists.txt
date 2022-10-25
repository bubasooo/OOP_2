cmake_minimum_required(VERSION 3.23)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw1
        Complex.cpp
        main.cpp
        Human.cpp
        hw1.cpp)
