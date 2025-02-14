/*
  Author: Poluektov Andrey VMK - 22
  Задание 3. Бинарный поиск
  Ссылка на задание: https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2024/2024_part_1.md#%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-3-%D0%B1%D0%B8%D0%BD%D0%B0%D1%80%D0%BD%D1%8B%D0%B9-%D0%BF%D0%BE%D0%B8%D1%81%D0%BA
 
  Текст задания:
    - Реализуйте алгоритм бинарного поиска.
    - Напишите тесты.
    - Измерьте время работы алгоритмов. См. замечание об измерении времени в задании 1.
      Постройте графики времени работы алгоритма.
      Сравните его с алгоритмом последовательного поиска. Если разница в масштабах времени существенная,
      постройте график последовательного поиска на отдельном полотне.
    - Укажите оценку BigO для разных классов входных данных (худший, средний, лучший случаи) и для памяти.
      Проверьте, соответствуют ли графики времени работы алгоритмов одному из указанных классов? Какому? Почему?
 */

#include <iostream>
#include <chrono>
#include <cassert>
#include "search_module.h"

using namespace std;
using namespace chrono;


int main() {
    setlocale(LC_ALL,"rus");

    // Запуск автоматических тестов для проверки бинарного поиска
    testBinarySearch();

    // Параметры для эксперимента:
    // - Размер массива для измерения времени (например, 10 миллионов элементов)
    const size_t arraySize = 10000000;

    // Создаем отсортированный массив, заполненный монотонно возрастающими значениями
    // Для генерации используем функцию fillArrayRandomIncreasing (из задания 1)
    int* sortedArray = new int[arraySize];
    fillArrayRandomIncreasing(sortedArray, arraySize, 0, 10, 1, 10);

    // Проверяем, что массив отсортирован
    assert(isSorted(sortedArray, arraySize));

    // Выбираем значение для поиска (например, элемент из середины массива)
    int target = sortedArray[arraySize / 2];

    // Измеряем время работы последовательного поиска
    auto start = steady_clock::now();
    size_t seqIndex = sequentialSearch(sortedArray, arraySize, target);
    auto end = steady_clock::now();
    auto seqTime = duration_cast<milliseconds>(end - start).count();
    cout << "Sequential Search: найден индекс " << seqIndex << " за " << seqTime << " ms" << endl;

    // Измеряем время работы бинарного поиска
    start = steady_clock::now();
    size_t binIndex = binarySearch(sortedArray, arraySize, target);
    end = steady_clock::now();
    auto binTime = duration_cast<milliseconds>(end - start).count();
    cout << "Binary Search: найден индекс " << binIndex << " за " << binTime << " ms" << endl;

    // Вывод оценок сложности (BigO)
    cout << "\nОценки сложности:" << endl;
    cout << "Последовательный поиск: лучший случай O(1), средний и худший O(n)" << endl;
    cout << "Бинарный поиск: O(log n) для всех случаев при условии отсортированного массива" << endl;
    cout << "Память: O(n) для хранения массива" << endl;

    // Освобождаем выделенную память
    delete[] sortedArray;

    return 0;
}
