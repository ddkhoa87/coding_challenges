`constexpr` function must initialize all of its local variables.

`std::ranges` funtions can be executed at compile time when possible.
Be mindful with the number of possible `::next_permutation` iterations. It might exceed compiling limitation.

On MS Windows, before `/std:c++20`, `cl.exe` does not allowed constexpr functions to use local iterating variables, i.e., `[]` and `for (const auto& x : arr)`.

**Common mistakes**

Wrong index when rotating, reflecting, and generating magic squares.
Half test cases passed and half failed. This hints certain magic squares were invalid.
