#include <gtest/gtest.h>

#include "source.hpp"

struct TestData {
    int input;
    int expected;
};

class ParametrizedTest : public ::testing::TestWithParam<TestData> {};

TEST_P(ParametrizedTest, Successful) {
    auto [input, expected] = GetParam();
}

INSTANTIATE_TEST_SUITE_P(
    Successful, 
    ParametrizedTest,
    ::testing::Values(
        TestData{}
));
