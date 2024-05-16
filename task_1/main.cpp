// main.cpp
#include <iostream>
#include <cassert>
#include "moduleSample.h"

int main() {
    const size_t SIZE = 1000000; // Размер массива
    const int MIN_VAL = 1; // Минимальное значение элемента массива
    const int MAX_VAL = 100; // Максимальное значение элемента массива

    // Измерение времени создания случайного массива и записи его в файл
    double timeRandomArray = measureTime([&]() {
        int* randArray = createRandomArray<int>(SIZE, MIN_VAL, MAX_VAL); // Создание случайного массива
        printArrayToFile(randArray, SIZE, "random_array.txt"); // Запись массива в файл
        delete[] randArray; // Освобождение памяти
        });

    std::cout << "Time to create and write random array: " << timeRandomArray << " milliseconds" << std::endl;

    // Измерение времени создания возрастающего массива и записи его в файл
    double timeIncreasingArray = measureTime([&]() {
        int* incArray = createIncreasingArray<int>(SIZE, 1); // Создание массива с монотонно возрастающими значениями
        printArrayToFile(incArray, SIZE, "increasing_array.txt"); // Запись массива в файл
        delete[] incArray; // Освобождение памяти
        });

    std::cout << "Time to create and write increasing array: " << timeIncreasingArray << " milliseconds" << std::endl;

    // Создание массивов для последующих операций
    int* randArray = createRandomArray<int>(SIZE, MIN_VAL, MAX_VAL); // Создание случайного массива
    int* incArray = createIncreasingArray<int>(SIZE, 1); // Создание возрастающего массива

    // Проверка, отсортирован ли массив
    assert(!isArraySorted(randArray, SIZE)); // Проверка, не отсортирован ли случайный массив (должен быть не отсортирован)
    assert(isArraySorted(incArray, SIZE)); // Проверка, отсортирован ли возрастающий массив (должен быть отсортирован)

    // Поиск значения в массиве
    size_t index = sequentialSearch(randArray, SIZE, 50); // Поиск значения 50 в случайном массиве
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
