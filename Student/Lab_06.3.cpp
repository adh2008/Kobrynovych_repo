//ітераційний 1 спосіб
#include <iostream>
#include <iomanip>
using namespace std;

// Оголошення звичайних функцій
void PrintArray(int* a, const int size);
int SumOdd(int* a, const int size);

// Оголошення шаблонної функції
template <typename T>
T SumOdd(T* a, const int size);

int main()
{
    const int n = 10;

    // 1. Формування масиву
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 2. Виведення масиву
    cout << "Initial array: ";
    PrintArray(a, n);

    // 3. Обчислення суми звичайною функцією
    int s1 = SumOdd(a, n);
    cout << "SumOdd(a, n) = " << s1 << endl;

    // 4. Обчислення суми шаблонною функцією
    int s2 = SumOdd<int>(a, n);
    cout << "SumOdd<int>(a, n) = " << s2 << endl;

    return 0;
}

// Функція виведення масиву
void PrintArray(int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// Звичайна функція обчислення суми непарних елементів
int SumOdd(int* a, const int size)
{
    int s = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
        {
            s += a[i];
        }
    }

    return s;
}

// Шаблонна функція обчислення суми непарних елементів
template <typename T>
T SumOdd(T* a, const int size)
{
    T s = T();

    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
        {
            s += a[i];
        }
    }

    return s;
}
