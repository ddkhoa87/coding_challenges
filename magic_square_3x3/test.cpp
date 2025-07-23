#include <gtest/gtest.h>

#include "generate_magic_square.hpp"
#include "min_cost_to_magic_square.hpp"

constexpr bool is_magic_square(const MagicSquare& square) {
    std::array<bool, 9> is_magic{false};
    for (const auto& val : square) {
        if (is_magic[val - 1]) {
            return false; // Duplicate value found
        }
        is_magic[val - 1] = true; // Mark this value as seen
    }

    const int magic_sum{15}; // The magic sum for a 3x3 magic square
    return (square[0] + square[1] + square[2] == magic_sum) &&
           (square[3] + square[4] + square[5] == magic_sum) &&
           (square[6] + square[7] + square[8] == magic_sum) &&
           (square[0] + square[3] + square[6] == magic_sum) &&
           (square[1] + square[4] + square[7] == magic_sum) &&
           (square[2] + square[5] + square[8] == magic_sum) &&
           (square[0] + square[4] + square[8] == magic_sum) &&
           (square[2] + square[4] + square[6] == magic_sum);
}

TEST(GenerateMagicSquare, AllMagicSquaresAtCompileTime) {
    constexpr auto magic_squares = generate_all_magic_squares();

    static_assert(is_magic_square(magic_squares[0]));
    static_assert(is_magic_square(magic_squares[1]));
}

struct TestData {
    std::vector<std::vector<int>> input;
    int expected_min_cost;
};

class MinCostToMagicSquareTest : public ::testing::TestWithParam<TestData> {};

TEST_P(MinCostToMagicSquareTest, Successful) {
    const auto& [input, expected_min_cost] = GetParam();
    EXPECT_EQ(formingMagicSquare(input), expected_min_cost);
}

INSTANTIATE_TEST_SUITE_P(
    Successful,
    MinCostToMagicSquareTest,
    ::testing::Values(
        TestData{{{4, 5, 8}, {2, 4, 1}, {1, 9, 7}}, 14},
        TestData{{{5, 3, 4}, {1, 5, 8}, {6, 4, 2}}, 7},
        TestData{{{4, 9, 2}, {3, 5, 7}, {8, 1, 5}}, 1},
        TestData{{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, 0},
        TestData{{{4, 8, 2}, {4, 5, 7}, {6, 1, 6}}, 4}
    ));