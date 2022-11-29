cmake_minimum_required(VERSION 3.23)
project(hw24_25)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw24_25
            NodeKV.cpp
            BinTreeKV.cpp
            AVLTreeKV.cpp
            TreeIteratorKV.cpp
            IterableAVLKV.cpp
            BITree.cpp
            NodeDupl.cpp
            BITreeDuplicates.cpp
            Nation.cpp
            main.cpp

                )
