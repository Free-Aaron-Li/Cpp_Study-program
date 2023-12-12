// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_1_HPP
#define CPP_PRIMER_STUDYING_5_1_HPP

/**
 * @title
 * 5.1 简单语句
 */

#include "5.hpp"

class Exercise_5_1 {
 public:
    /**
     * @title
     * 练习5.1
     * @description
     * 什么是空语句？什么时候会用到空语句？
     */
    /* 空语句指一条语句中只包含一个单独的分号。
     * 当某个语法在逻辑上不需要语句时，就可以使用空语句。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习5.2
     * @description
     * 什么是块？什么时候会用到块？
     */
    /* 指用花括号括起来的语句和声明的序列，当程序中语法上需要一条语句，逻辑上需要多条语句的情况下，就可以使用块 */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习5.3
     * @description
     * 使用逗号运算符重写1.4.1节的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。
     */
    /* 对于我来说提高了，但是需要注意逗号运算符的规则，其返回值为运算符右侧对象 */
    static void exercise_5_3();
};
#endif  // CPP_PRIMER_STUDYING_5_1_HPP
