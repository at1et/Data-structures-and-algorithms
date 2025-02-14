#pragma once
#include "search_module.h"  // Подключение заголовочного файла с объявлениями функций
#include <random>           // Для генерации случайных чисел
#include <ctime>            // Для работы с временем (используется в seed генератора)
#include <fstream>          // Для работы с файлами (запись массива в файл)
#include <cassert>          // Для написания тестов (assert)
#include <iostream>         // Для вывода в консоль (отладка и тестирование)
using namespace std;

/*
  Функция getRandomGenerator:
  Использует статический объект генератора случайных чисел, чтобы избежать его переинициализации.
 */
mt19937& getRandomGenerator() {
    static random_device rd;
    static mt19937 gen(rd());  // Генератор Mersenne Twister с seed от random_device
    return gen;
}

/*
  Функция createRandomArray:
  Генерирует массив случайных чисел заданного размера и диапазона.
 */
int* createRandomArray(size_t size, int minVal, int maxVal) {
    int* array = new int[size];  // Выделяем динамическую память под массив
    uniform_int_distribution<int> distr(minVal, maxVal);  // Задаем равномерное распределение
    auto& gen = getRandomGenerator();  // Получаем генератор случайных чисел

    for (size_t i = 0; i < size; ++i) {
        array[i] = distr(gen);  // Заполняем массив случайными числами
    }
    return array;
}

/*
  Функция fillArrayRandomIncreasing:
  Заполняет массив возрастающей последовательностью с случайными шагами.
 */
void fillArrayRandomIncreasing(int* array, size_t size, int startMin, int startMax, int stepMin, int stepMax) {
    if (size == 0) return;

    auto& gen = getRandomGenerator();  // Получаем генератор случайных чисел
    uniform_int_distribution<int> startDistr(startMin, startMax);  // Диапазон первого элемента
    uniform_int_distribution<int> stepDistr(stepMin, stepMax);     // Диапазон шага

    array[0] = startDistr(gen);  // Устанавливаем первый элемент массива

    for (size_t i = 1; i < size; ++i) {
        array[i] = array[i - 1] + stepDistr(gen);  // Генерируем последующие элементы
    }
}


/*
  Функция isSorted:
  Проверяет, отсортирован ли массив (по неубыванию).
 */
bool isSorted(const int* array, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] > array[i])
            return false;  // Если есть нарушение порядка, возвращаем false
    }
    return true;  // Если дошли до конца без нарушений, массив отсортирован
}

/*
  Функция binarySearch:
  Выполняет бинарный поиск элемента в отсортированном массиве.
 */
size_t binarySearch(const int* array, size_t size, int target) {
    size_t left = 0, right = size;

    while (left < right) {
        size_t mid = left + (right - left) / 2;  // Вычисляем средний индекс

        if (array[mid] == target)
            return mid;  // Элемент найден

        if (array[mid] < target)
            left = mid + 1;  // Ищем в правой половине
        else
            right = mid;  // Ищем в левой половине
    }

    return size;  // Элемент не найден
}

/*
  Функция testBinarySearch:
  Запускает тесты для бинарного поиска, проверяя его корректность.
 */
void testBinarySearch() {
    int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    assert(binarySearch(arr1, 10, 5) == 5);

    int arr2[] = { 1, 3, 5, 7, 9 };
    assert(binarySearch(arr2, 5, 4) == 5);

    int arr3[] = { 42 };
    assert(binarySearch(arr3, 1, 42) == 0);

    int arr4[] = { 42 };
    assert(binarySearch(arr4, 1, 10) == 1);

    cout << "Все тесты бинарного поиска пройдены." << endl;
}
