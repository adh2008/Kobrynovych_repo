#include <gtest/gtest.h>
#include <cmath>

#define main main_lab51
#include "Lab_05_1.cpp"
#undef main

using namespace std;

TEST(Lab51Test, HandlesZeroInput) {
    EXPECT_NEAR(h(0.0, 0.0), 0.0, 0.0001);
}

TEST(Lab51Test, HandlesUnitInput) {
    EXPECT_NEAR(h(1.0, 1.0), 2.0 / 3.0, 0.0001);
} 