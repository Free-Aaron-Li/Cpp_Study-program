// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:7_5.
// If there are no special instructions, this file is used as an exercise and test file.

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
void Exercise_7_5::meaninglessFunction_10() {}
void Exercise_7_5::meaninglessFunction_11() {}
void Exercise_7_5::meaninglessFunction_12() {}
void Exercise_7_5::meaninglessFunction_13() {}
void Exercise_7_5::meaninglessFunction_14() {}
void Exercise_7_5::meaninglessFunction_15() {}


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

void Exercise_7_5::exercise_7_43() { C c; }

class Debug {
 private:
    bool _hw;    /* 硬件错误 */
    bool _io;    /* io错误 */
    bool _other; /* 其他错误 */

 public:
    constexpr Debug(bool b = true) : _hw(b), _io(b), _other(b) {}
    constexpr Debug(bool h, bool i, bool o) : _hw(h), _io(i), _other(o) {}

 public:
    constexpr bool any() { return _hw || _io || _other; }
    void           set_io(bool b) { _io = b; }
    void           set_hw(bool b) { _hw = b; }
    void           set_other(bool b) { _other = b; }
};

void Exercise_7_5::exercise_7_53() { Debug debug; }
