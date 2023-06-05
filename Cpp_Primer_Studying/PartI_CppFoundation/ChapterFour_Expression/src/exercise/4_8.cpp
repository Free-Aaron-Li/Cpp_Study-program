// This file is part of Cpp_Workspace project.
// This program is called:4_8.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_8.hpp"

void
Exercise_4_8::meaninglessFunction_1() {}

void
Exercise_4_8::meaninglessFunction_2() {}

void
Exercise_4_8::exercise_4_25() {
    int q = 0b01110001;
    std::cout << std::bitset<32>(~q << 6) << '\n';
}
