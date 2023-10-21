// This file is part of Cpp_Primer_Studying project.
// This program is called:10_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "10_3.hpp"

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    /** Returns an iterator to the first position after the unrepeated region */
    auto end_unique = std::unique(words.begin(), words.end());
    /** delete repeated element */
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
    auto end_target_sequence = std::partition(vector.begin(), vector.end(), string_greater_than_four);
    vector.erase(end_target_sequence, vector.end());
    for (const auto &c : vector) {
        std::cout << c << " ";
    }
}

void Exercise_10_3::exercise_10_14() {
    int  a = 10, b = 20;
    auto c = [](const int &a, const int &b) -> int { return a + b; };
    std::cout << "a + b = " << c(a, b) << "\n";
}

void Exercise_10_3::exercise_10_15() {
    int  a = 10, b = 20;
    auto c = [a, b](const int &c) -> int { return a + b + c; };
    std::cout << "a + b + c = " << c(30) << "\n";
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    std::stable_sort(
      words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
    /** Gets the iterator pointed to by the first element that satisfies size()>=sz */
    auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a) { return a.size() >= sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_16() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies(words, 4);
}

void Exercise_10_3::exercise_10_17() {
    std::vector<SalesData_pr> data;
    data.emplace_back("01", 12, 12.0);
    data.emplace_back("01000000", 12, 12.0);
    data.emplace_back("0100", 12, 12.0);
    data.emplace_back("01000", 12, 12.0);
    data.emplace_back("010000", 12, 12.0);
    std::stable_sort(data.begin(), data.end(), [](const SalesData_pr &data_1, const SalesData_pr &data_2) -> bool {
        return data_1.isbn() < data_2.isbn();
    });
    std::for_each(data.begin(), data.end(), [](const SalesData_pr &data) { print(std::cout, data) << "\n"; });
}

void biggies_2(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    std::stable_sort(
      words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
    /** Gets the iterator pointed to by the first element that satisfies size()>=sz */
    auto wc = std::partition(words.begin(), words.end(), [sz](const std::string &s) -> bool { return s.size() < sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_18() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies_2(words, 4);
}

void biggies_3(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    auto wc
      = std::stable_partition(words.begin(), words.end(), [sz](const std::string &s) -> bool { return s.size() < sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_19() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies_3(words, 4);
}

void Exercise_10_3::exercise_10_20() {
    std::vector<std::string> data{"hello,is", "good", "word", "is,right", "?"};
    auto count = std::count_if(data.begin(), data.end(), [](const std::string &s) -> bool { return s.size() > 6; });
    std::cout << count << "\n";
}

void Exercise_10_3::exercise_10_21() {
    int  i         = 10;
    auto i_is_zero = [i]() mutable -> bool {
        while (i != 0)
            --i;
        if (i == 0)
            return true;
        else
            return false;
    };

    std::cout << "i is zero? " << (i_is_zero() ? "yes" : "no") << "\n";
}
