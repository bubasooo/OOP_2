cmake_minimum_required(VERSION 3.23)
project(hw24_25)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw24_25
        Node.cpp
        BinTree.cpp
        AVLTree.cpp
        TreeIterator.cpp
        IterableAVL.cpp
                )
