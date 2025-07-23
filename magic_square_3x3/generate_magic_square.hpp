#pragma once

#include <iostream>
#include <vector>
#include <array>

using MagicSquare = std::array<int, 9>;

// Helper function to rotate a magic square 90 degrees clockwise
constexpr MagicSquare rotate(const MagicSquare& s) {
    return {s[6], s[3], s[0], s[7], s[4], s[1], s[8], s[5], s[2]};
}

// Helper function to reflect a magic square horizontally
constexpr MagicSquare reflect(const MagicSquare& s) {
    return {s[2], s[1], s[0], s[5], s[4], s[3], s[8], s[7], s[6]};
}

constexpr std::array<MagicSquare, 8> generate_all_magic_squares() {
    std::array<MagicSquare, 8> squares{};
    // Start with a known magic square
    squares[0] = {8, 1, 6, 3, 5, 7, 4, 9, 2};

    // Generate 3 rotations
    squares[1] = rotate(squares[0]);
    squares[2] = rotate(squares[1]);
    squares[3] = rotate(squares[2]);

    // Reflect the original and generate 3 more rotations
    MagicSquare reflected = reflect(squares[0]);
    squares[4] = reflected;
    squares[5] = rotate(squares[4]);
    squares[6] = rotate(squares[5]);
    squares[7] = rotate(squares[6]);

    return squares;
}

/**
 * @brief Prints a magic square in a 3x3 format.
 *
 * @param square The magic square to print.
 */
void print_square(const MagicSquare& square) {
    std::cout << square[0] << " " << square[1] << " " << square[2] << "\n";
    std::cout << square[3] << " " << square[4] << " " << square[5] << "\n";
    std::cout << square[6] << " " << square[7] << " " << square[8] << "\n";
    std::cout << "---------\n";
}
