// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_6.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_6_HPP
#define CPP_PRIMER_STUDYING_6_6_HPP

/**
 * @title
 * 6.6 函数匹配
 */

#include "6.hpp"

class Exercise_6_6 {
 public:
    /** * @title * 练习6.49 * @description
     * 什么是候选函数？什么是可行函数？
     */
    /* 候选函数满足两个特征：1. 与被调用的函数同名，2. 其声明在调用点可见（也就是与被调函数处于同一个作用域）
     * 可行函数也满足两个特征：1. 其形参数量与调用所提供的实参数量一致，2.
     * 每个实参的类型与对应的形参类型相同，或者能够转换成形参类型
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习6.50
     * @description
     * 已知有第217页对函数f的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
     * (a) f(2.56,42)   (b) f(42)   (c) f(42,0)     (d)f(2.56,3.14)
     */
    /* a: 可行函数：fii、fdd；调用不合法，存在二义性
     * b：可行函数：fi、fdd；最佳函数：fi
     * c：可行函数：fii、fdd；最佳函数：fii
     * d：可行函数：fii、fdd；最佳函数：fdd
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习6.51
     * @description
     * 编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一个练习题的答案，如果你回答错误了，反复研究本节的内容直到你弄清楚自己错在何处。
     */
    static void exercise_6_51();

    /**
     * @title
     * 6.6.1节练习
     */

    /**
     * @title
     * 练习6.52
     * @description
     * 已知有如下声明：
     *     void manip(int,int);
     *     double dobj;
     * 请指出下列调用中每个类型转换的等级。
     * (a) manip('a','z');             (b) manip(55.4,dobj);
     */
    /* a：3级，类型提升实现的匹配
     * b：4级，通过算术类型转换实现的匹配
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习6.53
     * @description
     * 说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。
     * @code
     * (a) int calc(int &,int &);
     *     int calc(const int &,const int &);
     * (b) int calc(char *,char *);
     *     int calc(const char *,const char *);
     * (c) int calc(char *,char *);
     *     int calc(char * const,char * const);
     */
    /* a：合法，实参可以为const int类型
     * b：合法，实参可以为const char *类型
     * c：合法，const为顶层const，声明重复（重载函数中含有顶层const和不含有的形参所组成的其他类型相同的形参列表组成的函数是一致的）
     * */
    static void meaninglessFunction_4();
};

#endif  // CPP_PRIMER_STUDYING_6_6_HPP
