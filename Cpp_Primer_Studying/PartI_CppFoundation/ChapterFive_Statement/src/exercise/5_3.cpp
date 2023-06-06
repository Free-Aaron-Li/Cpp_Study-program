// This file is part of Cpp_Primer_Studying project.
// This program is called:5_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "5_3.hpp"

void Exercise_5_3::meaninglessFunction_1() {}
void Exercise_5_3::meaninglessFunction_2() {}

void Exercise_5_3::exercise_5_5() {
    /**
     * 规定：<br>
     * 成绩实行百分制，小于60分成绩为F，每10分为一档，90~100为A，80~90位B，70~80位C，60~70位D。<br>
     * 100分为A++，分数的余数为7~9为优，加上“+”；分数的余数为1~3为差，加上“-”。
     */
    std::cout << "请输入一个分数（100以内的正整数）：";
    unsigned int             achievement;                            /* 定义成绩 */
    std::string              result;                                 /* 成绩等级 */
    std::vector<std::string> grades{"F", "D", "C", "B", "A", "A++"}; /* 定义等级 */
    auto                     iter = grades.begin();                  /* 定义迭代器 */
Start:
    std::cin >> achievement;

    if (achievement > 100) {
        std::cout << "你输入的成绩有误！请重新输入：";
        goto Start;
    }
    else if (achievement == 100) result = *(iter + 5);
    else if (achievement < 60) result = *iter;
    else {
        decltype(achievement) number = (achievement - 50) / 10;
        if (achievement % 10 >= 7) result = *(iter + number) + "+";
        else if (achievement % 10 <= 3) result = *(iter + number) + "-";
        else result = *(iter + number);
    }

    std::cout << "你的成绩等级为：" << result << "\n";
}

void Exercise_5_3::exercise_5_6() {
    std::cout << "请输入一个分数（100以内的正整数）：";
    unsigned int             achievement;                            /* 定义成绩 */
    std::string              result;                                 /* 成绩等级 */
    std::vector<std::string> grades{"F", "D", "C", "B", "A", "A++"}; /* 定义等级 */
    auto                     iter = grades.begin();                  /* 定义迭代器 */
Start:
    std::cin >> achievement;

    if (achievement > 100) {
        std::cout << "你输入的成绩有误！请重新输入：";
        goto Start;
    }

    decltype(achievement) number = (achievement - 50) / 10;
    (achievement >= 100) ? (result = *(iter + 5))
                         : ((achievement > 60) ? (result = *(iter + number)) : (result = *iter));

    (achievement >= 60)
      ? ((achievement % 10 >= 7) ? (result += "+") : ((achievement % 10 <= 3) ? (result += "-") : result))
      : result;
    std::cout << "你的成绩等级为：" << result << "\n";
}
