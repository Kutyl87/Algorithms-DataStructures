cmake_minimum_required(VERSION 3.16)
project(HeapComparison)
add_executable(HeapComparison main.cpp)
add_subdirectory(
        ../heap
        ${CMAKE_BINARY_DIR}/heap
)
set_target_properties(HeapComparison
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(HeapComparison PRIVATE ../heap)
target_compile_options(HeapComparison PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(HeapComparison PUBLIC HeapLib)
