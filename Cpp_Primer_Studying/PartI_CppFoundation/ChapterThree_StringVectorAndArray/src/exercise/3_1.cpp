/**
 * @author AaronLi
 * @data 2023-05-17-下午1:22
 * @license GPL-3.0
 */

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "3_1.hpp"

using std::cin;
using std::cout;

void Exercise_3_1::range() {
    cout << "请输入两个整数：";
    double range_left, range_right;
    cin >> range_left;
    cin >> range_right;
    if (range_left > range_right) {
        cout << "您输入的整数不合法！\n";
        return;
    }

    if (range_left - (int) range_left == 0 && range_right - (int) range_right == 0) {
        cout << "两整数范围内的所有整数是：\n";
        for (int i = (int) range_left + 1; i < range_right; ++i) {
            cout << i << " ";
        }
    } else {
        cout << "您输入的不是整数！\n";
        return;
    }
}
