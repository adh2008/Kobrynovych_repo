// Lab_05_5.cpp
// Лабораторна робота № 5.5 (Варіант 9)
#include <iostream>

using namespace std;

// Рекурсивна функція f(n) з відстеженням рівня та глибини рекурсії
int f(int n, int level, int &depth)
{
    if (level > depth)
        depth = level;

    if (n == 0)
        return 0;
    if (n % 10 > 0)
        return n % 10;

    return f(n / 10, level + 1, depth);
}

// Функція для обчислення суми S(p, q) та знаходження максимальної глибини
int S(int p, int q, int &max_depth)
{
    int sum = 0;
    max_depth = 0;

    for (int i = p; i <= q; ++i)
    {
        int current_depth = 0;
        int val = f(i, 1, current_depth);
        sum += val;

        if (current_depth > max_depth)
            max_depth = current_depth;
    }

    return sum;
}

int main()
{
    int p, q;
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    int max_depth = 0;
    int sum = S(p, q, max_depth);

    cout << "S(" << p << ", " << q << ") = " << sum << endl;
    cout << "Max depth = " << max_depth << endl;

    return 0;
}