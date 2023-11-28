// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_13_1_HPP
#define CPP_PRIMER_STUDYING_13_1_HPP

/**
 * @title
 * 13.1 拷贝、赋值与销毁
 */

#include "13.hpp"

class Exercise_13_1 {
 public:
    /**
     * @title
     * 13.1.1 拷贝构造函数
     */

    /**
     * @title
     * 练习13.1
     * @description
     * 拷贝构造函数是什么？什么时候使用它？
     */
    /*
     * 如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，那么此构造函数是拷贝构造函数。
     * 当拷贝初始化时使用拷贝构造函数完成，但并不总是使用。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习13.2
     * @description
     * 解释为什么下面的声明是非法的：
     * @code
     * Sales_data::Sales_data(Sales_data rhs);
     */
    /*
     * 拷贝构造函数第一个参数必须为引用类型。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习13.3
     * @description
     * 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？
     */
    /*
     * 拷贝StrBlob时，仅需拷贝其唯一元素data，调用shared_ptr的拷贝构造函数进行拷贝，引用计数加1。
     * 拷贝StrBlob时，对wptr成员，调用weak_ptr的拷贝构造函数进行拷贝，引用计数不变；拷贝curr，则直接进行内存复制。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习13.4
     * @description
     * 假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
     * @code
     * Point global;
     * Point foo_bar(Point arg)
     * {
     *      Point local = arg, *heap = new Point(global);
     *      *heap = local;
     *      Point pa[4] = {local,*heap};
     *      return *heap;
     * }
     */
    /*
     * 1. local采用拷贝初始化时用到；
     * 2. 使用花括号初始化数组时用到；
     * 3. foo_bar函数返回类型为非引用类型，返回*heap时用到；
     * 4. local拷贝到*heap地址时用到；
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习13.5
     * @description
     * 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是ps本身的位置。
     * @code
     * class HasPtr{
     * public:
     *      HasPtr(const std::string &s = std::string()) : ps(new std::string(s)),i(0){}
     * private:
     *      std::string *ps;
     *      int i;
     * }
     */
    static void exercise_13_5();
};

#endif  // CPP_PRIMER_STUDYING_13_1_HPP
