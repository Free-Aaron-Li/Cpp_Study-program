/**
 * @author AaronLi
 * @date 2023-04-01-下午11:36
 * @license GPL-3.0
 */

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "1_4.hpp"

void Exercise_1_4::Sum() {
    int sum = 0;
    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }

    std::cout << "sum is: " << sum << std::endl;
}

void Exercise_1_4::ForAndWhile() {
    std::cout << "首先讨论while循环，while循环分为两个部分，控制语句和语句块。" << std::endl;
    std::cout << "优点： \n仅需控制表达式便可以完成循环执行。\n缺点：\n如果需要使用递增/递减变量需要自行编写，较为麻烦。"
              << std::endl;
    std::cout << "for循环是while循环的扩展形式，由于在循环条件中检测变量、在循环体中递增/递减变量的模式使用非常频繁，所以产生"
                 "for循环。\n缺点：在不需要检测变量的情况下使用for循环容易产生误解" << std::endl;
}