#include <gtest/gtest.h>
#include <cmath>

using namespace std;

#define main main_lab54
#include "Lab_05_4.cpp"
#undef main

TEST(Lab54Test, AllMethodsReturnEqualResults) {
    int K = 1;
    int N = 15;
    double expected = S0(K, N);

    EXPECT_NEAR(S1(K, N, K), expected, 0.00001);
    EXPECT_NEAR(S2(K, N, N), expected, 0.00001);
    EXPECT_NEAR(S3(K, N, K, 0), expected, 0.00001);
    EXPECT_NEAR(S4(K, N, N, 0), expected, 0.00001);
}