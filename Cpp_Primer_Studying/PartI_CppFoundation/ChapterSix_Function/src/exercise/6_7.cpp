// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_7.
// If there are no special instructions, this file is used as an exercise and test file.

#include "6_7.hpp"

void
Exercise_6_7::meaninglessFunction_1() {}

int
exercise_54_sub(int, int);

void
Exercise_6_7::exercise_6_54() {
    std::vector<int (*)(int, int)> vector;
    using pa = decltype(exercise_6_54);
    typedef decltype(exercise_6_54) pb;
    typedef int                     (*pc)(int, int);

    std::vector<pa *> vector_a;
    std::vector<pb *> vector_b;
    std::vector<pc>   vector_c;
}

int
add(int a, int b) {
    return a + b;
}

int
subtract(int a, int b) {
    return a - b;
}

int
multiply(int a, int b) {
    return a * b;
}

int
divide(int a, int b) {
    return b != 0 ? (a / b) : 0;
}
void
Exercise_6_7::exercise_6_55() {
    std::vector<int (*)(int, int)> vector{add, subtract, multiply, divide};
    for (const auto &e : vector) {
        std::cout << e(4, 2) << "\n";
    }
}
