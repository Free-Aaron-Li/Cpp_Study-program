// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_3.hpp"

void Exercise_11_3::meaninglessFunction_1() {}
void Exercise_11_3::meaninglessFunction_2() {}
void Exercise_11_3::meaninglessFunction_3() {}
void Exercise_11_3::meaninglessFunction_4() {}

void Exercise_11_3::exercise_11_16() {
    std::map<std::string, int> val{{"hello", 0}};
    auto                       map_iter = val.begin();
    map_iter->second                    = 1;
    std::cout << map_iter->first << " " << map_iter->second << "\n";
}
