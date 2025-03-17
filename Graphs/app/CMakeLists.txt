cmake_minimum_required(VERSION 3.16)
project(grafy)
add_executable(grafy main.cpp)
add_subdirectory(
        ../heap
        ${CMAKE_BINARY_DIR}/heap
)
set_target_properties(grafy
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(grafy PRIVATE ../heap)
if(!MSVC)
        target_compile_options(grafy PRIVATE -Wall -Wextra -pedantic -Werror -g)
endif()
target_link_libraries(grafy PUBLIC HeapLib)
