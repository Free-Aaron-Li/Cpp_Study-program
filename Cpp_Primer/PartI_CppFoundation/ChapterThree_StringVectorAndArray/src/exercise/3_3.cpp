/**
 * @author AaronLi
 * @data 2023-05-23-下午11:36
 * @license GPL-3.0
 */
#include "3_3.hpp"

void Exercise_3_3::inputVector() {
    std::cout << "请输入一串整数（用空格隔开每个数）：";
    int number;
    std::vector<int> number_array;
    while (std::cin >> number) {
        number_array.push_back(number);
        if (std::cin.get() == '\n')break;
    }
    std::cout << "您输入的整数串为：";
    for (auto e: number_array) {
        std::cout << e << " ";
    }
}

void Exercise_3_3::inputVector_1() {
    std::cout << "请输入一串字符串（用空格隔开每个字符串）：";
    std::string str;
    std::vector<std::string> number_array;
    while (std::cin >> str) {
        number_array.push_back(str);
        if (std::cin.get() == '\n')break;
    }
    std::cout << "您输入的整数串为：";
    for (const auto &e: number_array) {
        std::cout << e << " ";
    }
    std::cout << "\n元素个数为：" << number_array.size();
}
