// This file is part of Cpp_Primer_Studying project.
// This program is called:7_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "7_5.hpp"

void Exercise_7_5::meaninglessFunction_1() {}
void Exercise_7_5::meaninglessFunction_2() {}
void Exercise_7_5::meaninglessFunction_3() {}
void Exercise_7_5::meaninglessFunction_4() {}
void Exercise_7_5::meaninglessFunction_5() {}
void Exercise_7_5::meaninglessFunction_6() {}
void Exercise_7_5::meaninglessFunction_7() {}
void Exercise_7_5::meaninglessFunction_8() {}
void Exercise_7_5::meaninglessFunction_9() {}

void Exercise_7_5::exercise_7_41() {
    std::string  str = "123";
    SalesData_pr data;
    SalesData_pr data1(str);
    SalesData_pr data2(std::cin);
}

class NoDefault {
 public:
    NoDefault(int){};
};

class C {
 public:
    C() : _noDefault(0){};

 private:
    NoDefault _noDefault;
};

void Exercise_7_5::exercise_7_43() {
    C c;
    int a=10;
}
