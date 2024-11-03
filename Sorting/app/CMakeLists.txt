cmake_minimum_required(VERSION 3.16)
project(SortingComparison)
add_executable(SortingComparison main.cpp)
add_subdirectory(
        ../sortingAlgorithms
        ${CMAKE_BINARY_DIR}/sortingAlgorithms
)
add_subdirectory(
        ../utils
        ${CMAKE_BINARY_DIR}/utils
)
set_target_properties(SortingComparison
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(SortingComparison PRIVATE ../sortingAlgorithms ../utils)
target_compile_options(SortingComparison PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(SortingComparison PUBLIC sortingAlgorithmsLib algorithmsUtilslib)