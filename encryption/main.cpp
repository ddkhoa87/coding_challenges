#include <algorithm>
#include <sstream>
#include <string>

void stringstream_vs_idiom() {
    std::string s{"I am a string with spaces"};
    // std::stringstream ss{s};
    // ss.str();

    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
}

void reserve_vs_resize() {
    std::string s;

    s.reserve(20);
    for (auto i = 0; i < 20; ++i) {
        s += 'a';
    }

    // s.resize(20);
    // for (auto i = 0; i < 200; ++i) {
    //     s[i] = 'a';
    // }
}

int main() {
    reserve_vs_resize();   
    
    return 0;
}