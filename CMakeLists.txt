cmake_minimum_required(VERSION 4.3)
project(03SortAlgorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(03SortAlgorithms src/main.cpp
        inc/MergeSort.h
        inc/BaseSort.h
        inc/Bubble.h
        inc/Insertion.h
        inc/Selection.h
        inc/Quick.h
        inc/Heap.h)
