Implement `exponent(const int x, const int n)` with only basic operators: multiplication, division, odd/even number check.

Based on binary (base-2) representation or integers, any non-negative number can be expressed as a sum of powers of 2:

| 1 | 2 | 4 | 8 | 16 |           |
|:-:|:-:|:-:|:-:|:--:|:----------|  
|   |   |   |   |    |           |
| 1 |   |   |   |    | 1         |
| 2 | 1 |   |   |    | 2         |
| 3 | 1 |   |   |    | 1 + 2     |
| 4 | 2 | 1 |   |    | 4         |
| 5 | 2 | 1 |   |    | 1 + 4     |
| 6 | 3 | 1 |   |    | 2 + 4     |
| 7 | 3 | 1 |   |    | 1 + 2 + 4 |
| 8 | 4 | 2 | 1 |    | 8         |
| 9 | 4 | 2 | 1 |    | 1 + 8     |

If we keep halving the exponent n, every time n is *odd*, we include the corresponding x^(power of 2). Exp:
+ x^7 == x^1 * x^2 * x^4 == x^(1 + 2 + 4)
+ x^7 == x^1 * x^4
