// Lab_03_4.cpp
// Кобринович Богдан
// Лабораторна робота № 3.4
// Перевірка належності точки зафарбованій області
// Варіант 9

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, R;

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    // Перевірка належності точки зафарбованій області
    if (x * x + y * y <= R * R && ((x <= 0 && y <= 0) || (x >= 0 && y >= pow(x - 1, 2)))) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cin.get();
    return 0;
}