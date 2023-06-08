// This file is part of Cpp_Primer_Studying project.
// This program is called:5_6.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "5_6.hpp"

void Exercise_5_6::exercise_5_23() {
    int number_1, number_2;

    std::cout << "请输入两个整数：";
    std::cin >> number_1 >> number_2;
    std::cout << "二者之比为：" << number_1 / number_2 << "\n";
}

void Exercise_5_6::exercise_5_24() {
    int number_1, number_2;

    std::cout << "请输入两个整数：";
    std::cin >> number_1 >> number_2;
    if (number_1 == 0) throw std::runtime_error("除数为0");
    std::cout << "二者之比为：" << number_1 / number_2 << "\n";
}

void Exercise_5_6::exercise_5_25() {
    int number_1, number_2;

    std::cout << "请输入两个整数：";
    while (std::cin >> number_1 >> number_2) {
        try {
            if (number_1 == 0) throw std::runtime_error("除数为0");
            std::cout << "二者之比为：" << number_1 / number_2 << "\n";
            if (std::cin.get() == '\n') break;
        }
        catch (std::runtime_error &error) {
            std::cout << "是否需要输入新数？";
            char option;
            std::cin >> option;
            if (!option || option == 'n' || option == 'N') break;
            std::cout << "新数为：";
        }
    }
}
