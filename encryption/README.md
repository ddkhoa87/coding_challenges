https://www.hackerrank.com/challenges/encryption/problem?isFullScreen=true

**Approach and STL functions**

1. Sanitize
    + `remove`-`erase` idiom
      + `s.erase(std::remove(s.begin(), s.end(), ' '), s.end())`
      + `s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end())`
    + `stringstream` parsing
2. Determine encryption matrix dimension
    + `math.h` `floor` and `ceil`
3. Output
    + iterating input matrix column-wise
    + appending output string incrementally *only if a character is within the input bound*, (check the pitfalls below), `reserve` space to avoid reallocation.
    + add space to the output at the end of each column of the input *only if this is not the last column*.

**Pitfalls**
+ "feedthedog" -> rows==3, cols==4, when j==2 and i==2, index==10 which is out of the string. Let L is the length of the sanitized string, check for `index < L`.
+ meanwhile, there needs to be space in the output string except for after the last input column.
+ Either `floor == ceil` or `floor + 1 == ceil`

**Benchmarking**

+ stringstream parsing slighly faster for short strings
+ string reserve vs resize are not clearly better than the other

+ stringstream parsing

    real    0m0.116s
    user    0m0.031s
    sys     0m0.047s

    real    0m0.116s
    user    0m0.046s
    sys     0m0.046s

    real    0m0.123s
    user    0m0.000s
    sys     0m0.140s

    real    0m0.117s
    user    0m0.047s
    sys     0m0.015s

    real    0m0.133s
    user    0m0.015s
    sys     0m0.062s

+ remove-erase idiom

    real    0m0.238s
    user    0m0.031s
    sys     0m0.062s

    real    0m0.129s
    user    0m0.015s
    sys     0m0.077s

    real    0m0.117s
    user    0m0.031s
    sys     0m0.046s

    real    0m0.138s
    user    0m0.015s
    sys     0m0.063s

    real    0m0.153s
    user    0m0.031s
    sys     0m0.061s

+ string reserve and append

    real    0m0.243s
    user    0m0.015s
    sys     0m0.078s

    real    0m0.123s
    user    0m0.031s
    sys     0m0.030s

    real    0m0.135s
    user    0m0.015s
    sys     0m0.077s

    real    0m0.153s
    user    0m0.000s
    sys     0m0.062s

    real    0m0.126s
    user    0m0.031s
    sys     0m0.047s

+ string resize and assign

    real    0m0.219s
    user    0m0.031s
    sys     0m0.047s

    real    0m0.132s
    user    0m0.046s
    sys     0m0.046s

    real    0m0.129s
    user    0m0.000s
    sys     0m0.094s

    real    0m0.110s
    user    0m0.046s
    sys     0m0.030s

    real    0m0.132s
    user    0m0.015s
    sys     0m0.031s
