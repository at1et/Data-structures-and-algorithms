// moduleSample.h
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <functional>
#include <chrono>

using namespace std::chrono;

// Шаблон функции для измерения времени выполнения
template <typename Func>
double measureTime(Func func) {
    auto t0 = steady_clock::now();
    func();
    auto t1 = steady_clock::now();
    auto delta = duration_cast<milliseconds>(t1 - t0);
    return delta.count();
}

// Шаблон функции создания массива заданного размера, заполненного случайными значениями в заданном интервале
template <typename T>
T* createRandomArray(size_t size, T min, T max) {
    T* arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}

// Шаблон функции создания массива с монотонно возрастающими значениями
template <typename T>
T* createIncreasingArray(size_t size, T start) {
    T* arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = start++;
    }
    return arr;
}

// Шаблон функции вывода массива в файл
template <typename T>
void printArrayToFile(const T* arr, size_t size, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            file << arr[i] << " ";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

// Шаблон функции проверки, отсортирован ли массив
template <typename T>
bool isArraySorted(const T* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Шаблон функции последовательного поиска значения в массиве
template <typename T>
size_t sequentialSearch(const T* arr, size_t size, const T& key) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return size; // если элемент не найден
}

// Бонус: шаблон функции последовательного поиска с произвольной функцией
template <typename T, typename F>
size_t sequentialSearchCustom(const T* arr, size_t size, F func) {
    for (size_t i = 0; i < size; ++i) {
        if (func(arr[i])) {
            return i;
        }
    }
    return size; // если элемент не найден
}
