#include <gtest/gtest.h>
#include <cmath>

using namespace std;

#define main main_lab53
#include "Lab_05_3.cpp"
#undef main

TEST(Lab53Test, HandlesSmallInput) {
    EXPECT_NEAR(p(0.5), atan(0.5), 0.0001);
}   

TEST(Lab53Test, HandlesLargeInput) {
    double expected = (cos(sin(2.0)) + 1.0) / (exp(-2.0) + 1.0);
    EXPECT_NEAR(p(2.0), expected, 0.0001);
}