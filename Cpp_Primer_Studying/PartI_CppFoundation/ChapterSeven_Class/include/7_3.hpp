// This file is part of Cpp_Primer_Studying project.
// This program is called:7_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_3_HPP
#define CPP_PRIMER_STUDYING_7_3_HPP

/**
 * @title
 * 7.3 类的其他特性
 */

#include "7.hpp"
#include "window_mgr.hpp"

class Exercise_7_3 {
 public:
    /**
     * @title
     * 7.3.1节练习
     */

    /**
     * @title
     * 练习7.23
     * @description
     * 编写你自己的Screen类。
     */
    /* 具体查看include/screen.hpp文件 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.24
     * @description
     * 给你的Screen类添加三个构造函数：一个默认构造函数；
     * 另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；
     * 第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。
     */
    /* 具体查看include/screen.hpp文件 */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.25
     * @description
     * Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？
     */
     /* Screen类中数据成员的类型仅有内置类型和string类型，所有能够进行拷贝和赋值操作。 */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.26
     * @description
     * 将Sales_data::avg_price定义成内联函数。
     */
     /* 查看include/sales_data_private.hpp文件 */
    static void meaninglessFunction_4();

};
#endif  // CPP_PRIMER_STUDYING_7_3_HPP
