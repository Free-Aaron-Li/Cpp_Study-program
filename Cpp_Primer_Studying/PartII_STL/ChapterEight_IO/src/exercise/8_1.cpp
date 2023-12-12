// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_1.
// If there are no special instructions, this file is used as an exercise and test file.

#include "8_1.hpp"

void Exercise_8_1::meaninglessFunction_1() {}
void Exercise_8_1::meaninglessFunction_2() {}

std::istream& exercise_1_sub(std::istream& istream) {
    std::string str;
    while (istream >> str)
        std::cout << str << "\n";
    istream.clear();
    return istream;
}

void Exercise_8_1::exercise_8_1() { /* redirect std::cin */
    exercise_1_sub(std::cin);
}
