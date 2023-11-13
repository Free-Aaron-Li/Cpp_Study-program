// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-04-03-下午6:47
 * @license GPL-3.0
 */

#include "1_4.hpp"

void Exercise_1_4::OutputSum() {
    int sum = 0, value = 0;

    while (std::cin >> value) {
        sum += value;
        if (std::cin.get()=='\n'){
            break;
        }
    }
    std::cout << "Sum is: " << sum << std::endl;
}