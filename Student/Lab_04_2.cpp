#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    double x_start, x_end, dx;

    // Введення початкових даних з клавіатури
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
    cout << "|      x       |      y       |" << endl;
    cout << "+--------------+--------------+" << endl;

    // Форматування виводу чисел (4 знаки після коми)
    cout << fixed << setprecision(4);

    // Цикл для обчислення значення функції на заданому інтервалі
    // Додаємо dx / 2.0 для уникнення помилок точності типів з рухомою комою
    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        double f_x;

        // Обчислення значення системи умов
        if (x <= -0.1) {
            f_x = 5.0 * cos(18.0 * x);
        } 
        else if (x < 1.2) { // -0.1 < x < 1.2
            f_x = atan((x + 2.0) / 5.0);
        } 
        else { // x >= 1.2
            double tan_val = tan(x);
            // Перевірка ділення на нуль для ctg(x) = 1 / tan(x)
            if (abs(tan_val) < 1e-9) {
                cout << "| " << setw(12) << x << " | " << setw(12) << "не існує" << " |" << endl;
                continue;
            }
            f_x = (1.0 / tan_val) + 18.0;
        }

        // Обчислення підсумкового значення y = 2|x|^3 - f(x)
        double y = 2.0 * pow(fabs(x), 3) - f_x;

        // Виведення строчки таблиці
        cout << "| " << setw(12) << x << " | " << setw(12) << y << " |" << endl;
    }

    cout << "+--------------+--------------+" << endl;

    return 0;
}