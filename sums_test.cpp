#include "sums.h"
#include <gtest/gtest.h>

TEST(FactorialTest, Negative)
{
    EXPECT_EQ(1, Factorial(-5));
}
TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }