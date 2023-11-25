// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.
*@author AaronLi *@data 2023 - 05 - 17 - 下午11 : 29 * @license GPL
  - 3.0 * /

#include "3_2.hpp"

      void
      Exercise_3_2::readInWords() {
    std::cout << "----------\n"
                 "练习3.2——壹\n";
    std::cout << "请输入一段文字！\n";
    std::string str;
    while (getline(std::cin, str)) {
        std::cout << str << "\n";
        if (std::cin.get() == '\n')
            break;
    }

    std::cout << "----------\n"
                 "练习3.2——贰\n";
    std::cout << "请输入一段文字！\n";
    std::string word;
    while (std::cin >> word) {
        std::cout << word << "\n";
        if (std::cin.get() == '\n')
            break;
    }
}

void
Exercise_3_2::compareStrings() {
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
        if (str_1 > str_2)
            std::cout << "字符串1更大，其值为：" << str_1 << "\n";
        else
            std::cout << "字符串2更大，其值为：" << str_2 << "\n";
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
        if (str_1.size() > str_2.size())
            std::cout << "字符串1的长度更长，其值为：" << str_1 << "\n";
        else
            std::cout << "字符串2的长度更长，其值为：" << str_2 << "\n";
    }
}

void
Exercise_3_2::connectionStrings() {
    std::cout << "----------\n"
                 "练习3.5——壹\n";
    std::cout << "请输入多个字符串于下一行：\n";
    std::string str_1, str_2;
    while (getline(std::cin, str_2)) {
        str_1 += str_2;
    }

    std::cout << "最终的字符串为：" << str_1 << "\n";
}

void
Exercise_3_2::connectionStrings_1() {
    std::string str_1, str_2;
    std::cout << "----------\n"
                 "练习3.5——贰\n";
    std::cout << "请输入多个字符串于下一行：\n";
    while (getline(std::cin, str_2)) {
        str_1 += str_2 + " ";
    }
    std::cout << "最终的字符串，用空格隔开：" << str_1 << "\n";
}

void
Exercise_3_2::characterInstead() {
    std::cout << "请输入一串字符于下方\n";
    std::string str;
    getline(std::cin, str);

    for (auto &c : str) {
        if (!std::isspace(c))
            c = 'X';
    }

    std::cout << "字符全部替换为X后的字符串为：" << str << "\n";
}

void
Exercise_3_2::characterInstead_1() {
    std::cout << "请输入一串字符于下方\n";
    std::string str;
    getline(std::cin, str);

    for (char c : str) {
        if (!std::isspace(c))
            c = 'X';
    }

    std::cout << "字符全部替换为X后的字符串为：" << str << "\n";
}

void
Exercise_3_2::characterInstead_2() {
    /**
     * 使用while循环和for循环重写characterInstead()方法
     * */
    std::cout << "请输入一串字符于下方\n";
    std::string str;
    getline(std::cin, str);

    decltype(str.size()) index = 0;

    while (index < str.size()) {
        if (!std::isspace(str[index]))
            str[index] = 'X';
        ++index;
    }

    for (index = 0; index < str.size(); ++index) {
        if (!std::isspace(str[index]))
            str[index] = 'X';
    }

    std::cout << "字符全部替换为X后的字符串为：" << str << "\n";
}

void
Exercise_3_2::punctuationRemoval() {
    std::cout << "请输入一串字符于下方\n";
    std::string str;
    getline(std::cin, str);
    std::string new_string;

    for (char &c : str) {
        if (!std::ispunct(c))
            new_string += c;
    }

    std::cout << "标点符号全部删除后的字符串为：" << new_string << "\n";
}
