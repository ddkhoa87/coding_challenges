#include <cstdint>

std::uint64_t exp(const std::uint64_t x, std::uint64_t n) {
    if (0 == n) {
        return 1;
    }
    
    std::uint64_t running_power{x};
    std::uint64_t res{1};

    while (n) {
        if (n % 2 == 1) {
            res *= running_power;
        }
        
        if (n /= 2) {
            running_power *= running_power;
        }
    }

    return res;
}
