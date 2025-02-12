// Этот файл содержит класс Timer для измерения времени работы участка кода.

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>
#include <string>

// Используем пространство имён std и chrono во всём файле
using namespace std;
using namespace chrono;

class Timer {
public:
    // Конструктор принимает имя таймера для вывода в лог.
    Timer(const string& name = "")
        : name(name), start(steady_clock::now()) {}

    // Деструктор вычисляет разницу времени и выводит результат.
    ~Timer() {
        auto end = steady_clock::now();
        auto delta = duration_cast<milliseconds>(end - start);
        cout << "Timer [" << name << "]: " << delta.count() << " ms" << endl;
    }
private:
    string name;
    steady_clock::time_point start;
};

#endif // TIMER_H
