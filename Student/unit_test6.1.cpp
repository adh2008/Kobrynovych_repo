#include <gtest/gtest.h>
#include <cstdlib>
#include <windows.h>

// --- Функції з вашої програми ---

void fillArray(int b[], int size) {
    for (int i = 0; i < size; i++) {
        b[i] = rand() % 106 - 25;
    }
}

int countElements(const int b[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (b[i] > 0 && b[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int sumElements(const int b[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (b[i] > 0 && b[i] % 2 != 0) {
            sum += b[i];
        }
    }
    return sum;
}

void replaceElements(int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (b[i] > 0 && b[i] % 2 != 0) {
            b[i] = 0;
        }
    }
}

// --- Google Tests ---

// 1. Тест обчислення кількості додатних непарних елементів
TEST(IterativeArrayTest, CountElements) {
    const int size = 6;
    // Додатні й непарні: 5, 9, 3 (всього 3 шт)
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };

    EXPECT_EQ(countElements(testArr, size), 3);
}

// 2. Тест обчислення суми додатних непарних елементів
TEST(IterativeArrayTest, SumElements) {
    const int size = 6;
    // Додатні й непарні: 5, 9, 3 -> Сума: 5 + 9 + 3 = 17
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };

    EXPECT_EQ(sumElements(testArr, size), 17);
}

// 3. Тест коли в масиві немає елементів, що відповідають критерію
TEST(IterativeArrayTest, NoMatchingElements) {
    const int size = 5;
    // Тільки від'ємні, парні або нуль
    int testArr[size] = { -5, -3, 0, 2, 4 };

    EXPECT_EQ(countElements(testArr, size), 0);
    EXPECT_EQ(sumElements(testArr, size), 0);
}

// 4. Тест заміни елементів нулями
TEST(IterativeArrayTest, ReplaceElements) {
    const int size = 6;
    int testArr[size] = { -25, 5, 4, 9, 0, 3 };
    int expectedArr[size] = { -25, 0, 4, 0, 0, 0 };

    replaceElements(testArr, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(testArr[i], expectedArr[i]);
    }
}

// 5. Тест генерації: перевірка, чи всі елементи знаходяться в межах [-25, 80]
TEST(IterativeArrayTest, FillArrayRange) {
    const int size = 23;
    int testArr[size];

    fillArray(testArr, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_GE(testArr[i], -25);
        EXPECT_LE(testArr[i], 80);
    }
}

// Головна функція для запуску всіх Google тесті
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}