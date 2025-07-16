#include <gtest/gtest.h>

#include "source.hpp"

std::uint64_t exp(const std::uint64_t x, std::uint64_t n);

struct ExpTestData {
    std::uint64_t x;
    std::uint64_t n;
    std::uint64_t expected_result;
};

class ExpParametrizedTest : public testing::TestWithParam<ExpTestData> {
};

TEST_P(ExpParametrizedTest, Successful) {
    const auto& test_data = GetParam();
    EXPECT_EQ(exp(test_data.x, test_data.n), test_data.expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    SuccessfulExp,
    ExpParametrizedTest,
    ::testing::Values(
        ExpTestData{2, 0, 1},
        ExpTestData{2, 1, 2},
        ExpTestData{3, 2, 9}, 
        ExpTestData{4, 3, 64},
        ExpTestData{2, 7, 128}
    )
);