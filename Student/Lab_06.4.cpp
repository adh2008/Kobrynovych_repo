//рекурсивний 2 спосіб
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// Введення елементів масиву
void inputArray(double* a, int n, int i)
{
    if (i == n)
        return;

    cout << "a[" << i << "] = ";
    cin >> a[i];

    inputArray(a, n, i + 1);
}

// Виведення масиву у форматованому вигляді
void printArray(const double* a, int n, int i)
{
    if (i == n)
        return;

    printf("%10.2f", a[i]);
    printArray(a, n, i + 1);
}

// Пошук елемента з найбільшим модулем
double maxAbsElement(const double* a, int n, int i)
{
    if (i == n - 1)
        return a[i];

    double maxElement = maxAbsElement(a, n, i + 1);

    if (fabs(a[i]) > fabs(maxElement))
        return a[i];

    return maxElement;
}

// Пошук індексу першого додатного елемента
int findFirstPositive(const double* a, int n, int i)
{
    if (i == n)
        return -1;

    if (a[i] > 0)
        return i;

    return findFirstPositive(a, n, i + 1);
}

// Пошук індексу наступного додатного елемента
int findSecondPositive(const double* a, int n, int i)
{
    if (i == n)
        return -1;

    if (a[i] > 0)
        return i;

    return findSecondPositive(a, n, i + 1);
}

// Обчислення суми елементів між двома індексами
double sumBetween(const double* a, int left, int right)
{
    if (left >= right - 1)
        return 0.0;

    return a[left + 1] + sumBetween(a, left + 1, right);
}

// Перенесення ненульових елементів на початок
void moveNonZero(double* a, int n, int i, int& pos)
{
    if (i == n)
        return;

    if (a[i] != 0.0)
    {
        a[pos] = a[i];
        pos++;
    }

    moveNonZero(a, n, i + 1, pos);
}

// Заповнення решти масиву нулями
void fillZeros(double* a, int n, int i)
{
    if (i == n)
        return;

    a[i] = 0.0;
    fillZeros(a, n, i + 1);
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n must be positive." << endl;
        return 1;
    }

    double* a = new double[n];

    cout << "Enter array elements:" << endl;
    inputArray(a, n, 0);

    cout << "\nOriginal array:\n";
    printArray(a, n, 0);
    cout << endl;

    // 1.1. Максимальний за модулем елемент
    double maxElement = maxAbsElement(a, n, 0);

    cout << "Element with maximum absolute value: "
         << maxElement << endl;

    // 1.2. Сума між першим і другим додатними елементами
    int first = findFirstPositive(a, n, 0);
    int second = -1;

    if (first != -1)
        second = findSecondPositive(a, n, first + 1);

    if (first != -1 && second != -1)
    {
        double sum = sumBetween(a, first, second);
        cout << "Sum between first and second positive elements: "
             << sum << endl;
    }
    else
    {
        cout << "There are fewer than two positive elements. "
             << "Sum cannot be calculated." << endl;
    }

    // 2. Перенесення нулів у кінець зі збереженням порядку
    int pos = 0;
    moveNonZero(a, n, 0, pos);
    fillZeros(a, n, pos);

    cout << "Modified array:\n";
    printArray(a, n, 0);
    cout << endl;

    delete[] a;

    return 0;
}
