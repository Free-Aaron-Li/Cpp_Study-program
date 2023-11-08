// This file is part of Cpp_Primer_Studying project.
// This program is called:6_6.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "6_6.hpp"

void Exercise_6_6::meaninglessFunction_1() {}
void Exercise_6_6::meaninglessFunction_2() {}
void Exercise_6_6::meaninglessFunction_3() {}
void Exercise_6_6::meaninglessFunction_4() {}

void f() { std::cout << "f()\n"; }

void f(int a) { std::cout << "f(int)\n"; }

void f(int a, int b) { std::cout << "f(int,int)\n"; }

void f(double c, double = 3.14) { std::cout << "f(double,double)\n"; }

void Exercise_6_6::exercise_6_51() {
    // f(2.56,42);     //call of overloaded ‘f(double, int)’ is ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}
