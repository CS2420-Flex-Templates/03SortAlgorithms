# Set minimum CMAKE
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
project( 03SortAlgorithms )

# require C++23
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE 03SortAlgorithms )

set( LIB_NAME classLibrary )

# Add the class .cpp and .h files
add_library( ${LIB_NAME} INTERFACE )


target_sources(${LIB_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/BaseSort.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/Selection.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/Quick.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/Bubble.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/Insertion.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/Heap.h
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/MergeSort.h
)


target_include_directories( ${LIB_NAME} INTERFACE inc )

ADD_EXECUTABLE( ${APP_EXECUTABLE} src/main.cpp )
TARGET_LINK_LIBRARIES( ${APP_EXECUTABLE} ${LIB_NAME} )

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_constructors ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_push ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_pop ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_clear ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_deep_copies ${APP_EXECUTABLE} 5)
add_test(${APP_EXECUTABLE}_other ${APP_EXECUTABLE} 6)

find_program(VALGRIND "valgrind")
if(VALGRIND)
    add_custom_target(valgrind
            COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()







