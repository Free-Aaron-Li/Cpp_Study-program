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