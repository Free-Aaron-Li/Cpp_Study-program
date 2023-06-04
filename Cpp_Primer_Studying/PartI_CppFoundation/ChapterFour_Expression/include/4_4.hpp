// This file is part of Cpp_Primer_Studying project.
// This program is called:4_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_4_HPP
#define CPP_PRIMER_STUDYING_4_4_HPP

/**
 * @title
 * 4.4 赋值运算符
 */

#include "4.hpp"

class Exercise_4_4 {
 public:
    /**
     * @title
     * 练习4.13
     * @description
     * 在下述语句中，当赋值完成后i和d的值分别是什么？
     * @code
     * int i;double d;
     * (a) d=i=3.5;         (b) i=d=3.5;
     */
    /* a：i=3 d=3.0
     * b：d=3.4 i=3
     * */
    static void exercise_4_13();

    /**
     * @title
     * 练习4.14
     * @description
     * 执行下述if语句后将发生什么情况？
     * @code
     * if (42=i) //...
     * if(i=42) //...
     */
    /* 第一个if语句：错误，因为赋值运算符的左侧运算对象必须是一个可修改的左值，42仅为字面值，无法进行赋值操作。
     * 第二个if语句：i对象的值将会被赋值为42。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习4.15
     * @description
     * 下面的赋值是非法的，为什么？应该如何修改？
     * @code
     * double dval;int ival;int *pi;
     * dval=ival=pi=0;
     */
    /* pi的类型为int *，dval和ival均为内置类型，无法将int指针类型的pi赋值给dval和ival。
     * 应该修改为：dval=ival=0; pi=0;
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习4.16
     * @description
     * 尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？
     * @code
     * (a) if(p=getPtr()!=0)            (b) if(i=1024)
     */
    /* a：由于!=运算符的优先级高于赋值运算符，所以首先getPtr()函数的返回值与0做比较并返回布尔值，将布尔值赋值给p对象。根据p的返回值决定if语句。
     * b：将1024字面值赋值给i，并将赋值运算符的返回值转换为布尔值true，if语句将会被以true的方式执行。
     * */
    static void meaninglessFunction_3();
};

#endif  // CPP_PRIMER_STUDYING_4_4_HPP
