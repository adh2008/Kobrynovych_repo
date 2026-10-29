#include <gtest/gtest.h>
#include <vector>

using namespace std;

// Рекурсивна функція з Lab_06.2.cpp
int sumOddElementIndices(const vector<int>& a, int i)
{
    if (i == a.size())
        return 0;

    if (a[i] % 2 != 0)
        return i + sumOddElementIndices(a, i + 1);

    return sumOddElementIndices(a, i + 1);
}

// Тест 1: Звичайний масив із непарними елементами
TEST(RecursiveIndicesTest, SumIndicesWithOddElements) {
    // Індекси непарних елементів (5, 7, 9): 1, 3, 4 -> Сума: 1 + 3 + 4 = 8
    vector<int> a = {4, 5, 2, 7, 9};
    EXPECT_EQ(sumOddElementIndices(a, 0), 8);
}

// Тест 2: Масив лише з парними елементами (сума індексів повинна дорівнювати 0)
TEST(RecursiveIndicesTest, SumIndicesAllEven) {
    vector<int> a = {2, 4, 6, 8, 10};
    EXPECT_EQ(sumOddElementIndices(a, 0), 0);
}

// Тест 3: Масив із від'ємними непарними елементами
TEST(RecursiveIndicesTest, SumIndicesNegativeOdd) {
    // Індекси непарних елементів (-3, -5): 0, 2 -> Сума: 0 + 2 = 2
    vector<int> a = {-3, -2, -5};
    EXPECT_EQ(sumOddElementIndices(a, 0), 2);
}