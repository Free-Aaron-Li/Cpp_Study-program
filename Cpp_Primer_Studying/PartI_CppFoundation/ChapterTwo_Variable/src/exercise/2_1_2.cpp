// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-04-06-下午6:44
 * @license GPL-3.0
 */

#include "2_1.hpp"

void Exercise_2_1::TypeConversion() {
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; /* 32 */
    /* 得到的无符号数为负数，那么负数会被自动转换为一个合法无符号数 */
    std::cout << u - u2 << std::endl; /* 4294967264 */

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; /* 32 */
    std::cout << i - i2 << std::endl; /* -32 */
    /* 当一个算术表达式转给你既有无符号数又有int值时，那个int值就会转换为无符号数 */
    std::cout << i - u << std::endl; /* 0 */
    std::cout << u - i << std::endl; /* 0 */
}

void Exercise_2_1::Escape() {
    std::cout << "*******************" << std::endl;
    std::cout << "2M\012";
    std::cout << "2\012M\012";
    std::cout << "*******************" << std::endl;
}
