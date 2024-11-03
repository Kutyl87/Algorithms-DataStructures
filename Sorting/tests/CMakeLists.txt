cmake_minimum_required(VERSION 3.16.0)
project(Characters_tests)
set(SOURCE_FILES sortingTests.cpp)
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0)
FetchContent_MakeAvailable(Catch2)
add_executable(exec ${SOURCE_FILES})
set_target_properties(exec
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_compile_options(exec PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(exec PUBLIC ../sortingAlgorithms)
target_link_directories(exec PUBLIC ../sortingAlgorithms/lib)
target_link_libraries(exec sortingAlgorithmsLib)
target_link_libraries(exec Catch2::Catch2WithMain)