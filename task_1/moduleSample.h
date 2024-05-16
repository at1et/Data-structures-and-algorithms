// moduleSample.h
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <chrono>

// Подключаем пространство имен std::chrono для удобства работы с временными типами
using namespace std::chrono;

// Шаблон функции для измерения времени выполнения
template <typename Func>
double measureTime(Func func) {
    // Начальная отметка времени
    auto t0 = steady_clock::now();
    // Выполнение переданной функции
    func();
    // Конечная отметка времени
    auto t1 = steady_clock::now();
    // Преобразование времени (обычно наносекунды) в миллисекунды
    auto delta = duration_cast<milliseconds>(t1 - t0);
    // Возвращаем длительность выполнения в миллисекундах
    return delta.count();
}

// Шаблон функции создания массива заданного размера, заполненного случайными значениями в заданном интервале
template <typename T>
T* createRandomArray(size_t size, T min, T max) {
    // Создание массива размером size
    T* arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        // Заполнение массива случайными значениями в интервале [min, max]
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}

// Шаблон функции создания массива с монотонно возрастающими значениями
template <typename T>
T* createIncreasingArray(size_t size, T start) {
    // Создание массива размером size
    T* arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        // Заполнение массива возрастающими значениями, начиная с start
        arr[i] = start++;
    }
    return arr;
}

// Шаблон функции вывода массива в файл
template <typename T>
void printArrayToFile(const T* arr, size_t size, const std::string& filename) {
    std::ofstream file(filename); // Открытие файла для записи
    if (file.is_open()) { // Проверка, удалось ли открыть файл
        for (size_t i = 0; i < size; ++i) {
            file << arr[i] << " "; // Запись элементов массива в файл
        }
        file.close(); // Закрытие файла
    }
    else {
        std::cerr << "Unable to open file" << std::endl; // Сообщение об ошибке, если файл не удалось открыть
    }
}

// Шаблон функции проверки, отсортирован ли массив
template <typename T>
bool isArraySorted(const T* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) { // Проверка условия возрастания элементов
            return false; // Массив не отсортирован
        }
    }
    return true; // Массив отсортирован
}

// Шаблон функции последовательного поиска значения в массиве
template <typename T>
size_t sequentialSearch(const T* arr, size_t size, const T& key) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == key) { // Если элемент найден
            return i; // Возвращаем индекс элемента
        }
    }
    return size; // Если элемент не найден, возвращаем размер массива
}

// Бонус: шаблон функции последовательного поиска с произвольной функцией
template <typename T, typename F>
size_t sequentialSearchCustom(const T* arr, size_t size, F func) {
    for (size_t i = 0; i < size; ++i) {
        if (func(arr[i])) { // Если условие функции выполнено
            return i; // Возвращаем индекс элемента
        }
    }
    return size; // Если элемент не найден, возвращаем размер массива
}
