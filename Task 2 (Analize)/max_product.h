#ifndef MAX_PRODUCT_H  // Проверяем, не был ли этот заголовочный файл включён ранее
#define MAX_PRODUCT_H  // Определяем макрос, чтобы предотвратить повторное включение

#include <vector>       // Подключаем вектор для работы с массивами
#include <stdexcept>    // Подключаем исключения для обработки ошибок

using namespace std;    // Используем стандартное пространство имён

// Структура для хранения результата работы функции
struct ProductResult {
    double product;    // Наибольшее произведение двух чисел в массиве
    double factor1;    // Первый множитель (число из массива)
    double factor2;    // Второй множитель (число из массива)
    int comparisons;   // Количество сравнений, выполненных алгоритмом
};

// ФункциЯ, которая находит наибольшее произведение двух чисел в массиве
ProductResult maxProduct(const vector<double>& arr);

// Функция для сохранения результата в текстовый файл
void saveResultToFile(const string& filename, const vector<double>& arr, const ProductResult& res);

#endif // MAX_PRODUCT_H  // Завершаем директиву препроцессора
