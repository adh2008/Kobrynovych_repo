#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    double a, b, c;
    double x_start, x_end, dx;

    // Введення параметрів a, b, c з клавіатури
    cout << "Введіть a: ";
    cin >> a;
    cout << "Введіть b: ";
    cin >> b;
    cout << "Введіть c: ";
    cin >> c;

    // Введення проміжку та кроку
    cout << "Введіть X_поч: ";
    cin >> x_start;
    cout << "Введіть X_кін: ";
    cin >> x_end;
    cout << "Введіть dX (крок): ";
    cin >> dx;

    // Перевірка коректності кроку
    if (dx <= 0) {
        cout << "Помилка: крок dX повинен бути більше 0!" << endl;
        return 1;
    }

    // Шапка таблиці
    cout << "\n+--------------+--------------+" << endl;
    cout << "|      x       |      F       |" << endl;
    cout << "+--------------+--------------+" << endl;

    // Форматування виводу (4 знаки після коми)
    cout << fixed << setprecision(4);

    // Обчислення значення функції F на заданому інтервалі
    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        // Усуваємо похибку чисел із рухомою комою поблизу нуля
        if (abs(x) < 1e-9) {
            x = 0.0;
        }

        double F;
        bool division_by_zero = false;

        // Перевірка умов для обчислення F
        if (a < 0 && x != 0) {
            F = a * x * x + b * b * x;
        } 
        else if (a > 0 && x == 0) {
            // Перевірка ділення на нуль (x - c == 0 при x = 0, тобто c == 0)
            if (x - c == 0) {
                division_by_zero = true;
            } else {
                F = x - (a / (x - c));
            }
        } 
        else { // В інших випадках
            // Перевірка ділення на нуль (c == 0)
            if (c == 0) {
                division_by_zero = true;
            } else {
                F = 1.0 + (x / c);
            }
        }

        // Виведення результату у таблицю
        if (division_by_zero) {
            cout << "| " << setw(12) << x << " | " << setw(12) << "ділення на 0" << " |" << endl;
        } else {
            cout << "| " << setw(12) << x << " | " << setw(12) << F << " |" << endl;
        }
    }

    cout << "+--------------+--------------+" << endl;

    return 0;
}