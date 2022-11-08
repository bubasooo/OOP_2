cmake_minimum_required(VERSION 3.23)
project(hw21_22)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw21_22
        task21.cpp
        task22.cpp
        tests.cpp
                )
