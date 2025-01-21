cmake_minimum_required(VERSION 3.16)
project(TuringApp)
add_executable(TuringApp main.cpp)
add_subdirectory(
        ../src
        ${CMAKE_BINARY_DIR}/src
)

set_target_properties(TuringApp
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(TuringApp PRIVATE ../src )
target_compile_options(TuringApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(TuringApp PUBLIC TuringLib)