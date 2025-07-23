#include <iostream>

#include "generate_magic_square.hpp"
#include "min_cost_to_magic_square.hpp"

int main() {
    vector<vector<int>> s{{4, 5, 8}, {2, 4, 1}, {1, 9, 7}};

    cout << formingMagicSquare(s) << endl;

    return 0;
}

