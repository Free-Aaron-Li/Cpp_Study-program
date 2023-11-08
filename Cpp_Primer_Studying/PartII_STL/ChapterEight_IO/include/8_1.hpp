// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_1.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_8_1_HPP
#define CPP_PRIMER_STUDYING_8_1_HPP

/**
 * @title
 * 8.1 IO类
 */

#include "8.hpp"

class Exercise_8_1 {
 public:
    /**
     * @title
     * 8.1.2节练习
     */

    /**
     * @title
     * 练习8.1
     * @description
     * 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。
     * 它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。
     */
    static void exercise_8_1();

    /**
     * @title
     * 练习8.2
     * @description
     * 测试函数，调用参数cin。
     */
    /* 具体查看exercise_8_1函数 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习8.3
     * @description
     * 什么情况下，下面的while循环会终止？
     * @code
     * while(cin>>i) // ....
     */
    /*
     * 当cin读取到EOF文件结束符，当程序强制终止时，也就是说只要badbit、failbit、eofbit任何一个标志位被置位，
     * 都会导致while循环结束
     * */
    static void meaninglessFunction_2();
};
#endif  // CPP_PRIMER_STUDYING_8_1_HPP
