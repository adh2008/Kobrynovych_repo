// Lab 5_1
// Варіант 9

#include <iostream>
#include <cmath>

using namespace std;

// Прототип функції h(x, y)
double h(const double x, const double y);

int main()
{
    double s, t;

    cout << "s = "; cin >> s;
    cout << "t = "; cin >> t;

    // Обчислення виразу згідно з варіантом 9:
    // h(1, s + t) + h(s, s - t) - h(t, sqrt(s^2 + t^2))
    double c = h(1, s + t) + h(s, s - t) - h(t, sqrt(s * s + t * t));

    cout << "c = " << c << endl;

    return 0;
}

// Визначення функції h(x, y) = (x^2 + y^2) / (1 + x^2 + x^2 * y^2)
double h(const double x, const double y)
{
    return (x * x + y * y) / (1 + x * x + x * x * y * y);
}

