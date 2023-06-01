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

void Exercise_3_3::outputVector() {
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    std::cout << "this is v1:";
    for (auto e: v1) {
        std::cout << e;
    }
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "this is v2:";
    for (auto e: v2) {
        std::cout << e;
    }
    std::cout << "\n";
    std::cout << "this is v3:";
    for (auto e: v3) {
        std::cout << e;
    }
    std::cout << "\n";
    std::cout << "this is v4:";
    for (auto e: v4) {
        std::cout << e;
    }
    std::cout << "\n";
    std::cout << "this is v5:";
    for (auto e: v5) {
        std::cout << e;
    }
    std::cout << "\n";
    std::cout << "this is v6:";
    for (const auto &e: v6) {
        std::cout << e;
    }
    std::cout << "\n";
    std::cout << "this is v7:";
    for (const auto &e: v7) {
        std::cout << e;
    }

    std::cout << "\nv7 type is: " << abi::__cxa_demangle(typeid(v7).name(), nullptr, nullptr, nullptr) << "\n";
}

void Exercise_3_3::inputVector_2() {
    std::vector<char> character_array;
    std::string str;
    getline(std::cin, str);
    for (auto e: str) {
        character_array.push_back(e);
    }

    for (auto &c: character_array) {
        c = toupper(c);
    }

    std::cout << "the new array is: ";
    for (auto e: character_array) {
        std::cout << e;
    }
}

void Exercise_3_3::inputVector_3() {
    std::cout << "请输入一组整数：";
    std::vector<int> numbers;
    int number;
    while (std::cin >> number) {
        numbers.push_back(number);
        if (std::cin.get() == '\n')break;
    }

    std::cout << "相邻两整数相加得到的集合为：";
    for (int i = 0; i < numbers.size(); i += 2) {
        std::cout << numbers[i] + numbers[i + 1] << "  ";
    }

    std::cout << "\n首尾整数相加得到的集合为：";
    for (int i = 0; i < numbers.size() / 2; i++) {
        std::cout << numbers[i] + numbers[numbers.size() - 1 - i] << "  ";
    }
    if (numbers.size() % 2 == 1) std::cout << numbers[numbers.size() / 2];
}

void Exercise_3_3::meaninglessFunction_1() {

}

void Exercise_3_3::meaninglessFunction_2() {

}
