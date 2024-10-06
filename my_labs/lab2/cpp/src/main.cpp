#include <iostream>
#include "arithmetic_mean.hpp"

int main() {
    double a = 5.0;
    double b = 10.0;

    std::cout << "Arithmetic mean (static): " << arif_mean(a, b) << std::endl;
    std::cout << "Arithmetic mean (dynamic): " << arif_mean(a, b) << std::endl;

    return 0;
}