#include <iostream>
#include <functional>
#include <cmath>
#include "SimpleIterationMethod.hpp"

#include <iostream>
#include <functional>
#include <cmath>

double SimpleIterationMethod(std::function<double(double)> phi, double initial_guess, double epsilon, int max_iterations)
{
    double x_current = initial_guess;
    double x_next = phi(x_current);
    int iterations = 0;

    std::cout << "Starting Simple Iteration Method..." << std::endl;
    std::cout << "Initial guess: " << initial_guess << std::endl;

    while (fabs(x_next - x_current) > epsilon && iterations < max_iterations) {
        x_current = x_next;
        x_next = phi(x_current);
        iterations++;

        std::cout << "Iteration " << iterations << ": x_current = " << x_current 
                  << ", x_next = " << x_next << std::endl;

        // Условие выхода на случай, если метод расходится
        if (fabs(x_next) > 1e10) { // Пример: если x_next становится слишком большим
            std::cout << "Divergence detected: x_next = " << x_next << std::endl;
            return x_next; // Завершить функцию и вернуть текущее значение
        }
    }

    if (iterations == max_iterations) {
        std::cout << "Max iterations reached. Last x_next = " << x_next << std::endl;
    } else {
        std::cout << "Converged to " << x_next << " after " << iterations << " iterations." << std::endl;
    }

    return x_next;
}
