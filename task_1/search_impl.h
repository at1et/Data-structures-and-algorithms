// Реализация шаблонных функций последовательного поиска.

#ifndef SEARCH_IMPL_H
#define SEARCH_IMPL_H

#include <cstddef>
#include <functional>
using namespace std;

template <typename T>
size_t sequentialSearch(const T* array, size_t size, const T& value) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value)
            return i;
    }
    return size; // значение не найдено
}

template <typename T>
size_t sequentialSearch(const T* array, size_t size, const function<bool(const T&)>& predicate) {
    for (size_t i = 0; i < size; ++i) {
        if (predicate(array[i]))
            return i;
    }
    return size; // подходящий элемент не найден
}

#endif // SEARCH_IMPL_H
