#include <gtest/gtest.h>

#include "source.hpp"

struct TestData {
    int h;
    int m;
    std::string expected;
};

class ParametrizedTest : public ::testing::TestWithParam<TestData> {};

TEST_P(ParametrizedTest, Successful) {
    const auto [h, m, expected] = GetParam();
    EXPECT_EQ(timeInWords(h, m), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Successful, 
    ParametrizedTest,
    ::testing::Values(
        TestData{5, 0, "five o' clock"},
        TestData{5, 1, "one minute past five"},
        TestData{5, 10, "ten minutes past five"},
        TestData{5, 28, "twenty eight minutes past five"},
        TestData{5, 15, "quarter past five"},
        TestData{5, 30, "half past five"},
        TestData{5, 45, "quarter to six"},
        TestData{5, 47, "thirteen minutes to six"}
    ));