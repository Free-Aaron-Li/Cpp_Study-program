// This file is part of Cpp_Workspace project.
// This program is called:4_8.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_WORKSPACE_4_8_HPP
#define CPP_WORKSPACE_4_8_HPP

/**
 * @title
 * 4.8 位运算符
 */

#include <bitset>

#include "4.hpp"

class Exercise_4_8 {
 public:
    /**
     * @title
     * 练习4.25
     * @description
     * 如果一台机器上int占32位、char占8位，用的是Latin-1字符集，其中字符'q'的二进制形式是01110001，那么表达式~'q'<<6的值是什么？
     */
    /* 首先获取到q的二进制码为：0111,0001，求反位运算符优先级大于左移运算符，所以首先进行求反操作，char类型提升为int类型，其二进制码转换为：
     * 0000,0000 0000,0000 0000,0000 0111,0001转换为：1111,1111 1111,1111 1111,1111 1000,1110
     * 再经过左移6位得到：1111,1111 1111,1111 1110,0011 1000,0000。转换为八进制为：FFFF E380
     * */
    static void exercise_4_25();

    /**
     * @title
     * 练习4.26
     * @description
     * 在本节关于测验成绩的例子中，如果使用unsigned int作为quiz1的类型会发生什么情况？
     */
    /* 在不同的设备上，int类型可能为16位，会导致位数不足情况。使得结果出现误差或者得到未定义的值 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习4.27
     * @description
     * 下列表达式的结果是什么？
     * @code
     * unsigned long ul1=3,ul2=7;
     * (a) ul1 & ul2                (b) ul1 | ul2
     * (c) ul1 && ul2               (d) ul1 || ul2
     */
    /* 获取ul1和ul2的二进制码：
     * ul1：0000,0011
     * ul2：0000,0111
     * a：进行位与运算，得到：3
     * b：进行位或运算，得到：7
     * c：进行逻辑与运算，得到：1
     * d：进行逻辑或运算，得到：1
     * */
    static void meaninglessFunction_2();
};
#endif  // CPP_WORKSPACE_4_8_HPP
