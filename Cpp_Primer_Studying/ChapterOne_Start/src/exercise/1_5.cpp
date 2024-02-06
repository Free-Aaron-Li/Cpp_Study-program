// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-04-05-下午2:46
 * @license GPL-3.0
 */

#include "1_5.hpp"
#include "Sales_item.h"

void Exercise_1_5::Book() {
    Sales_item book;
    ElemType   number = 1;
    std::cout << "请输入书籍销售记录：（ISBN编码 销售量 销售单价）" << std::endl;
    while (std::cin >> book) {
        std::cout << "第" << number << "记录：" << book << std::endl;
        ++number;
        if (std::cin.get() == '\n')
            break;
    }
}

void Exercise_1_5::BookSum() {
    Sales_item item_1, item_2;
    std::cout << "请输入两个ISBN相同的书籍销售记录：" << std::endl;
    std::cin >> item_1 >> item_2;
    std::cout << "销售记录和为：" << std::endl;
    std::cout << item_1 + item_2 << std::endl;
}

void Exercise_1_5::BooksSum() {
    Sales_item book, sum;
    std::cout << "请输入多个相同ISBN的书籍销售记录：" << std::endl;
    if (std::cin >> sum) {
        while (std::cin >> book) {
            sum += book;
            if (std::cin.get() == '\n')
                break;
        }
    }
    std::cout << "所有记录之和为：" << sum << std::endl;
}

void Exercise_1_5::SalesRecordSum() {
    Sales_item target_item;
    ElemType   sum = 1;
    std::cout << "请输入销售记录：" << std::endl;
    if (std::cin >> target_item) {
        Sales_item item;
        while (std::cin >> item) {
            if (target_item.isbn() == item.isbn()) {
                ++sum;
            } else {
                std::cout << "ISBN为：" << target_item.isbn() << "的销售记录有：" << sum << "条" << std::endl;
                target_item = item;
                sum         = 1;
                if (std::cin.get() == '\n')
                    break;
            }
        }
        std::cout << "ISBN为：" << target_item.isbn() << "的销售记录有：" << sum << "条" << std::endl;
    } else {
        std::cerr << "并未读取到任何数据" << std::endl;
    }
}
