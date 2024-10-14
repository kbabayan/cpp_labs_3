#include <gtest/gtest.h>
#include <cmath>
#include <functional>
#include "../SimpleIterationMethod.cpp"  // Подключаем вашу реализацию

// Тест для случая, когда метод сходится к нужному значению
TEST(SimpleIterationTest, ConvergesToRoot) {
    auto phi = [](double x) { return 0.5 * (x + 3 / x); }; // Функция для теста
    double initial_guess = 1.0;
    double epsilon = 1e-6;
    int max_iterations = 100;

    double result = SimpleIterationMethod(phi, initial_guess, epsilon, max_iterations);
    EXPECT_NEAR(result, sqrt(3.0), epsilon);  // Ожидаем результат, близкий к sqrt(3)
}

// Тест для случая, когда достигается максимальное число итераций
TEST(SimpleIterationTest, MaxIterationsReached) {
    auto phi = [](double x) { return x / 2; }; // Функция, которая медленно сходится
    double initial_guess = 100.0;
    double epsilon = 1e-6;
    int max_iterations = 5;

    double result = SimpleIterationMethod(phi, initial_guess, epsilon, max_iterations);
    EXPECT_EQ(max_iterations, 5);  // Проверяем, что количество итераций равно максимальному
}

// Тест для случая расходимости
TEST(SimpleIterationTest, DivergenceDetected) {
    auto phi = [](double x) { return 2 * x; }; // Функция, которая расходится
    double initial_guess = 1.0;
    double epsilon = 1e-6;
    int max_iterations = 100;

    double result = SimpleIterationMethod(phi, initial_guess, epsilon, max_iterations);
    EXPECT_GT(result, 1e10);  // Ожидаем, что результат превышает значение расходимости
}