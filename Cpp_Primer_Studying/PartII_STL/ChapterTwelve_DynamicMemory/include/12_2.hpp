// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_12_2_HPP
#define CPP_PRIMER_STUDYING_12_2_HPP

/**
 * @title
 * 12.2 动态数组
 */

#include "12.hpp"

class Exercise_12_2 {
 public:
    /**
     * @title
     * 12.2.1 new和数组
     */

    /**
     * @title
     * 练习12.23
     * @description
     * 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象。
     */
    static void exercise_12_23();

    /**
     * @title
     * 练习12.24
     * @description
     * 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。
     */
    static void exercise_12_24();

    /**
     * @title
     * 练习12.25
     * @description
     * 给定下面的new表达式，你应该如何释放pa？
     * @code
     * int *pa = new int[10];
     */
    /*
     * delete [] pa;
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 12.2.2 allocator类
     */

    /**
     * @title
     * 练习12.26
     * @description
     * 用allocator重写第427页中的程序。
     */
    static void exercise_12_26();
};
#endif  // CPP_PRIMER_STUDYING_12_2_HPP
