// main.cpp
// Author: Полуэктов Андрей
//
// Задание 1. Подготовительный код для работы с массивами, измерения времени; последовательный поиск.
// Ссылка на задание: https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2024/2024_part_1.md#%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-1-%D0%BF%D0%BE%D0%B4%D0%B3%D0%BE%D1%82%D0%BE%D0%B2%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9-%D0%BA%D0%BE%D0%B4-%D0%B4%D0%BB%D1%8F-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%8B-%D1%81-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0%D0%BC%D0%B8-%D0%B8%D0%B7%D0%BC%D0%B5%D1%80%D0%B5%D0%BD%D0%B8%D1%8F-%D0%B2%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%B8-%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9-%D0%BF%D0%BE%D0%B8%D1%81%D0%BA
//
// Данная программа демонстрирует работу с классическими массивами, включает функции генерации
// случайных и монотонно возрастающих массивов, последовательный поиск (с вариантами) и измерение времени работы.

#include <iostream>             // Подключаем стандартную библиотеку ввода/вывода
#include <cassert>              // Подключаем библиотеку для assert
#include <chrono>               // Подключаем библиотеку для работы с временем
#include <functional>           // Подключаем библиотеку для std::function (предикаты)
#include "array_UST.h"          // Подключаем наш заголовочный файл с функциями работы с массивами и классом Timer

using namespace std;            // Используем стандартное пространство имён

// Точка входа в программу
int main() {
    // Выводим сообщение о начале работы программы
    cout << "Starting Assignment 1: Array utilities and sequential search" << endl;

    // Запускаем автоматические тесты для проверки функции isSorted
    testIsSorted();

    // Определяем размер массива (10 миллионов элементов для надёжного измерения времени)
    size_t arraySize = 10000000;
    // Задаём минимальное и максимальное значения для генерации случайных чисел
    int randomMin = -1000000;
    int randomMax = 1000000;

    // Выводим сообщение о создании случайного массива
    cout << "Creating random array of size " << arraySize << "..." << endl;
    // Создаём динамический массив, заполненный случайными числами
    int* randomArray = createRandomArray(arraySize, randomMin, randomMax);

    // Выбираем значение для поиска: берём элемент из середины массива,
    // чтобы гарантированно оно присутствовало
    int searchValue = randomArray[arraySize / 2];
    {
        // Создаём объект Timer для измерения времени последовательного поиска
        // По завершении блока (при выходе из фигурных скобок) таймер автоматически выведет затраченное время
        Timer timer("Sequential search in unsorted array");
        // Выполняем последовательный поиск искомого значения в неотсортированном массиве
        size_t index = sequentialSearch(randomArray, arraySize, searchValue);
        // Если значение найдено, выводим его индекс, иначе выводим сообщение о неудаче
        if (index != arraySize) {
            cout << "Found value " << searchValue << " at index " << index << endl;
        }
        else {
            cout << "Value " << searchValue << " not found in unsorted array." << endl;
        }
    } // Здесь вызывается деструктор Timer и выводится время поиска

    // Создаём монотонно возрастающий массив
    cout << "Creating monotonically increasing array of size " << arraySize << "..." << endl;
    // Выделяем память для отсортированного массива
    int* sortedArray = new int[arraySize];
    // Заполняем массив возрастающими значениями:
    // первый элемент – случайное число из диапазона [0, 10],
    // каждый последующий элемент = предыдущий элемент + случайный шаг из диапазона [1, 10]
    fillArrayRandomIncreasing(sortedArray, arraySize, 0, 10, 1, 10);
    // Проверяем, что массив действительно отсортирован, используя assert
    assert(isSorted(sortedArray, arraySize) && "The array should be sorted!");

    // Измеряем время последовательного поиска в отсортированном массиве.
    // Выбираем значение для поиска из середины массива
    int sortedSearchValue = sortedArray[arraySize / 2];
    {
        // Создаём Timer для измерения времени поиска в отсортированном массиве
        Timer timer("Sequential search in sorted array");
        // Выполняем последовательный поиск искомого значения
        size_t index = sequentialSearch(sortedArray, arraySize, sortedSearchValue);
        // Выводим результат поиска
        if (index != arraySize) {
            cout << "Found value " << sortedSearchValue << " at index " << index << endl;
        }
        else {
            cout << "Value " << sortedSearchValue << " not found in sorted array." << endl;
        }
    } // По завершении блока Timer выводится время поиска

    // Записываем отсортированный массив в файл (опционально)
    string filename = "sorted_array.txt"; // Имя файла для записи
    writeArrayToFile(filename, sortedArray, arraySize);
    cout << "Sorted array written to file: " << filename << endl;

    // Освобождаем выделенную динамическую память для случайного и отсортированного массивов
    delete[] randomArray;
    delete[] sortedArray;

    return 0; 
}
