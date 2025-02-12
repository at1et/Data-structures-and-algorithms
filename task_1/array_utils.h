// Функции для работы с классическими массивами: генерация, заполнение, запись в файл, проверка сортировки.

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <cstddef>
#include <string>
using namespace std;

// Создает динамический массив типа int заданного размера,
// заполненный случайными числами в диапазоне [minVal, maxVal].
int* createRandomArray(size_t size, int minVal, int maxVal);

// Заполняет переданный массив типа int заданного размера монотонно возрастающими случайными значениями.
// Параметры: диапазон для первого элемента (startMin, startMax) и диапазон для шага (stepMin, stepMax).
void fillArrayRandomIncreasing(int* array, size_t size, int startMin, int startMax, int stepMin, int stepMax);

// Записывает содержимое массива в текстовый файл.
void writeArrayToFile(const string& filename, const int* array, size_t size);

// Проверяет, отсортирован ли массив; возвращает true, если отсортирован.
bool isSorted(const int* array, size_t size);

// Автоматические тесты для функции isSorted (используются assert).
void testIsSorted();

#endif // ARRAY_UTILS_H
