#include <gtest/gtest.h>
#include <hello.hpp>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, BasicClassTest)
{
    Hello h{5};
    EXPECT_EQ(h.get_i(), 5);
}