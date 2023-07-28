// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include <iostream>

void test() { /* Displays IO operation errors */
    int i_val_1;
    std::cin >> i_val_1; /* if enter character */

    std::cout << std::cin.rdstate() << "\n"; /* Displays the current condition state of the stream */

    /* Reset condition state of the failbit */
    std::cin.clear(std::cin.rdstate() & ~std::istream::failbit);
    std::cout << std::cin.rdstate();
}

int main() { test(); }