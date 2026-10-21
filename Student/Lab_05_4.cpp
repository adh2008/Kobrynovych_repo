// Lab_05_4.cpp
// Лабораторна робота № 5.4 (Варіант 9)
#include <iostream>
#include <cmath>

using namespace std;

// 5) Ітераційний спосіб
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i);
    return s;
}

// 1) Рекурсивний підйом (параметр зростає: i+1)
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i) + S1(K, N, i + 1);
}

// 2) Рекурсивний підйом (параметр спадає: i-1)
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i) + S2(K, N, i - 1);
}

// 3) Рекурсивний спуск (параметр зростає: i+1)
double S3(const int K, const int N, const int i, double t)
{
    t = t + (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i);
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// 4) Рекурсивний спуск (параметр спадає: i-1)
double S4(const int K, const int N, const int i, double t)
{
    t = t + (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i);
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main()
{
    int K = 1;
    int N = 15;

    cout << "K = " << K << ", N = " << N << endl << endl;

    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;

    return 0;
}