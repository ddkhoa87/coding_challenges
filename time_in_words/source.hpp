#pragma once

#include <array>
#include <iostream>
#include <string>
#include <sstream>

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

const std::string first_twenty[] {"", 
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const std::string ties[] {"", "", "twenty", "thirty", "forty", "fifty", "sixty"};


std::string number_to_text(int n) {
    if (n < 20) {
        return first_twenty[n];
    } else {
        return ties[n / 10] + " " + first_twenty[n % 10];
    }
}

std::string timeInWords(int h, int m) {
    std::stringstream ss;

    switch (m) {
    case 0:
        ss << number_to_text(h) << " o' clock";
        break;
    case 15:
        ss << "quarter past " << number_to_text(h);
        break;
    case 30:
        ss << "half past " << number_to_text(h);
        break;
    case 45:
        ss << "quarter to " << number_to_text(h+1);
        break;
    default:
        if (m < 30) {  // 0 < m < 30
            ss << number_to_text(m) << " minute";
            ss << ((m == 1) ? "" : "s");
            ss << " past " << number_to_text(h);
        } else {  // 30 < m < 60
            ss << number_to_text(60 - m) << " minute";
            ss << ((m == 1) ? "" : "s");
            ss << " to " << number_to_text(h+1);
        }
    }

    return ss.str();
}