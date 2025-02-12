// Реализация функций для работы с массивами.

#include "array_utils.h"
#include <random>
#include <ctime>
#include <fstream>
#include <cassert>
#include <iostream>
using namespace std;

// Функция для доступа к глобальному генератору случайных чисел.
// Использование статических переменных гарантирует, что генератор инициализируется только один раз.
mt19937& getRandomGenerator() {
    static random_device rd;      // Источник энтропии для инициализации генератора
    static mt19937 gen(rd());       // Генератор случайных чисел, инициализированный с помощью rd
    return gen;                     // Возвращаем ссылку на статический генератор
}

// Создает динамический массив целых чисел заданного размера,
// заполненный случайными значениями в диапазоне [minVal, maxVal].
int* createRandomArray(size_t size, int minVal, int maxVal) {
    int* array = new int[size];  // Выделение памяти для массива из 'size' элементов
    // Создаем распределение для равномерного выбора чисел между minVal и maxVal.
    uniform_int_distribution<int> distr(minVal, maxVal);
    auto& gen = getRandomGenerator();  // Получаем ссылку на глобальный генератор случайных чисел
    // Заполняем массив случайными значениями.
    for (size_t i = 0; i < size; ++i) {
        array[i] = distr(gen);
    }
    return array;  // Возвращаем указатель на созданный массив.
}

// Заполняет переданный массив монотонно возрастающими числами.
// Первый элемент выбирается случайным образом из диапазона [startMin, startMax],
// а каждый последующий элемент равен предыдущему плюс случайный шаг из диапазона [stepMin, stepMax].
void fillArrayRandomIncreasing(int* array, size_t size, int startMin, int startMax, int stepMin, int stepMax) {
    if (size == 0) return;  // Если массив пустой, выходим.
    auto& gen = getRandomGenerator();  // Получаем ссылку на генератор случайных чисел.
    uniform_int_distribution<int> startDistr(startMin, startMax);  // Распределение для начального значения.
    uniform_int_distribution<int> stepDistr(stepMin, stepMax);       // Распределение для шага.
    array[0] = startDistr(gen);  // Заполняем первый элемент массива.
    for (size_t i = 1; i < size; ++i) {
        array[i] = array[i - 1] + stepDistr(gen);  // Каждый следующий элемент = предыдущий + случайный шаг.
    }
}

// Записывает содержимое массива в текстовый файл, разделяя элементы пробелами.
void writeArrayToFile(const string& filename, const int* array, size_t size) {
    ofstream out(filename);  // Открываем файл для записи.
    if (!out) {  // Если файл не удалось открыть, выводим сообщение об ошибке.
        cerr << "Cannot open file " << filename << " for writing." << endl;
        return;
    }
    // Записываем каждый элемент массива в файл.
    for (size_t i = 0; i < size; ++i) {
        out << array[i] << " ";
    }
    out.close();  // Закрываем файл.
}

// Проверяет, отсортирован ли массив (по неубыванию).
// Если массив имеет менее двух элементов, считается, что он отсортирован.
bool isSorted(const int* array, size_t size) {
    if (size < 2) return true;
    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] > array[i])
            return false;
    }
    return true;
}

// Автоматические тесты для проверки функции isSorted с использованием assert.
void testIsSorted() {
    {
        int arr1[] = { 1, 2, 3, 4, 5 };
        assert(isSorted(arr1, 5) == true);
    }
    {
        int arr2[] = { 5, 4, 3, 2, 1 };
        assert(isSorted(arr2, 5) == false);
    }
    {
        int arr3[] = { 1 };
        assert(isSorted(arr3, 1) == true);
    }
    {
        int arr4[] = { 1, 1, 1, 1 };
        assert(isSorted(arr4, 4) == true);
    }
    {
        int arr5[] = { 1, 2, 2, 3, 2 };
        assert(isSorted(arr5, 5) == false);
    }
    cout << "All isSorted tests passed." << endl;
}
