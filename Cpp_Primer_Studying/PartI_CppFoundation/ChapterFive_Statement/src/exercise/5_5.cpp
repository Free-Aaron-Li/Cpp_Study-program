// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:5_5.
// If there are no special instructions, this file is used as an exercise and test file.

#include "5_5.hpp"

void Exercise_5_5::exercise_5_20() {
    std::string word, same_word;

    std::cout << "请输入单词集合：";
    while (std::cin >> word) {
        if (word == same_word) {
            std::cout << "出现连续两次重复的单词，单词为：" << same_word << "\n";
            break;
        }
        same_word = word;
        if (std::cin.get() == '\n') {
            std::cout << "抱歉 ，没有重复单词！";
            break;
        }
    }
}

void Exercise_5_5::exercise_5_21() {
    std::string word, same_word;

    std::cout << "请输入单词集合：";
    while (std::cin >> word) {
        if (std::isupper(word[0])) {
            if (word == same_word) {
                std::cout << "出现连续两次重复的单词，单词为：" << same_word << "\n";
                break;
            }
            same_word = word;
        } else {
            continue;
        }
        if (std::cin.get() == '\n') {
            std::cout << "抱歉 ，没有重复单词！";
            break;
        }
    }
}

int get_size() { return 2; }

void Exercise_5_5::exercise_5_22() {
    int sz;

    do { sz = get_size(); } while (sz <= 0);
}
