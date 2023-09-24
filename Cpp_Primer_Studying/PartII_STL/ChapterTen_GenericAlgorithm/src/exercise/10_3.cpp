// This file is part of Cpp_Primer_Studying project.
// This program is called:10_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "10_3.hpp"

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string &str_1, const std::string &str_2) { return str_1.size() < str_2.size(); }

void Exercise_10_3::exercise_10_11() {
    std::vector<std::string> vector{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vector);
    std::stable_sort(vector.begin(), vector.end(), isShorter);
    for (const auto &c : vector) {
        std::cout << c << " ";
    }
}

bool compareIsbn(const SalesData_pr &data_1, const SalesData_pr &data_2) { return data_1.isbn() < data_2.isbn(); }

void Exercise_10_3::exercise_10_12() {
    std::vector<SalesData_pr> vector;
    vector.emplace_back("01", 12, 12.0);
    vector.emplace_back("01000000", 12, 12.0);
    vector.emplace_back("0100", 12, 12.0);
    vector.emplace_back("01000", 12, 12.0);
    vector.emplace_back("010000", 12, 12.0);
    std::stable_sort(vector.begin(), vector.end(), compareIsbn);
    for (const auto &c : vector) {
        print(std::cout, c) << "\n";
    }
}

bool string_greater_than_four(const std::string &str) { return str.size() >= 5; }

void Exercise_10_3::exercise_10_13() {
    std::vector<std::string> vector{"hello", "is", "good", "word", "is", "right", "?"};
    auto                     end_target_sequence = std::partition(vector.begin(), vector.end(), string_greater_than_four);
    vector.erase(end_target_sequence, vector.end());
    for (const auto &c : vector) {
        std::cout << c << " ";
    }
}
