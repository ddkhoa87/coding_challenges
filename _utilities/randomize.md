**Fixed seed sequence**
(C++23)

```c++
#include <random>

std::seed_seq seq{1,2,3,4};  // Reproducible
std::mt19937 gen(seq); // or fixed seed std::mt19937 gen(12345);
std::uniform_int_distribution<int> dist(0, 99);

for (int i = 0; i < N; ++i)
    std::cout << dist(gen) << " ";
```

**Random seed***

(C++20, 23)
```c++
std::random_device rd;          // seeds RNG with real entropy
std::mt19937 gen(rd());         // high-quality PRNG Mersenne Twister engine
std::uniform_int_distribution<int> dist(0, 99);
```