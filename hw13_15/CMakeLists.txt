cmake_minimum_required(VERSION 3.23)
project(hw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw2
        DListQueueIterator.cpp
        OrderD.cpp
        DListQueue.cpp
        hw2.cpp
        main.cpp DListQueueHuman.cpp Human.cpp)
