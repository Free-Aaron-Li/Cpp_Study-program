// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_13_3_HPP
#define CPP_PRIMER_STUDYING_13_3_HPP

/**
 * @title
 * 13.3 交换操作
 */

#include "13.hpp"
#include "Has_Ptr.hpp"
#include <algorithm>

class Exercise_13_3 {
 public:
    /** @title
     * 13.3 交换操作
     */


    /**
     * @title
     * 练习13.29
     * @description
     * 解释swap(HasPtr&,HasPtr&)中对swap的调用不会导致递归循环。
     */
    /*
     * swap函数中调用的swap函数均是标准库函数swap,而非自定义的swap。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习13.30
     * @description
     * 为你的类值版本的HasPtr编写swap函数，并测试它。为你的swap函数添加一个打印语句，指出函数什么时候执行。
     */
    static void exercise_13_30();

    /**
     * @title
     * 练习13.31
     * @description
     * 为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。为这个vector添加一些元素，并对它执行sort。
     * 注意何时会调用swap。
     */
    /*
     * 需要注意到使用sort函数（algorithm库中)必须定义<运算符。
     * 当数据大于16时，sort算法会采用快速排序，这个时候会使用到swap函数，当子序列长度小于等于16时，又会转回插入排序算法。
     * 如果swap函数没有实现，sort算法依旧采用插入排序算法。
     * */
    static void exercise_13_31();

    /**
     * @title
     * 练习13.32
     * @description
     * 类指针的HasPtr版本会从swap受益吗？如果会，得到了什么益处？如果不是，为什么？
     */
    /*
     * 由于两个对象都指向对方的string，两者相互交换string后，各自版本的引用计数保持不变（都是减1再加1）。
     * 默认的swap版本已经能够正常处理类指针类的交换，特殊的swap并不会带来收益。
     * */
    static void meaninglessFunction_2();
};
#endif  // CPP_PRIMER_STUDYING_13_3_HPP
