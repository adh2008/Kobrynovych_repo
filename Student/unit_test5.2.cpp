#include <gtest/gtest.h>
#include <cmath>

using namespace std;

#define main main_lab52
#include "Lab_05_2.cpp"
#undef main

TEST(Lab52Test, HandlesZeroInput) {
    int n = 0;
    double s = 0.0;
    double eps = 0.0001;

    S(0.0, eps, n, s);
    EXPECT_NEAR(s, atan(0.0), eps);
} 

TEST(Lab52Test, HandlesPointFiveInput) {
    int n = 0;
    double s = 0.0;
    double eps = 0.0001;

    S(0.5, eps, n, s);
    EXPECT_NEAR(s, atan(0.5), eps);
}

TEST(Lab52Test, HandlesUnitInput) {
    int n = 0;
    double s = 0.0;
    double eps = 0.0001;

    S(1.0, eps, n, s);
    EXPECT_NEAR(s, atan(1.0), eps);
}