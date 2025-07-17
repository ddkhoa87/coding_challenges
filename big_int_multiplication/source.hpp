#pragma once

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class BigInt {
public:
    BigInt() = default;
    BigInt(int n) {
        if (0 > n) {
            throw std::invalid_argument("Input value cannot be negative");
        }
        do {
            digits_.push_back(n % 10);
            n /= 10;
        } while (n);
    }

    
    size_t len() const { return digits_.length(); }
    
    bool is_zero() const {
        return (digits_.length() == 1) && (digits_[0] == 0);
    }
    
    bool is_one() const {
        return (digits_.length() == 1) && (digits_[0] == 1);
    }
    
    void print(std::ostream &os=std::cout) {
        // uint8_t will be converted to unsigned char and become invisible characters
        std::copy(digits_.rbegin(), digits_.rend(), std::ostream_iterator<int>(os));
        os << std::endl;
    }
    
    friend std::ostream& operator << (std::ostream &os, const BigInt &n) {
        std::copy(n.digits_.rbegin(), n.digits_.rend(), std::ostream_iterator<int>(os));
        return os;
    }

    bool operator == (const BigInt &r) const {
        return this->digits_ == r.digits_;
    }
    
    BigInt& operator *= (const BigInt& r) {
        BigInt &l = *this;
        
        if (l.is_zero() || r.is_zero()) {
            l = BigInt(0);
            return l;
        }
        if (r.is_one()) {
            return l;
        }
        if (l.is_one()) {
            l = r;
            return l;
        }
        
        std::vector<int> temp(l.len() + r.len(), 0);
        
        for (int i = 0; i < l.len(); ++i)
            for (int j = 0; j < r.len(); ++j) {
                temp[i + j] += l.digits_[i] * r.digits_[j];
            }
        
        char carry = 0;
        l.digits_.resize(temp.size(), 0);
        for (int i = 0; i < temp.size(); ++i) {
            const int sum = carry + temp[i];
            l.digits_[i] = sum % 10;
            carry = sum / 10;
        }
        
        for (int i = l.len() - 1; (0 < i) && (0 == l.digits_[i]); --i) {
            l.digits_.pop_back();
        }
        return l;
    }
    
private:
    std::string digits_;
};