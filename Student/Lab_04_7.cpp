#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "atan(x)" << " |"
         << setw(12) << "S" << " |"
         << setw(7) << "n" << " |"
         << endl;
    cout << "---------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2.0)
    {
        n = 0;
        a = x;    // Перший доданок при n = 0 дорівнює x
        S = a;

        do {
            n++;
            // Рекурентне співвідношення R = a_n / a_{n-1}
            R = -x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
            a *= R;
            S += a;
        } while (abs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(5) << atan(x) << " |"
             << setw(12) << setprecision(5) << S << " |"
             << setw(7) << n + 1 << " |"  // Загальна кількість доданків
             << endl;

        x += dx;
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}