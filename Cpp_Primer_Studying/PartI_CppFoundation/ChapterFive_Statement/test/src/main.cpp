// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include <iostream>
#include <string>

void test_switch() {
    char character;
    int  number = 0;
    std::cin >> character;
    switch (character) {
        case 'a':
        case 'b':
        case 'c': number++; break;
        default: std::cout << "error!\n"; break;
    }
    std::cout << "number is " << number << "\n";
}

void test_switch_Internal_definition() {
    bool index = false;
    // switch (index) {
    //     case true:
    //         std::string file_name;
    //         int         ival = 0;
    //         int         jval;
    //         break;
    //     case false: /* 错误！ */
    //         jval = 0;
    //         if (file_name.empty()) {};
    //         break;
    //     default: break;
    // }
}

void test_statement() {
    int ix, sz = 10;
    for (; ix != sz; ++ix) {}
    std::cout << ix;
}

int main() {
    // test_switch();
    // test_switch_Internal_definition();
    test_statement();
    return 0;
}