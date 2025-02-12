// Author: Полуэктов Андрей
//
// Задание 1. Подготовительный код для работы с массивами, измерения времени; последовательный поиск.
// Ссылка на задание: https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2024/2024_part_1.md
//
// Данная программа демонстрирует работу с классическими массивами, включает функции генерации
// случайных и монотонно возрастающих массивов, последовательный поиск (с вариантами) и измерение времени работы.

#include <iostream>
#include <cassert>
#include <chrono>
#include <functional>
#include "array_utils.h"
#include "search.h"
#include "timer.h"
using namespace std;

int main() {
    cout << "Starting Assignment 1: Array utilities and sequential search" << endl;

    // Запуск автоматических тестов для функции проверки сортировки.
    testIsSorted();

    // Параметры для создания массива
    size_t arraySize = 10000000;  // 10 миллионов элементов – для надежных измерений времени
    int randomMin = -1000000;
    int randomMax = 1000000;

    cout << "Creating random array of size " << arraySize << "..." << endl;
    int* randomArray = createRandomArray(arraySize, randomMin, randomMax);

    // Измеряем время последовательного поиска в неотсортированном массиве
    int searchValue = randomArray[arraySize / 2];  // выбираем значение, которое гарантированно присутствует
    {
        Timer timer("Sequential search in unsorted array");
        size_t index = sequentialSearch(randomArray, arraySize, searchValue);
        if (index != arraySize) {
            cout << "Found value " << searchValue << " at index " << index << endl;
        }
        else {
            cout << "Value " << searchValue << " not found in unsorted array." << endl;
        }
    }

    // Создаем монотонно возрастающий массив
    cout << "Creating monotonically increasing array of size " << arraySize << "..." << endl;
    int* sortedArray = new int[arraySize];
    // Параметры: первый элемент – случайное число в диапазоне [0, 10], шаг – случайное число в диапазоне [1, 10]
    fillArrayRandomIncreasing(sortedArray, arraySize, 0, 10, 1, 10);
    // Проверка, что массив отсортирован
    assert(isSorted(sortedArray, arraySize) && "The array should be sorted!");

    // Измеряем время последовательного поиска в отсортированном массиве
    int sortedSearchValue = sortedArray[arraySize / 2];  // выбираем значение, которое точно присутствует
    {
        Timer timer("Sequential search in sorted array");
        size_t index = sequentialSearch(sortedArray, arraySize, sortedSearchValue);
        if (index != arraySize) {
            cout << "Found value " << sortedSearchValue << " at index " << index << endl;
        }
        else {
            cout << "Value " << sortedSearchValue << " not found in sorted array." << endl;
        }
    }

    // Бонус: последовательный поиск с использованием произвольного предиката.
    // Ищем первый элемент, который больше заданного порога.
    int threshold = sortedArray[arraySize / 2];
    {
        Timer timer("Sequential search with predicate (first element > threshold)");
        function<bool(const int&)> pred = [threshold](const int& x) { return x > threshold; };
        size_t index = sequentialSearch(sortedArray, arraySize, pred);
        if (index != arraySize) {
            cout << "Found first element greater than " << threshold
                << " at index " << index << " with value " << sortedArray[index] << endl;
        }
        else {
            cout << "No element greater than " << threshold << " found." << endl;
        }
    }

    // Записываем отсортированный массив в файл (опционально)
    string filename = "sorted_array.txt";
    writeArrayToFile(filename, sortedArray, arraySize);
    cout << "Sorted array written to file: " << filename << endl;

    // Освобождаем выделенную динамическую память
    delete[] randomArray;
    delete[] sortedArray;

    cout << "Program completed." << endl;
    return 0;
}
