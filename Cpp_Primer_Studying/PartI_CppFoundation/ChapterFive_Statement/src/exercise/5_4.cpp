// This file is part of Cpp_Primer_Studying project.
// This program is called:5_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "5_4.hpp"

void Exercise_5_4::meaninglessFunction_1() {}

void Exercise_5_4::exercise_5_14() {
    /* TODO 23-6-7 当前的求解思路无法解决，留在后续使用数据结构解决。
     * */
}

void Exercise_5_4::exercise_4_16() {
    int value = 10;

    std::cout << "这是使用for循环语句输出0~9：";
    for (int i = 0; i < value; ++i) { std::cout << i << " "; }

    std::cout << "\n这是使用while循环改写：";
    int i = 0;
    while (i < value) {
        std::cout << i << " ";
        ++i;
    }

    std::cout << "\n这是使用while循环输出一串字符：";
    std::string string       = "this is good time!";
    auto        string_index = string.begin();
    while (string_index != string.end()) {
        std::cout << *string_index << " ";
        ++string_index;
    }

    std::cout << "\n这是使用for循环改写：";
    for (auto index = string.begin(); index != string.end(); ++index) std::cout << *index << " ";
}

void Exercise_5_4::exercise_5_17() { /* TODO 23-6-7 当前的求解思路无法解决，留给后续使用其他方法解决 */
}

void Exercise_5_4::exercise_5_19() {
    std::string string_1, string_2;

    do {
        std::cout << "Please enter two strings:";
        if (std::cin >> string_1 >> string_2)
            (string_1.size() >= string_2.size()) ? (std::cout << string_2 << "\n") : (std::cout << string_1 << "\n");
    } while (std::cin);
}
