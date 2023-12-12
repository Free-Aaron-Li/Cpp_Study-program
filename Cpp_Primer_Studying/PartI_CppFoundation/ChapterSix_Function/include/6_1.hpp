// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_1.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_1_HPP
#define CPP_PRIMER_STUDYING_6_1_HPP

/**
 * @title
 * 6.1 函数基础
 */

#include "6.hpp"

class Exercise_6_1 {
 public:
    /**
     * @title
     * 6.1节练习
     */

    /**
     * @title
     * 练习6.1
     * @description
     * 实参和形参的区别是什么？
     */
    /* 实参是形参的初始值、形参存在于函数的形参列表中 */
    static void meaninglessFunction_1();


    /**
     * @title
     * 练习6.2
     * @description
     * 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
     * @code
     * (a) int f(){
     *          string s;
     *          ...
     *          return s;
     *    }
     * (b) f2(int i) { ... }
     * (c) int calc(int v1,int v1) ... }
     * (d) double square(double x) return x * x;
     */
    /* a：s对象为string类型，但是返回类型规定为int类型，无法返回s对象。
     * b：函数没有返回类型
     * c：函数的函数体缺少左花括号
     * d：函数缺少函数体的花括号
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习6.3
     * @description
     * 编写你自己的fact函数，上机检查是否正确
     */
    static void exercise_6_3();

    /**
     * @title
     * 练习6.4
     * @description
     * 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
     */
    /* 练习6.3的练习程序即可实现该功能 */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习6.5
     * @description
     * 编写一个函数输出其实参的绝对值。
     */
    static void exercise_6_5();

    /**
     * @title
     * 6.1.1 节练习
     */

    /**
     * @title
     * 练习6.6
     * @description
     * 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
     */
    /* 形参存在于形参列表中，属于局部变量。局部变量存在于函数体和形参列表中，当函数的控制路径经过变量定义语句时，创建该局部变量，当到达块末尾，局部变量被销毁。
     * 局部静态变量，类似局部变量被定义，但是当到达块末尾并不会被销毁，而是直到程序结束才被销毁。
     * */
    static void exercise_6_6();

    /**
     * @title
     * 练习6.7
     * @description
     * 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。
     */
    static void exercise_6_7();

    /**
     * @title
     * 6.1.2节练习
     */

    /**
     * @title
     * 练习6.8
     * @description
     * 编写一个名为Chapter6.h的头文件，令其包含6.1节练习中的函数声明。
     */
    /* 本头文件便是用于存放第6章第一节练习题的声明 */
    static void meaninglessFunction_4();

    /**
     * @title
     * 6.1.3节练习
     */

    /**
     * @title
     * 练习6.9
     * @description
     * 编写你自己的fact.cc和factMain.cc，这两个文件都应该包含上一小节的练习中编写的Chapter6.h头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。
     */
    /* 在我的笔记中详细描述，这里就不再赘述 */
    static void meaninglessFunction_5();
};
#endif  // CPP_PRIMER_STUDYING_6_1_HPP
