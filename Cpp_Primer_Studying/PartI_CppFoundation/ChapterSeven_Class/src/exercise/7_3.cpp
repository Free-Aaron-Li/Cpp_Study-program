// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:7_3.
// If there are no special instructions, this file is used as an exercise and test file.

#include "7_3.hpp"

void Exercise_7_3::meaninglessFunction_1() {}
void Exercise_7_3::meaninglessFunction_2() {}
void Exercise_7_3::meaninglessFunction_3() {}
void Exercise_7_3::meaninglessFunction_4() {}
void Exercise_7_3::meaninglessFunction_5() {}
void Exercise_7_3::meaninglessFunction_6() {}
void Exercise_7_3::meaninglessFunction_7() {}

void Exercise_7_3::exercise_7_27() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << '\n';
    myScreen.display(std::cout);
    std::cout << "\n";
}

class Y;

class X {
 public:
    Y *y;
};

class Y {
 public:
    X x;
};
void Exercise_7_3::exercise_7_31() {
    X x{};
    Y y{};
}
