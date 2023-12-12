// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-03-27-下午4:35
 * @license GPL-3.0
 */

#include "test.hpp"

int Io_Test() {
    std::cout << "Enter two numbers: ";
    int value1 = 0, value2 = 0;
    std::cin >> value1 >> value2;
    std::cout << "The sum of " << value1 << " and " << value2 << " is " << value1 + value2
              << std::endl;
    return 0;
}

int hello() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}

int test() {
    //Io_Test();
    //hello();
    return 0;
}