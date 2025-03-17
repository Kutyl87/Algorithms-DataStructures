cmake_minimum_required(VERSION 3.16.0)
project(Turing)
set(HEADER_FILES Turing.h)
set(SOURCE_FILES Turing.cpp)
add_library(TuringLib STATIC ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(TuringLib PROPERTIES LINKER_LANGUAGE CXX)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set_target_properties(TuringLib
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_compile_options(TuringLib PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(TuringLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})