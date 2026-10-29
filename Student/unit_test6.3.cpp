#include <gtest/gtest.h>

// --- Функції з вашої програми Lab_06.3.cpp ---

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
T SumOddTemplate(T* a, const int size)
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

// --- Google Tests ---

// 1. Тест звичайної функції SumOdd
TEST(IterativeTemplateTest, SumOddRegularFunction) {
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Непарні: 1, 3, 5, 7, 9 -> Сума: 25
    EXPECT_EQ(SumOdd(a, n), 25);
}

// 2. Тест шаблонної функції SumOdd<int>
TEST(IterativeTemplateTest, SumOddTemplateInt) {
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EXPECT_EQ(SumOddTemplate<int>(a, n), 25);
}

// 3. Тест масиву без непарних елементів (очікуваний результат: 0)
TEST(IterativeTemplateTest, SumOddAllEven) {
    const int n = 5;
    int a[n] = { 2, 4, 6, 8, 10 };
    EXPECT_EQ(SumOdd(a, n), 0);
    EXPECT_EQ(SumOddTemplate<int>(a, n), 0);
}

// 4. Тест із від'ємними непарними числами
TEST(IterativeTemplateTest, SumOddNegativeNumbers) {
    const int n = 4;
    int a[n] = { -3, -2, -5, 4 }; // Непарні: -3, -5 -> Сума: -8
    EXPECT_EQ(SumOdd(a, n), -8);
    EXPECT_EQ(SumOddTemplate<int>(a, n), -8);
}