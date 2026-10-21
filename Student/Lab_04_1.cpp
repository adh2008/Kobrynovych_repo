#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, N, i;
    double S;

    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;

    // 1) Цикл while
    S = 0;
    i = k;
    while (i <= N)
    {
        S += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
        i++;
    }
    cout << S << endl;

    // 2) Цикл do-while
    S = 0;
    i = k;
    do {
        S += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
        i++;
    } while (i <= N);
    cout << S << endl;

    // 3) Цикл for з інкрементом (i++)
    S = 0;
    for (i = k; i <= N; i++)
    {
        S += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
    }
    cout << S << endl;

    // 4) Цикл for з декрементом (i--)
    S = 0;
    for (i = N; i >= k; i--)
    {
        S += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
    }
    cout << S << endl;

    return 0;
}