cmake_minimum_required(VERSION 3.11)

project(SimpleIterationMethod)

set(CMAKE_CXX_STANDARD 11)

# FetchContent для Catch2
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.0.1
)

FetchContent_MakeAvailable(catch2)

# Создание статической библиотеки для метода простых итераций
add_library(SimpleIterationMethod STATIC SimpleIterationMethod.cpp)

# Убедимся, что тесты могут использовать библиотеку
target_include_directories(SimpleIterationMethod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Включаем поддержку CTest
include(CTest)

# Добавляем директорию с тестами
add_subdirectory(tests)
