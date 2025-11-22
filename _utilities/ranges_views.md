### lv-able

```cpp
lpos = -2
vpos = -2

for (auto [i, ch] : s | std::views::enumerate)
    if 'l' == ch
        lpos = i
    else if 'v' == ch
        if lpos == i - 1
            return 0
        vpos = i
```

### Move zeros

```cpp
void moveZeroes(vector<int>& nums) {
    size_t i{0};
    for (const auto &v : nums)
        if (v) {
            nums[i] = v;
            ++i;
        }
        
    ranges::fill(nums | views::drop(i), 0);
}
```