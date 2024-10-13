# Включаем поддержку CTest
include(CTest)

# Создаём исполняемый файл для тестов
add_executable(SimpleIterationMethodTest test_SimpleIterationMethod.cpp)

# Линкуем с библиотекой Catch2 и SimpleIterationMethod
target_link_libraries(SimpleIterationMethodTest PRIVATE Catch2::Catch2WithMain SimpleIterationMethod)

# Добавляем тест
add_test(NAME SimpleIterationMethodTest COMMAND SimpleIterationMethodTest)
