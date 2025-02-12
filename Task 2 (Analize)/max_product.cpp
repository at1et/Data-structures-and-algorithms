#include "max_product.h"  // Подключаем заголовочный файл с объявлением структуры и функции
#include <limits>         // Подключаем библиотеку для работы с бесконечностью
#include <fstream>
#include <stdexcept>

using namespace std;  // Используем стандартное пространство имён

// Функция, находящая два числа с максимальным произведением
ProductResult maxProduct(const vector<double>& arr) {
    // Проверяем, что в массиве хотя бы два элемента, иначе выбрасываем исключение
    if (arr.size() < 2) {
        throw invalid_argument("Массив должен содержать как минимум два элемента.");
    }

    // Переменные для хранения двух наибольших и двух наименьших чисел
    double max1 = -numeric_limits<double>::infinity();  // Первый максимум (самое большое число)
    double max2 = -numeric_limits<double>::infinity();  // Второй максимум (второе по величине число)
    double min1 = numeric_limits<double>::infinity();   // Первый минимум (самое маленькое число)
    double min2 = numeric_limits<double>::infinity();   // Второй минимум (второе по величине среди отрицательных)

    int comparisons = 0;  // Счётчик сравнений (показывает, сколько раз мы сравнивали элементы массива)

    // Перебираем все элементы массива
    for (double x : arr) {
        comparisons++;  // Увеличиваем счётчик сравнений

        // Проверяем, является ли x новым максимумом
        if (x > max1) {
            max2 = max1;  // Второй максимум сдвигаем на место первого
            max1 = x;     // Новый максимум записываем в max1
        }
        else {
            comparisons++;  // Дополнительное сравнение
            if (x > max2) { // Если x больше второго максимума, обновляем max2
                max2 = x;
            }
        }

        comparisons++;  // Увеличиваем счётчик сравнений

        // Проверяем, является ли x новым минимумом
        if (x < min1) {
            min2 = min1;  // Второй минимум сдвигаем на место первого
            min1 = x;     // Новый минимум записываем в min1
        }
        else {
            comparisons++;  // Дополнительное сравнение
            if (x < min2) { // Если x меньше второго минимума, обновляем min2
                min2 = x;
            }
        }
    }

    // Вычисляем два возможных произведения
    double candidate1 = max1 * max2;  // Произведение двух наибольших чисел
    double candidate2 = min1 * min2;  // Произведение двух наименьших чисел (если они отрицательные, результат положительный)

    // Создаём структуру для хранения результата
    ProductResult result;
    result.comparisons = comparisons;  // Записываем количество сравнений

    // Выбираем наибольшее произведение
    if (candidate1 >= candidate2) {
        result.product = candidate1;  // Записываем максимальное произведение
        result.factor1 = max1;        // Первый множитель
        result.factor2 = max2;        // Второй множитель
    }
    else {
        result.product = candidate2;  // Записываем максимальное произведение
        result.factor1 = min1;        // Первый множитель
        result.factor2 = min2;        // Второй множитель
    }

    return result; // Возвращаем результат работы функции
}
// Функция для сохранения результатов в текстовый файл
void saveResultToFile(const string& filename, const vector<double>& arr, const ProductResult& res) {
    ofstream outputFile(filename);
    if (!outputFile) {
        throw runtime_error("Ошибка открытия файла для записи.");
    }

    outputFile << "Исходный массив: ";
    for (double x : arr) {
        outputFile << x << " ";
    }
    outputFile << "\n";

    outputFile << "Наибольшее произведение: " << res.product << "\n";
    outputFile << "Множители: " << res.factor1 << " и " << res.factor2 << "\n";
    outputFile << "Количество сравнений: " << res.comparisons << "\n";

    outputFile.close();
}

