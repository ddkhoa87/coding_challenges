```cpp
// lv-able
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