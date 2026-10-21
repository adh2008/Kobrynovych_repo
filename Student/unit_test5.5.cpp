#include <gtest/gtest.h>

using namespace std;

#define main main_lab55
#include "Lab_05_5.cpp"
#undef main

TEST(Lab55Test, SingleFunctionEvaluationAndDepth) {
    int depth = 0;

    // f(123) = 3, глибина = 1
    EXPECT_EQ(f(123, 1, depth), 3);
    EXPECT_EQ(depth, 1);

    // f(120) -> f(12) = 2, глибина = 2
    depth = 0;
    EXPECT_EQ(f(120, 1, depth), 2);
    EXPECT_EQ(depth, 2);

    // f(100) -> f(10) -> f(1) = 1, глибина = 3
    depth = 0;
    EXPECT_EQ(f(100, 1, depth), 1);
    EXPECT_EQ(depth, 3);
}

TEST(Lab55Test, SumAndMaxDepthCalculation) {
    int max_depth = 0;

    // Для діапазону [10, 15]:
    // f(10)=1, f(11)=1, f(12)=2, f(13)=3, f(14)=4, f(15)=5
    // Сума = 1 + 1 + 2 + 3 + 4 + 5 = 16, Максимальна глибина = 2
    int sum = S(10, 15, max_depth);

    EXPECT_EQ(sum, 16);
    EXPECT_EQ(max_depth, 2);
}