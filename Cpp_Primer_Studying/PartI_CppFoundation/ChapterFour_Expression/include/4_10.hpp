// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:4_10.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_4_10_HPP
#define CPP_PRIMER_STUDYING_4_10_HPP

/**
 * @title
 * 4.10 逗号运算符
 */

#include "4.hpp"

class Exercise_4_10 {
 public:
    /**
     * @title
     * 练习4.31
     * @description
     * 本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增运算符需要哪些改动？使用后置版本重写本节的程序。
     */
    static void exercise_4_31();

    /**
     * @title
     * 练习4.32
     * @description
     * 解释下面这个循环的含义。
     * @code
     * constexpr int size = 5;
     * int ia[size] = {1,2,3,4,5};
     * for(int *ptr=ia,ix=0;ix!=size && ptr!=ia+size; ++ix,++ptr){ ...}
     */
    /* 遍历这个数组 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习3.33
     * @description
     * 根据4.12节中的表说明下面这条表达式的含义。
     * @code
     * someValue ? ++x,++y :--x,--y;
     */
    /* 在这个表达式中存在四种运算符：条件运算符，逗号运算符、递增运算符和递减运算符。
     * 其中优先级：递增运算符，递减运算符>条件运算符>逗号运算符
     * 所以，实际表达式等价于：(someValue?++x,--y:--x),--y;
     * 实际上，这条表达式并不能够执行。
     * */
    static void exercise_4_33();
};
#endif  // CPP_PRIMER_STUDYING_4_10_HPP
