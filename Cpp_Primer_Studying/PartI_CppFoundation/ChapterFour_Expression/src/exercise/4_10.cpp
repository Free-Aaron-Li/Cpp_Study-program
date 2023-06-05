// This file is part of Cpp_Primer_Studying project.
// This program is called:4_10.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_10.hpp"

void Exercise_4_10::meaninglessFunction_1() {}

void Exercise_4_10::exercise_4_31() {
    std::vector<int>            ivec(10, 0);
    std::vector<int>::size_type cnt = ivec.size();
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) { ivec[ix] = cnt; }
    for (auto c : ivec) { std::cout << c << " "; }

    std::cout << "\n改为后置版本：\n";
    for (auto &c : ivec) { c = 0; }
    cnt = ivec.size() + 1;
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) { ivec[ix] = cnt - 1; }
    for (auto c : ivec) { std::cout << c << " "; }
}

void Exercise_4_10::exercise_4_33() {
    bool someValue = true;
    int  x = 10, y = 20;
    // int  result = (someValue ? ++x, ++y : --x), (--y);
    // std::cout << "\n" << result << "\n";
}
