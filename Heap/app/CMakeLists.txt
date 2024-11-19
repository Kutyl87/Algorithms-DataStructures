cmake_minimum_required(VERSION 3.16)
project(HeapComparison)
add_executable(HeapComparison main.cpp)
add_subdirectory(
        ../src
        ${CMAKE_BINARY_DIR}/src
)
add_subdirectory(
        ../utils
        ${CMAKE_BINARY_DIR}/utils
)
set_target_properties(HeapComparison
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(HeapComparison PRIVATE ../src ../utils)
target_compile_options(HeapComparison PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(HeapComparison PUBLIC HeapLib algorithmsUtilslib)
