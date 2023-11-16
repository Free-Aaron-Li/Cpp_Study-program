// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_1.hpp"

void
Exercise_11_1::meaninglessFunction_1() {}
void
Exercise_11_1::meaninglessFunction_2() {}
void
Exercise_11_1::exercise_11_3(const std::vector<std::string>& words) {
    std::map<std::string, std::size_t> word_count{};
    for (const auto& val : words) {
        ++word_count[val];
    }
    std::cout << "\n";
    for (const auto& val : word_count) {
        std::cout << "The \"" << val.first << "\" have " << val.second << ((val.second > 1) ? " time" : " times")
                  << "\n";
    }
}
std::string
filter(std::string str) {
    std::string punctuation{"\"'`:*-_;,.?!()[]{}"};
    for (auto& val : str)
        if (val >= 'A' && val <= 'Z')
            val -= 'A' - 'a';
    size_t begin_position = str.find_first_not_of(punctuation);
    if (begin_position == std::string::npos)
        return "";
    size_t end_position = str.find_last_not_of(punctuation);
    return str.substr(begin_position, end_position - begin_position + 1);
}
void
Exercise_11_1::exercise_11_4(const std::vector<std::string>& words) {
    std::map<std::string, std::size_t> word_count{};
    for (auto& val : words) {
        ++word_count[filter(val)];
    }
    std::cout << "\n";
    for (const auto& val : word_count) {
        if (!val.first.empty())
            std::cout << "The \"" << val.first << "\" have " << val.second << ((val.second > 1) ? " time" : " times")
                      << "\n";
    }
}
