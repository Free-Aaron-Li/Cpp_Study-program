// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_1.hpp"

void Exercise_11::meaninglessFunction_1() {}
void Exercise_11::meaninglessFunction_2() {}
void Exercise_11::exercise_11_3() {
    std::map<std::string, std::size_t> word_count{};
    std::string                        word{};
    while (std::cin >> word)
        ++word_count[word];
    std::cout << "\n";
    for (const auto& val : word_count) {
        std::cout << "The \"" << val.first << "\" have " << ((val.second > 1) ? " time" : " times") << "\n";
    }
}
