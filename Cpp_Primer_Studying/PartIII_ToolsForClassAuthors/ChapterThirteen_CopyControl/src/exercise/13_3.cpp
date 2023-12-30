// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "13_3.hpp"

void
Exercise_13_3::meaninglessFunction_1() {}

void
Exercise_13_3::meaninglessFunction_2() {}

void
Exercise_13_3::exercise_13_30() {
    Like_value_HasPtr lhs("lhs"), rhs("rhs");
    lhs.setI(1);
    rhs.setI(2);
    swap(lhs, rhs);
}

void
Exercise_13_3::exercise_13_31() {
    std::vector<Like_value_HasPtr> v;
    for (int i = 0; i < 17; ++i)
        v.emplace_back(std::to_string(i));
    std::sort(v.begin(), v.end());  // need to define the < operator
    for (const auto& val : v) {
        std::cout << *val << " ";
    }
}
