cmake_minimum_required(VERSION 3.20)
project(lab2)

# Добавляем путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/cpp/hpp)

# Создаем динамическую и статическую библиотеки
add_library(LibArithmMeanDynamic SHARED cpp/src/arithmetic_mean.cpp)
add_library(LibArithmMeanStatic STATIC cpp/src/arithmetic_mean.cpp)

# Создаем исполняемый файл и связываем его с библиотеками
add_executable(lab2_main cpp/src/main.cpp)
target_link_libraries(lab2_main LibArithmMeanStatic LibArithmMeanDynamic)

# Установка библиотек и заголовочных файлов
install(TARGETS LibArithmMeanDynamic LibArithmMeanStatic lab2_main
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES cpp/hpp/arithmetic_mean.hpp DESTINATION include)