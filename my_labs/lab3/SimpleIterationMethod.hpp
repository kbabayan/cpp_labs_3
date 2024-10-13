#ifndef SIMPLE_ITERATION_METHOD_HPP
#define SIMPLE_ITERATION_METHOD_HPP

#include <functional>

// Метод простых итераций
double SimpleIterationMethod(std::function<double(double)> phi, double initial_guess, double epsilon, int max_iterations);

#endif