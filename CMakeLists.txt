cmake_minimum_required(VERSION 4.3)
project(03SortAlgorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(03SortAlgorithms main.cpp
        MergeSort.h
        BaseSort.h
        Bubble.h
        Insertion.h
        Selection.h
        Quick.h
        Heap.h)
