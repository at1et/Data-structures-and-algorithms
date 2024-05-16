// main.cpp
#include <iostream>
#include <cassert>
#include "moduleSample.h"

int main() {
    const size_t SIZE = 1000000; // Размер массива
    const int MIN_VAL = 1; // Минимальное значение элемента массива
    const int MAX_VAL = 100; // Максимальное значение элемента массива

    // Измерение времени создания случайного массива
    double timeRandomArray = measureTime([&]() {
        int* randArray = createRandomArray<int>(SIZE, MIN_VAL, MAX_VAL);
        printArrayToFile(randArray, SIZE, "random_array.txt");
        delete[] randArray;
        });

    std::cout << "Time to create and write random array: " << timeRandomArray << " milliseconds" << std::endl;

    // Измерение времени создания возрастающего массива
    double timeIncreasingArray = measureTime([&]() {
        int* incArray = createIncreasingArray<int>(SIZE, 1);
        printArrayToFile(incArray, SIZE, "increasing_array.txt");
        delete[] incArray;
        });

    std::cout << "Time to create and write increasing array: " << timeIncreasingArray << " milliseconds" << std::endl;

    // Создание массивов для последующих операций
    int* randArray = createRandomArray<int>(SIZE, MIN_VAL, MAX_VAL);
    int* incArray = createIncreasingArray<int>(SIZE, 1);

    // Проверка, отсортирован ли массив
    assert(!isArraySorted(randArray, SIZE)); // Проверка, не отсортирован ли массив randArray
    assert(isArraySorted(incArray, SIZE)); // Проверка, отсортирован ли массив incArray

    // Поиск значения в массиве
    size_t index = sequentialSearch(randArray, SIZE, 50); // Поиск значения 50 в массиве randArray
    if (index != SIZE) { // Если значение найдено
        std::cout << "Element found at index: " << index << std::endl; // Вывод индекса найденного элемента
    }
    else { // Если значение не найдено
        std::cout << "Element not found" << std::endl; // Вывод сообщения о том, что значение не найдено
    }

    // Освобождение памяти
    delete[] randArray;
    delete[] incArray;

    return 0;
}
