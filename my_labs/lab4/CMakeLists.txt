cmake_minimum_required(VERSION 3.10)
project(my_labs)

set(CMAKE_CXX_STANDARD 17)

# Добавляем Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    URL https://github.com/catchorg/Catch2/archive/v2.13.8.zip  # Укажите нужную версию
)
FetchContent_MakeAvailable(Catch2)

add_library(iomanip INTERFACE)
target_include_directories(iomanip INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iomanip ${TESTS})

target_link_libraries(tests_iomanip iomanip Catch2::Catch2)

enable_testing()
add_test(NAME tests_iomanip COMMAND tests_iomanip)
