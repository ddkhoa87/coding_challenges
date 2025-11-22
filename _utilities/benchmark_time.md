```cpp
#include <chrono>

void benchmark() {
    using namespace std::chrono;
    
    constexpr uint N = 100;
    auto start = steady_clock::now();
    
    for (auto i = 0; i < N; ++i) {
        lv("test");
    }
    
    auto end = steady_clock::now();
    auto total_ns = duration_cast<nanoseconds>(end - start).count();
    
    std::cout << "Avg per call: " << (total_ns / N) << " ns\n";
}
```