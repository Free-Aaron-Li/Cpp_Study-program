// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_2.
// If there are no special instructions, this file is used as an exercise and test file.

#include "6_2.hpp"
void Exercise_6_2::meaninglessFunction_1() {}
void Exercise_6_2::meaninglessFunction_2() {}
void Exercise_6_2::meaninglessFunction_3() {}
void Exercise_6_2::meaninglessFunction_4() {}
void Exercise_6_2::meaninglessFunction_5() {}
void Exercise_6_2::meaninglessFunction_6() {}
void Exercise_6_2::meaninglessFunction_7() {}
void Exercise_6_2::meaninglessFunction_8() {}
void Exercise_6_2::meaninglessFunction_9() {}

void exercise_6_10_sub(int *first, int *second) {
    int temporary;
    temporary = *first;
    *first    = *second;
    *second   = temporary;
}

void Exercise_6_2::exercise_6_10() {
    int a = 10, b = 12;
    std::cout << "now a and b is : " << a << "," << b << "\n";
    exercise_6_10_sub(&a, &b);
    std::cout << "call exchange function and the new a and b is : " << a << "," << b << "\n";
}

void exercise_6_11_sub(int &target) { target = 0; }

void Exercise_6_2::exercise_6_11() {
    int a = 10;
    std::cout << "now a is : " << a << "\n";
    exercise_6_11_sub(a);
    std::cout << "call reset function,and the new a is : " << a << "\n";
}

void exercise_6_12_sub(int &first, int &second) {
    int temporary;
    temporary = first;
    first     = second;
    second    = temporary;
}

void Exercise_6_2::exercise_6_12() {
    int a = 10, b = 12;
    std::cout << "now a and b is : " << a << "," << b << "\n";
    exercise_6_12_sub(a, b);
    std::cout << "call exchange function and the new a and b is : " << a << "," << b << "\n";
}

int exercise_6_21_sub(int first, const int *second) {
    if (first > *second)
        return first;
    else
        return *second;
}

void Exercise_6_2::exercise_6_21() {
    int i = 2, j = 3;
    std::cout << "i and j is : " << i << "," << j << "\n";
    std::cout << "compare i and j , the max number is : " << exercise_6_21_sub(i, &j) << "\n";
}

void exercise_22_sub(int *&first, int *&second) {
    /* 错误的使用是：形参直接为int *first,int *second。
     * 其仅在该函数中修改二者地址，实参并未修改。需要使用二级指针或者引用指针方式修改
     * */
    int *temporary;
    temporary = first;
    first     = second;
    second    = temporary;
}

void Exercise_6_2::exercise_6_22() {
    int  i = 2, j = 3;
    int *pi = &i, *pj = &j;
    std::cout << "*pi and *pj is : " << *pi << "," << *pj << "\n";
    exercise_22_sub(pi, pj);
    std::cout << "exchange i and j pointer,now *pi and *pj is : " << *pi << "," << *pj << "\n";
}

void exercise_23_sub_1(const int *array, size_t size) {
    for (size_t i = 0; i != size; ++i)
        std::cout << *array++ << " ";
}

void exercise_23_sub_2(const int *begin, const int *end) {
    while (begin != end)
        std::cout << *begin++ << " ";
}

void Exercise_6_2::exercise_6_23() {
    int i = 0, j[2] = {0, 1};
    std::cout << "method1 is :\n";
    exercise_23_sub_1(j, std::end(j) - std::begin(j));
    std::cout << "\nmethod2 is :\n";
    exercise_23_sub_2(std::begin(j), std::end(j));
}

int exercise_27_sub(std::initializer_list<int> list) {
    int result = 0;
    for (auto &elem : list)
        result += elem;
    return result;
}

void Exercise_6_2::exercise_6_27() {
    std::cout << "initializer_list elements is : 2,3,4. the sum of these elements is : " << exercise_27_sub({2, 3, 4})<<"\n";
}
