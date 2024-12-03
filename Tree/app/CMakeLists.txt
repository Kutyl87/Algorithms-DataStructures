cmake_minimum_required(VERSION 3.16)
project(TreeComparison)
add_executable(TreeComparison main.cpp)
add_subdirectory(
        ../src
        ${CMAKE_BINARY_DIR}/src
)
add_subdirectory(
        ../utils
        ${CMAKE_BINARY_DIR}/utils
)
set_target_properties(TreeComparison
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(TreeComparison PRIVATE ../src ../utils)
target_compile_options(TreeComparison PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(TreeComparison PUBLIC TreeLib algorithmsUtilslib)
