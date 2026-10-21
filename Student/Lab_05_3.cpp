// Лабораторна робота № 5.3
// Варіант 9
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
  
double p(const double x);

int main()
{
    double qp, qk, q, dq, z;
    int n;

    cout << "qp = "; cin >> qp;
    cout << "qk = "; cin >> qk;
    cout << "n = "; cin >> n;

    dq = (qk - qp) / n;
    q = qp;

    cout << fixed;
    cout << "-----------------------------------" << endl;
    cout << "|" << setw(12) << "q" << " |"
         << setw(16) << "z" << " |" << endl;
    cout << "-----------------------------------" << endl;

    while (q <= qk + dq / 2.0)
    {
        z = p(1.0 - q * q) + pow(p(1.0 + q - sqrt(abs(p(q)))), 2);
        
        cout << "|" << setw(12) << setprecision(3) << q << " |"
             << setw(16) << setprecision(5) << z << " |" << endl;
        
        q += dq;
    }
    cout << "-----------------------------------" << endl;

    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1.0)
    {
        return (cos(sin(x)) + 1.0) / (exp(-x) + 1.0);
    }
    else
    {
        double S = 0;
        int j = 0;
        double a = x; // При j = 0 перший доданок a0 = x
        S = a;
        do
        {
            j++;
            double R = -x * x * (2.0 * j - 1.0) / (2.0 * j + 1.0);
            a *= R;
            S += a;
        } while (j < 4);
        
        return S;
    }
}