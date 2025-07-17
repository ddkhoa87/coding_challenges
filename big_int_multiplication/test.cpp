#include <gtest/gtest.h>

#include "source.hpp"

struct TestData {
    BigInt l;
    BigInt r;
    BigInt expected;
};

class ParametrizedTest : public ::testing::TestWithParam<TestData> {};

TEST_P(ParametrizedTest, Successful) {
    auto [l, r, expected] = GetParam();

    EXPECT_EQ(l *= r, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Successful,
    ParametrizedTest,
    ::testing::Values(
        TestData{0, 0, 0},
        TestData{0, 1, 0},
        TestData{1, 0, 0},
        TestData{1, 1, 1},
        TestData{1, 2, 2},
        TestData{2, 1, 2},
        TestData{15, 10, 150},
        TestData{12345, 12345, 152399025}
    )
);