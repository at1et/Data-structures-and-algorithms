// Объявление шаблонных функций для последовательного поиска в массиве.

#ifndef SEARCH_H
#define SEARCH_H

#include <cstddef>
#include <functional>
using namespace std;

// Шаблонная функция последовательного поиска значения в массиве.
// Если значение найдено, возвращается его индекс; иначе возвращается size.
template <typename T>
size_t sequentialSearch(const T* array, size_t size, const T& value);

// Шаблонная функция последовательного поиска элемента по предикату.
// Если найден первый элемент, для которого предикат возвращает true, возвращается его индекс; иначе – size.
template <typename T>
size_t sequentialSearch(const T* array, size_t size, const function<bool(const T&)>& predicate);

// Подключаем файл с реализациями шаблонных функций.
#include "search_impl.h"

#endif // SEARCH_H
