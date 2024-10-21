/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>
#include <sstream>
#include <string>

// Манипулятор `endm` добавляет "[eol]\n" к потоку
inline std::ostream& endm(std::ostream& os) {
    os << "[eol]\n";
    return os;
}

// Манипулятор `squares` выводит значение в квадратных скобках
struct squares_t {};
inline squares_t squares;

// Перегрузка оператора для манипулятора squares
inline std::ostream& operator<<(std::ostream& os, const squares_t&) {
    // Не выводим ничего, просто возвращаем поток
    return os;
}

// Оператор для закрытия квадратных скобок
inline std::ostream& operator<<(std::ostream& os, const squares_t&) {
    os << "]"; // Если нужно, можно добавить логику для вывода, если это необходимо
    return os;
}

// Класс для обработки сложения значений
class add_t {
public:
    add_t() : sum_(0.0) {}

    // Перегрузка оператора для добавления значений
    template<typename T>
    add_t& operator<<(const T& value) {
        std::stringstream ss;
        ss << value;

        double number = 0.0;
        if (!(ss >> number)) {
            std::cerr << "Invalid argument: " << value << " cannot be converted to double." << std::endl;
            return *this; // Возвращаем текущее состояние без изменения суммы
        }

        sum_ += number; // Добавляем к сумме
        return *this;
    }

    // Перегрузка оператора вывода для отображения суммы
    friend std::ostream& operator<<(std::ostream& os, const add_t& add) {
        os << add.sum_;
        return os;
    }

private:
    double sum_;
};

inline add_t add;

#endif // __IOMANIP_HPP__
