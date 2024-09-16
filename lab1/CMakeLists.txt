# return() # Remove this line (строка означает, что файл не выполняется)
cmake_minimum_required(VERSION 3.29)
project(lab1)

add_library(introduction INTERFACE)
target_include_directories(introduction INTERFACE include)

# Добавляем Catch2 с помощью FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)


# Находим все тесты и создаём исполняемый файл
file(GLOB TESTS tests/*.cpp)
add_executable(tests_introduction ${TESTS})

# add_executable(tests introduction.cpp)

# Линкуем тесты с библиотекой и Catch2
target_link_libraries(tests_introduction introduction Catch2::Catch2WithMain)

# Подключаем Catch2 для тестов
include(CTest)
include(Catch)
catch_discover_tests(tests_introduction)
