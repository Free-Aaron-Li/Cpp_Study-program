// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:9_6.
// If there are no special instructions, this file is used as an exercise and test file.

#include "9_6.hpp"

std::string exercise_52_sub(const std::string& str) {
    std::stack<char> stk;
    bool             flag = false;
    for (auto const& c : str) {
        if (c == '(') {
            flag = true;
            continue;
        } else if (c == ')')
            flag = false;

        if (flag)
            stk.push(c);
    }

    std::string result;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return std::string(result.rbegin(), result.rend());
}


void Exercise_9_6::exercise_9_52() {
    std::string str = "hello this is (world) !";
    std::cout << exercise_52_sub(str);
}
