// This file is part of Cpp_Primer_Studying project.
// This program is called:4_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_4.hpp"

void Exercise_4_4::meaninglessFunction_1() {}
void Exercise_4_4::meaninglessFunction_2() {}
void Exercise_4_4::meaninglessFunction_3() {}

void Exercise_4_4::exercise_4_13() {
    int    i;
    double d;
    d = i = 3.5;
    std::cout << i << " " << d << "\n";
    i = d = 3.5;
    std::cout << i << " " << d << "\n";
}
