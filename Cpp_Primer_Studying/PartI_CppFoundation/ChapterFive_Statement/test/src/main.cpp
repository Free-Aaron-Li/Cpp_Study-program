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

int main() {
    test_switch();
    return 0;
}