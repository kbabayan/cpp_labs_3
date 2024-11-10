cmake_minimum_required(VERSION 3.10)
project(lab4_part2)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.7.1
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
add_executable(tests_proxy tests/proxy.cpp)
target_include_directories(tests_proxy PRIVATE include)

target_link_libraries(tests_proxy PRIVATE Catch2::Catch2WithMain)
# find_package(Catch2 REQUIRED)

enable_testing()
add_test(NAME PROXY_TEST COMMAND tests_proxy)
