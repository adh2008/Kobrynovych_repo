// Lab_03_2.cpp
// < Кобринович, Богдан >
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 0.9

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x; // вхідний аргумент
    double a; // вхідний параметр
    double b; // вхідний параметр
    double c; // вхідний параметр
    double F; // результат обчислення виразу

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c; 
    cout << "x = "; cin >> x;
    
    // Спосіб 1: розгалуження в скороченій формі
    if (a < 0 && x != 0)
        F = a * pow(x, 2) + pow(b, 2) * x;

    if (a > 0 && x == 0)
        F = x - (a / (x - c));

    if (!(a < 0 && x != 0) && !(a > 0 && x == 0))
        F = 1 + (x / c);

    cout << "1) F = " << F << endl;

    // Спосіб 2: розгалуження в повній формі
    if (a < 0 && x != 0)
        F = a * pow(x, 2) + pow(b, 2) * x;
    else if (a > 0 && x == 0)
        F = x - (a / (x - c));
    else
        F = 1 + (x / c);

    cout << "2) F = " << F << endl;
    
    cin.get();
    return 0;
}