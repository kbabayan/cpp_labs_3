cmake_minimum_required(VERSION 3.10)
project(SimpleIteration)

# Добавляем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Добавляем Catch2
FetchContent_Declare(
  catch2
  URL https://github.com/catchorg/Catch2/archive/v2.13.7.zip
)
FetchContent_MakeAvailable(catch2)

# Указываем исходники для основной библиотеки
add_library(SimpleIterationMethod SimpleIterationMethod.cpp SimpleIterationMethod.hpp)

# Линкуем тесты Google Test
add_executable(SimpleIterationTests tests/test_SimpleIterationMethod.cpp)
target_link_libraries(SimpleIterationTests SimpleIterationMethod gtest gtest_main)
add_test(NAME SimpleIterationTests COMMAND SimpleIterationTests)

# Линкуем тесты Catch2
add_executable(Catch2Tests tests/test_catch2.cpp)
target_link_libraries(Catch2Tests SimpleIterationMethod Catch2::Catch2)
add_test(NAME Catch2Tests COMMAND Catch2Tests)
