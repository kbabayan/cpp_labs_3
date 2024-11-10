# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(lab4)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем директорию для заголовочных файлов
include_directories(include)

# Добавляем тесты
add_executable(tests_iomanip tests/iomanip.cpp)

# Подключаем директорию include для тестов
target_include_directories(tests_iomanip PRIVATE include)

# Подключаем Catch2, если он установлен локально или глобально
# find_package(Catch2 REQUIRED) # раскомментируйте, если используете глобально установленный Catch2

# Включаем тесты, если используете CTest
enable_testing()
add_test(NAME IOMANIP_TEST COMMAND tests_iomanip)
