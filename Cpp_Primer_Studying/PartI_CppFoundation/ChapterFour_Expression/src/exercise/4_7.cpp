// This file is part of Cpp_Primer_Studying project.
// This program is called:4_7.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_7.hpp"

void Exercise_4_7::meaninglessFunction_1() {}

void Exercise_4_7::meaninglessFunction_2() {}

void Exercise_4_7::exercise_4_21() {
    std::vector<int> vector{-1, 1, 3, 4, 5, 6, 7, 8, 10, 23, 44};
    for (auto c : vector) {
        std::cout << ((c % 2 == 0) ? c : c * 2) << " ";
    }
}

void Exercise_4_7::exercise_4_22() {
    std::cout << "请输入一个分数：";
    int number;
    std::cin >> number;
    std::cout << "方式一：\n";
    std::string grade
      = (number >= 90) ? "high pass" : ((number > 75) ? "pass" : ((number >= 60) ? "low pass" : "fail"));
    std::cout << "该分数的成绩应该为：" << grade << "\n";

    std::cout << "方式二：\n";
    if (number >= 90)
        grade = "high pass";
    else if (number > 75)
        grade = "pass";
    else if (number >= 60)
        grade = "low pass";
    else
        grade = "fail";

    std::cout << "该分数的成绩应该为：" << grade << "\n";
}
