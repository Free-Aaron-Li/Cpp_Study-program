// This file is part of Cpp_Primer_Studying project.
// This program is called:4_9.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include "4_9.hpp"

void Exercise_4_9::meaninglessFunction_1() {}

void Exercise_4_9::exercise_4_28() {
    int         i;
    double      j;
    float       k;
    bool        m;
    char        n;
    wchar_t     q;
    char16_t    p;
    short       u;
    long        y;
    long long   r;
    long double e;
    std::cout << "int is " << sizeof i << "\n";
    std::cout << "double is " << sizeof j << "\n";
    std::cout << "float is " << sizeof k << "\n";
    std::cout << "bool is " << sizeof m << "\n";
    std::cout << "char is " << sizeof n << "\n";
    std::cout << "wchar_t is " << sizeof q << "\n";
    std::cout << "char16_t is " << sizeof p << "\n";
    std::cout << "short is " << sizeof u << "\n";
    std::cout << "long is " << sizeof y << "\n";
    std::cout << "long long is " << sizeof r << "\n";
    std::cout << "long double is " << sizeof e << "\n";
}

void Exercise_4_9::exercise_4_29() {
    int x[10], *p = x;
    std::cout << sizeof(x) / sizeof(*p) << "\n";
    std::cout << sizeof(p) << "\n";
    std::cout << sizeof(p) / sizeof(*p) << "\n";
}
