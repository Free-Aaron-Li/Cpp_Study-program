// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_13_2_HPP
#define CPP_PRIMER_STUDYING_13_2_HPP

/**
 * @title
 * 13.2 拷贝控制的资源管理
 */

#include "Has_Ptr.hpp"
#include "13.hpp"

class Exercise_13_2 {
 public:
    /**
     * @title
     * 13.2.0
     */

    /**
     * @title
     * 练习13.22
     * @description
     * 假定我们希望HasPtr的行为像一个值。即，对于对象所指向的string成员，每个对象有一份自己的拷贝。
     * 我们将在下一节介绍拷贝控制成员的定义。但是，你已经学会了定义这些成员所需的所有只是。在继续学习下一节之前，
     * 为HasPtr编写拷贝构造函数和拷贝赋值运算符。
     */
    static void exercise_13_22();

    /**
     * @title
     * 13.2.1 行为像值的类
     */

    /**
     * @title
     * 练习13.23
     * @description
     * 比较上一节练习中你编写的拷贝控制成员和这一节的代码。确定你理解了你的代码和我们的代码之间的差异（如果有的话）
     */
    /*
     * 在编写拷贝赋值运算符时，并没有采取一个正确顺序。
     * 在将右侧运算对象拷贝到临时对象前，先释放了当前对象中的内存。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习13.24
     * @description
     * 如果本节中的HasPtr版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？
     */
    /*
     * 如果未定义析构函数，在销毁对象时合成的析构函数不会释放_ps指向的内存，造成内存泄露。
     * */
    static void meaninglessFunction_2();
};
#endif  // CPP_PRIMER_STUDYING_13_2_HPP
