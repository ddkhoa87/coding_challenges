#pragma once

#include <math.h>
#include <vector>

using namespace std;

#include "generate_magic_square.hpp"

constexpr auto magic_squares = generate_all_magic_squares();

constexpr int operator -(const MagicSquare &l, const MagicSquare &r) {
    int sum_differences{0};
    for (int i = 0; i < l.size(); ++i) {
        sum_differences += abs(l[i] - r[i]);
    }
    return sum_differences;
}

constexpr int min_cost_to_magic_square(const MagicSquare &s) {
    int min_cost{std::numeric_limits<int>::max()};
    for (const auto &magic_square : magic_squares) {
        int cost = s - magic_square;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int formingMagicSquare(vector<vector<int>> s) {
    MagicSquare s1;
    // int i = 0;
    // for (const auto &vec : s)
    // {
    //     for (const auto &val : vec) {
    //         s1d[i] = val;
    //         ++i;
    //     }
    // }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            s1[i * s.size() + j] = s[i][j];
        }
    }
    
    return min_cost_to_magic_square(s1);
}