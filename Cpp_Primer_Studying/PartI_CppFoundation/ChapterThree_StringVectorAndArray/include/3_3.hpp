/**
 * @author AaronLi
 * @data 2023-05-19-下午11:35
 * @license GPL-3.0
 */

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_3_3_HPP
#define CPP_PRIMER_3_3_HPP

/**
 * @title
 * 3.3 标准库类型vector
 */
#include <cxxabi.h>

#include <iostream>
#include <vector>

class Exercise_3_3 {
 public:
    /**
     * @title
     * 3.3.1节练习
     */
    /**
     * @title
     * 练习3.12
     * @description
     * 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果：对于不正确的，请说明其错误的原因。
     * @code
     * (a) vector<vector<int>> ivec;
     * (b) vector<string> svec=ivec;
     * (c) vector<string> svec(10,"null");
     */
    /* b错误，无法将一个类型为vector<int>的vector拷贝初始化string类型的vector */

    /**
     * @title
     * 练习3.13
     * @description
     * 下列的vector对象各包含多少个元素？这些元素的值分别是多少？
     * @code
     * (a) vector<int> v1;         (b) vector<int> v2(10);
     * (c) vector<int> v3(10,42);  (d) vector<int> v4{10};
     * (e) vector<int> v5{10,42};  (f) vector<string> v6{10};
     * (g) vector<string> v7{10,"hi"};
     */
    /* a：空元素
     * b：10个默认初始化为0的int类型元素
     * c：10个值为42的int类型元素
     * d：1个值为10的int类型元素
     * e：值为10，42的2个int类型元素
     * f：10个默认初始化的string类型元素
     * g：10个值为“hi”的string类型元素
     * */

    /**
     * @title
     * 3.3.2节练习
     */

    /**
     * @title
     * 练习3.14
     * @description
     * 编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
     */
    static void inputVector();

    /**
     * @title
     * 练习3.15
     * @description
     * 改写上题的程序，不过这次读入的是字符串。
     */
    static void inputVector_1();

    /**
     * @title
     * 3.3.3节练习
     */

    /**
     * @title
     * 练习3.16
     * @description
     * 编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不正确，回过头重新学习3.3.1节直到弄明白错在何处为止。
     */
    static void outputVector();
    /* I am a genius */

    /**
     * @title
     * 练习3.17
     * @description
     * 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。输入改变后的结果，每个词占一行。
     */
    static void inputVector_2();

    /**
     * @title
     * 练习3.18
     * @description
     * 下面的程序合法吗？如果不合法，你准备如何修改？
     * @code
     * vector<int> ivec;
     * ivec[0] = 42;
     */
    /* 不合法，无法通过使用下标的方式为vector对象添加元素，应该修改为：
     * ivec.push_back(42);
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习3.19
     * @description
     * 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请列举出三种不同的实现方式。哪种方法更好呢？为什么？
     */
    /* 方式①：vector<int> v1(10,42);
     * 方式②：vector<int> v2{42,42,42,42,42,42,42,42,42,42};
     * 方式③：vector<char> v3{10,'42'};
     * 第一种方式，简单高效
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习3.20
     * @description
     * 读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后一个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
     */
    static void inputVector_3();
};

#endif  // CPP_PRIMER_3_3_HPP
