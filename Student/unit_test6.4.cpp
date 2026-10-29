#include <gtest/gtest.h>
#include <cmath>

using namespace std;

// --- Функції з Lab_06.4.cpp ---

double maxAbsElement(const double* a, int n, int i)
{
    if (i == n - 1)
        return a[i];

    double maxElement = maxAbsElement(a, n, i + 1);

    if (fabs(a[i]) > fabs(maxElement))
        return a[i];

    return maxElement;
}

int findFirstPositive(const double* a, int n, int i)
{
    if (i == n)
        return -1;

    if (a[i] > 0)
        return i;

    return findFirstPositive(a, n, i + 1);
}

int findSecondPositive(const double* a, int n, int i)
{
    if (i == n)
        return -1;

    if (a[i] > 0)
        return i;

    return findSecondPositive(a, n, i + 1);
}

double sumBetween(const double* a, int left, int right)
{
    if (left >= right - 1)
        return 0.0;

    return a[left + 1] + sumBetween(a, left + 1, right);
}

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

void fillZeros(double* a, int n, int i)
{
    if (i == n)
        return;

    a[i] = 0.0;
    fillZeros(a, n, i + 1);
}

// --- Google Tests ---

// 1. Тест пошуку елемента з найбільшим модулем
TEST(RecursiveLab64Test, MaxAbsElement) {
    const int n = 4;
    double a[n] = { -1.5, 3.2, -7.8, 4.0 };
    EXPECT_DOUBLE_EQ(maxAbsElement(a, n, 0), -7.8);
}

// 2. Тест пошуку перших двох додатних елементів та обчислення суми між ними
TEST(RecursiveLab64Test, SumBetweenPositives) {
    const int n = 5;
    // Перший додатний: 5.0 (індекс 1), Другий додатний: 2.5 (індекс 3)
    // Елемент між ними: -3.0 (індекс 2) -> Сума = -3.0
    double a[n] = { -2.0, 5.0, -3.0, 2.5, 4.0 };

    int first = findFirstPositive(a, n, 0);
    int second = findSecondPositive(a, n, first + 1);

    EXPECT_EQ(first, 1);
    EXPECT_EQ(second, 3);
    EXPECT_DOUBLE_EQ(sumBetween(a, first, second), -3.0);
}

// 3. Тест трансформації масиву (перенесення нулів у кінець)
TEST(RecursiveLab64Test, MoveZerosToEnd) {
    const int n = 5;
    double a[n] = { 0.0, 2.5, 0.0, -1.2, 3.0 };
    double expected[n] = { 2.5, -1.2, 3.0, 0.0, 0.0 };

    int pos = 0;
    moveNonZero(a, n, 0, pos);
    fillZeros(a, n, pos);

    for (int i = 0; i < n; ++i) {
        EXPECT_DOUBLE_EQ(a[i], expected[i]);
    }
}