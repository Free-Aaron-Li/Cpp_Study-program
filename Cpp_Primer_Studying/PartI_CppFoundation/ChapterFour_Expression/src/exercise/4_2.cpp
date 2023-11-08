// This file is part of Cpp_Primer_Studying project.
// This program is called:4_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_2.hpp"

void Exercise_4_2::meaninglessFunction_3() {}

void Exercise_4_2::exercise_4_4() {
    int a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    std::cout << "the a is " << a << "\n";
}

void Exercise_4_2::exercise_4_6() {
    std::cout << "请输入一个整数：";
    int number = 0;
    std::cin >> number;
    if (number % 2 == 0)
        std::cout << "该整数为偶数";
    else
        std::cout << "该整数为奇数";
}

void Exercise_4_2::exercise_4_7() {
    std::cout << "超出short类型的最大数值32767:\n";
    short short_number = 32767;
    ++short_number;
    std::cout << "short_number is " << short_number << "\n";

    std::cout << "超出long类型的最大数值4294967295:\n";
    unsigned int unsigned_int_number = 4294967295;
    ++unsigned_int_number;
    std::cout << "unsigned_int_number is " << unsigned_int_number << "\n";

    std::cout << "超出long类型的最大数值65535:\n";
    unsigned short unsigned_short_number = 65535;
    ++unsigned_short_number;
    std::cout << "unsigned_short_number is " << unsigned_short_number << "\n";
}