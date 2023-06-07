// This file is part of Cpp_Primer_Studying project.
// This program is called:5_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "5_4.hpp"

void Exercise_5_4::meaninglessFunction_1() {}

void Exercise_5_4::exercise_5_14() {
    unsigned int number = 1, max_number = 1;
    std::string  element, same_string, max_number_string;

    std::cout << "请输入一串字母：";          /* TODO 23-6-7 无法对单词进行全局统计 */
    while (std::cin >> element) {
        if (element == same_string) ++number; /* 相同单词，增加单词数 */
        else {
            if (number > max_number) {        /* 新的最大相同单词数 */
                max_number        = number;
                max_number_string = same_string;
            }
            number = 1;
        }
        same_string = element;
        if (std::cin.get() == '\n') break;
    }

    if (number > max_number) {
        max_number        = number;
        max_number_string = same_string;
    }

    (max_number > 1) ? (
      std::cout << "the max number of word is: ' " << max_number_string << " ' and this number is " << max_number
                << "\n")
                     : (std::cout << "sorry! no max number of word.");
}
