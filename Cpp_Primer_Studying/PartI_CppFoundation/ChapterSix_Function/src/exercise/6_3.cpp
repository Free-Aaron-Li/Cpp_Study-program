// This file is part of Cpp_Primer_Studying project.
// This program is called:6_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "6_3.hpp"

void Exercise_6_3::meaninglessFunction_1() {}
void Exercise_6_3::meaninglessFunction_2() {}
void Exercise_6_3::meaninglessFunction_3() {}
void Exercise_6_3::meaninglessFunction_4() {}
void Exercise_6_3::meaninglessFunction_5() {}

void exercise_23_sub(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (begin != end) {
        std::cout << *begin << " ";
        return exercise_23_sub(++begin, end);
    } else {
        std::cout << "\n";
        return;
    }
}
void Exercise_6_3::exercise_6_33() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6};
    exercise_23_sub(vector.begin(), vector.end());
}

std::string array[10] = {"this", "is", "good", "time", "!", "so", "you", "think", "it", "?"};

std::string (*function())[10] { return &array; }

void Exercise_6_3::exercise_6_36() {
    std::string(*p)[10] = function();
    for (const auto& c : *p) {
        std::cout << c << " ";
    }
}

/* 使用类型别名 */
// 方式①
typedef std::string arr[10];
// 方式②
using arr = std::string[10];

arr* function_1() { return &array; }

/* 使用尾置返回类型 */
auto function_2() -> std::string (*)[10] { return &array; };

/* 使用decltype关键字 */
decltype(array)* function_3() { return &array; }

void Exercise_6_3::exercise_6_37() {
    std::string(*p1)[10] = function_1();
    for (const auto& c : *p1) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    std::string(*p2)[10] = function_2();
    for (const auto& c : *p2) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    std::string(*p3)[10] = function_3();
    for (const auto& c : *p3) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}

int odd[]  = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd)& arrPtr(int i) { return (i % 2) ? odd : even; }

void Exercise_6_3::exercise_6_38() {
    for (const auto& c : arrPtr(2)) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}
