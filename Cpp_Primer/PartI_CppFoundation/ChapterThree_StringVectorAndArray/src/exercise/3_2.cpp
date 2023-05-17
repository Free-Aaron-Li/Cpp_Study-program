/**
 * @author AaronLi
 * @data 2023-05-17-下午11:29
 * @license GPL-3.0
 */
#include "3_2.hpp"

void Exercise_3_2::readInWords() {
    std::cout << "----------\n"
                 "练习3.2——壹\n";
    std::cout << "请输入一段文字！\n";
    std::string str;
    while (getline(std::cin, str)) {
        std::cout << str << "\n";
        if (std::cin.get() == '\n')break;
    }

    std::cout << "----------\n"
                 "练习3.2——贰\n";
    std::cout << "请输入一段文字！\n";
    std::string word;
    while (std::cin >> word) {
        std::cout << word << "\n";
        if (std::cin.get() == '\n')break;
    }
}

void Exercise_3_2::compareStrings() {
    std::cout << "----------\n"
                 "练习3.4——壹\n";
    std::string str_1, str_2;
    std::cout << "请输入两串相同的字符串！\n";
    std::cout << "字符串1：";
    getline(std::cin, str_1);
    std::cout << "字符串2：";
    getline(std::cin, str_2);

    if (str_1 == str_2) {
        std::cout << "二者相同！\n";
    } else {
        if (str_1 > str_2)std::cout << "字符串1更大，其值为：" << str_1 << "\n";
        else std::cout << "字符串2更大，其值为：" << str_2 << "\n";
    }

    std::cout << "----------\n"
                 "练习3.4——贰\n";
    std::cout << "请输入两串字符串，用于比较二者长度！\n";
    std::cout << "字符串1：";
    getline(std::cin, str_1);
    std::cout << "字符串2：";
    getline(std::cin, str_2);

    if (str_1.size() == str_2.size()) {
        std::cout << "二者长度相同！";
    } else {
        if (str_1.size() > str_2.size())std::cout << "字符串1的长度更长，其值为：" << str_1 << "\n";
        else std::cout << "字符串2的长度更长，其值为：" << str_2 << "\n";
    }
}

void Exercise_3_2::connectionStrings() {
    std::cout << "----------\n"
                 "练习3.5——壹\n";
    std::cout << "请输入多个字符串于下一行：\n";
    std::string str_1, str_2;
    while (getline(std::cin, str_2)) {
        str_1 += str_2;
    }

    std::cout << "最终的字符串为：" << str_1 << "\n";
}

void Exercise_3_2::connectionStrings_1() {
    std::string str_1, str_2;
    std::cout << "----------\n"
                 "练习3.5——贰\n";
    std::cout << "请输入多个字符串于下一行：\n";
    while (getline(std::cin, str_2)) {
        str_1 += str_2 + " ";
    }
    std::cout << "最终的字符串，用空格隔开：" << str_1 << "\n";
}
