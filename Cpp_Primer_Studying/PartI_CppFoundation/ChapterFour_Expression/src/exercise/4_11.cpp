// This file is part of Cpp_Primer_Studying project.
// This program is called:4_11.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_11.hpp"

void Exercise_4_11::meaninglessFunction_1() {}
void Exercise_4_11::meaninglessFunction_2() {}
void Exercise_4_11::meaninglessFunction_3() {}
void Exercise_4_11::meaninglessFunction_4() {}

void Exercise_4_11::exercise_4_34() {
    float  fval = 10.0;
    int    ival = 12;
    double dval = 12.00;
    char   cval = '1';
    std::cout << "fval sizeof is " << sizeof(fval) << "\n";
    std::cout << "ival sizeof is " << sizeof(ival) << "\n";
    std::cout << "dval sizeof is " << sizeof(dval) << "\n";
    std::cout << "cval sizeof is " << sizeof(cval) << "\n";
    dval = fval + ival;
    std::cout << "dval sizeof is " << sizeof(dval) << " and this value is " << dval << "\n";

    dval = dval + ival * cval;
    std::cout << "dval sizeof is " << sizeof(dval) << " and this value is " << dval << "\n";
}
