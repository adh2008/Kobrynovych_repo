#include <gtest/gtest.h>



bool IsCriterion(int value) {
    return (value > 0 && value % 2 != 0);
}

int Count(const int* b, const int size, int i = 0) {
    if (i >= size) return 0;
    int current = IsCriterion(b[i]) ? 1 : 0;
    return current + Count(b, size, i + 1);
}

int Sum(const int* b, const int size, int i = 0) {
    if (i >= size) return 0;
    int current = IsCriterion(b[i]) ? b[i] : 0;
    return current + Sum(b, size, i + 1);
}

void Replace(int* b, const int size, int i = 0) {
    if (i >= size) return;
    if (IsCriterion(b[i])) {
        b[i] = 0;
    }
    Replace(b, size, i + 1);
}

// --- Google Tests ---

// 1. Тест рекурсивного обчислення кількості
TEST(RecursiveArrayTest, CountElements) {
    const int size = 6;
    // Додатні й непарні: 5, 9, 3 (всього 3 шт)
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };

    EXPECT_EQ(Count(testArr, size), 3);
}

// 2. Тест рекурсивного обчислення суми
TEST(RecursiveArrayTest, SumElements) {
    const int size = 6;
    // Додатні й непарні: 5 + 9 + 3 = 17
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };

    EXPECT_EQ(Sum(testArr, size), 17);
}

// 3. Тест рекурсивного підрахунку, коли відсутні потрібні елементи
TEST(RecursiveArrayTest, NoMatchingElements) {
    const int size = 5;
    int testArr[size] = { -15, -3, 0, 2, 80 };

    EXPECT_EQ(Count(testArr, size), 0);
    EXPECT_EQ(Sum(testArr, size), 0);
}

// 4. Тест рекурсивної заміни елементів нулями
TEST(RecursiveArrayTest, ReplaceElements) {
    const int size = 6;
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };
    int expectedArr[size] = { -25, 0, 4, 0, 0, 0 };

    Replace(testArr, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(testArr[i], expectedArr[i]);
    }
}