// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-04-03-下午6:47
 * @license GPL-3.0
 */

#include "1_4.hpp"

void Exercise_1_4::StatisticalFrequency() {
    int target_value = 0, value = 0;
    /* 读取第一个数 */
    if (std::cin >> target_value) {
        int cnt = 1;
        while (std::cin >> value) {
            if (value == target_value) {
                ++cnt;
            } else {
                std::cout << "\n" << target_value << " occurs "
                          << cnt << " times ";
                target_value = value;
                cnt = 1;
            }
            if (std::cin.get() == '\n')break;
        }
        std::cout << "\n" << target_value << " occurs "
                  << cnt << " times " << std::endl;
    }
}


void Exercise_1_4::IntegerPlus() {
    ElemType value_1 = 0;
    ElemType value_2 = 0;

    std::cout << "请输入两个整数：";
    std::cin >> value_1;
    std::cin >> value_2;

    std::cout << "两个整数之间的值为：" << std::endl;
    if (value_1 <= value_2) {
        while (value_1 <= value_2) {
            std::cout << value_1 << " ";
            value_1++;
        }
    } else {
        while (value_2 <= value_1) {
            std::cout << value_2 << " ";
            value_2++;
        }
    }
}

