#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <cmath>
#include "../SimpleIterationMethod.cpp"

// Пример функции φ(x) = cos(x)
double phi(double x) {
    return cos(x);
}

TEST_CASE("Test Simple Iteration Method - Close to Root", "[SimpleIterationMethod]") {
    double root = SimpleIterationMethod(phi, 0.5, 1e-6, 1000);  // Начальное приближение
    std::cout << "Computed root: " << root << std::endl;
    std::cout << "Cosine of computed root: " << cos(root) << std::endl;
    REQUIRE(fabs(root - cos(root)) < 1e-3);  // Проверяем, что φ(root) ≈ root
}

TEST_CASE("Test Simple Iteration Method - Convergence", "[SimpleIterationMethod]") {
    double root = SimpleIterationMethod([](double x) { return x / 2; }, 1.0, 1e-6, 1000);
    REQUIRE(fabs(root - 0.0) < 1e-3);  // Мы ожидаем, что x будет сходиться к 0
}

// Проверка на отсутствие сходимости для функции, у которой нет корня
TEST_CASE("Test Simple Iteration Method - No Convergence", "[SimpleIterationMethod]") {
    double root = SimpleIterationMethod(phi, 10.0, 1e-6, 100);  // Плохое начальное приближение
    // Ожидаем, что корень не найден, здесь мы просто проверяем, что метод не сошелся
    REQUIRE(fabs(root - cos(root)) >= 1e-7);  // Ожидаем, что φ(x) ≠ x
}