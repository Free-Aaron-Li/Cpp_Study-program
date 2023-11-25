// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

#include <iostream>

void test_1() { /* Displays IO operation errors */
    int i_val_1;
    std::cin >> i_val_1; /* if enter character */

   std::cout << std::cin.rdstate() << "\n"; /* Displays the current condition state of the stream */

    /* Reset condition state of the failbit */
    std::cin.clear(std::cin.rdstate() & ~std::istream::failbit);
    std::cout << std::cin.rdstate();
}

void test_2() { /* Associative input and output streams */
    std::cout << "test\n";
    std::cout << std::cin.tie() << "\n"; /* Display cout address */
    std::cout << &std::cout << "\n";     /* Consistent with the previous line */
    std::cout << &std::cin << "\n";      /* Display cin address */
}

/** @brief hello
 * @param this
 * @return about
 *
 */

int main() {
    // test_1();
    test_2();
    return 0;
}