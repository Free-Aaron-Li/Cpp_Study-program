// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_1.
// If there are no special instructions, this file is used as an exercise and test file.

#include "6_1.hpp"

void Exercise_6_1::meaninglessFunction_1() {}
void Exercise_6_1::meaninglessFunction_2() {}
void Exercise_6_1::meaninglessFunction_3() {}
void Exercise_6_1::meaninglessFunction_4() {}
void Exercise_6_1::meaninglessFunction_5() {}

/* 获取value的阶乘 */
int fact(int value) {
    int result = 1;
    while (value > 1) result *= value--;
    return result;
}

void Exercise_6_1::exercise_6_3() {
    std::cout << "请输入你想要的阶乘数：";
    int number;
    std::cin >> number;
    int outcome = fact(number);
    std::cout << "该阶乘数的结果为：" << outcome << "\n";
}

/* 获得实参的绝对值 */
int get_absoluteValue(int value) {
    if (value >= 0) return value;
    else return -value;
}

void Exercise_6_1::exercise_6_5() {
    std::cout << "请输入一个整数：";
    int number;
    std::cin >> number;
    int outcome = get_absoluteValue(number);
    std::cout << "该整数的绝对值为：" << outcome << "\n";
}

int exercise_6_6_sub(int value /* 形参 */) {
    int        i = 3;         /* 局部变量 */
    static int q = i + value; /* 局部静态变量 */
    return ++q;
}

void Exercise_6_1::exercise_6_6() {
    int value = 2;
    std::cout << "first call sub function,q is " << exercise_6_6_sub(value) << "\n";
    std::cout << "second call sub function,q is " << exercise_6_6_sub(value) << "\n";
}

int exercise_6_7_sub() {
    static int value = 0;
    return value++;
}

void Exercise_6_1::exercise_6_7() {
    std::cout << "first call : " << exercise_6_7_sub() << "\n";
    std::cout << "second call : " << exercise_6_7_sub() << "\n";
}
