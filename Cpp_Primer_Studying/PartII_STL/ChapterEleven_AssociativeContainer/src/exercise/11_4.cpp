// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_4'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_4.hpp"

void
Exercise_11_4::meaninglessFunction_1() {}

//------------------------------------------------------------------------------------------------

void
Exercise_11_4::exercise_11_38(const std::vector<std::string>& data) {
    std::unordered_map<std::string, std::size_t> word_count{};
    std::string                                  word;
    for (const auto& val : data) {
        ++word_count[val];
    }

    for (const auto& val : word_count) {
        std::cout << " word: \"" << val.first << "\" , has " << val.second << ((val.second > 1) ? " times" : " time")
                  << "\n";
    }
}

//------------------------------------------------------------------------------------------------
