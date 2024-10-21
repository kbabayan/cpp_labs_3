/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>

// Манипулятор endm: добавляет новую строку и очищает поток
inline std::ostream& endm(std::ostream& os) {
    os.put('\n');  // Добавляем новую строку
    os.flush();    // Очищаем буфер вывода
    return os;
}

// Манипулятор squares: выводит квадрат числа
class squares_manip {
public:
    int value;
    squares_manip(int v) : value(v) {}
};

// Перегрузка оператора << для манипулятора squares
inline std::ostream& operator<<(std::ostream& os, const squares_manip& sq) {
    return os << sq.value * sq.value;  // Выводим квадрат числа
}

// Функция для использования манипулятора squares
inline squares_manip squares(int value) {
    return squares_manip(value);  // Возвращаем объект squares_manip
}

// Манипулятор add: складывает два числа
template <typename T>
class add_manip {
public:
    T a, b;
    add_manip(T _a, T _b) : a(_a), b(_b) {}
};

// Перегрузка оператора << для манипулятора add
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const add_manip<T>& add) {
    return os << (add.a + add.b);  // Выводим сумму двух чисел
}

// Функция для использования манипулятора add
template <typename T>
inline add_manip<T> add(T a, T b) {
    return add_manip<T>(a, b);  // Возвращаем объект add_manip
}

#endif // __IOMANIP_HPP__