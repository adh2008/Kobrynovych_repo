// Лабораторна робота № 5.2 (Варіант 9) - 1-й спосіб
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "atan(x)" << " |"
         << setw(12) << "S" << " |"
         << setw(5) << "n" << " |"
         << endl;
    cout << "-----------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2.0)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(5) << atan(x) << " |"
             << setw(12) << setprecision(5) << s << " |"
             << setw(5) << n << " |"
             << endl;  
        x += dx;
    }
    cout << "-----------------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = x; // При n = 0 перший доданок a0 = x
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
    double R = -x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
    a *= R;
}