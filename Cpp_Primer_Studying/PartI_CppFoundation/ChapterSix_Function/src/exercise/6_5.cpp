// This file is part of Cpp_Primer_Studying project.
// This program is called:6_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "6_5.hpp"

void Exercise_6_5::meaninglessFunction_1() {}
void Exercise_6_5::meaninglessFunction_2() {}

std::string exercise_42_sub(size_t ctr, const std::string &word, const std::string &ending ="s") {
    return ((ctr > 1) ? word + ending : word);
}
void Exercise_6_5::exercise_6_42() {
    std::cout<<exercise_42_sub(2,"success","es")<<"\n";
    std::cout<<exercise_42_sub(2,"failure")<<"\n";
}
