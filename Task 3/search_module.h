#pragma once
#ifndef SEARCH_MODULE_H
#define SEARCH_MODULE_H

#include <cstddef>  // Для определения типа size_t
#include <string>   // Для работы со строками 
using namespace std;

/*
  Функция createRandomArray:
  Создает массив случайных чисел заданного размера.
 
  Параметры:
  - size: количество элементов в массиве.
  - minVal, maxVal: диапазон случайных значений (включительно).
 
  Возвращает:
  - Указатель на выделенный динамически массив случайных чисел.
 */
int* createRandomArray(size_t size, int minVal, int maxVal);

/*
  Функция fillArrayRandomIncreasing:
  Заполняет массив возрастающими значениями с случайными шагами.
 
  Параметры:
  - array: указатель на массив.
  - size: размер массива.
  - startMin, startMax: диапазон первого элемента.
  - stepMin, stepMax: диапазон шага между элементами.
 */
void fillArrayRandomIncreasing(int* array, size_t size, int startMin, int startMax, int stepMin, int stepMax);

/*
  Функция writeArrayToFile:
  Записывает массив в файл.
 
  Параметры:
  - filename: имя выходного файла.
  - array: указатель на массив.
  - size: размер массива.
 */
void writeArrayToFile(const string& filename, const int* array, size_t size);

/*
  Функция isSorted:
  Проверяет, отсортирован ли массив (по неубыванию).
 
  Параметры:
  - array: указатель на массив.
  - size: размер массива.
 
  Возвращает:
  - true, если массив отсортирован, иначе false.
 */
bool isSorted(const int* array, size_t size);

/*
  Шаблонная функция sequentialSearch:
  Последовательный поиск заданного элемента в массиве.
 
  Параметры:
  - array: указатель на массив.
  - size: размер массива.
  - value: значение для поиска.
 
  Возвращает:
  - Индекс найденного элемента или size, если элемент не найден.
 */
template <typename T>
size_t sequentialSearch(const T* array, size_t size, const T& value) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value)
            return i;  // Если найден, возвращаем индекс
    }
    return size;  // Если не найден, возвращаем размер массива
}

/*
  Функция binarySearch:
  Реализует бинарный поиск в отсортированном массиве.
 
  Параметры:
  - array: указатель на отсортированный массив.
  - size: размер массива.
  - target: искомое значение.
 
  Возвращает:
  - Индекс найденного элемента или size, если элемент отсутствует.
 */
size_t binarySearch(const int* array, size_t size, int target);

/*
  Функция testBinarySearch:
  Запускает тесты для бинарного поиска, проверяя его корректность.
 */
void testBinarySearch();

#endif // SEARCH_MODULE_H
