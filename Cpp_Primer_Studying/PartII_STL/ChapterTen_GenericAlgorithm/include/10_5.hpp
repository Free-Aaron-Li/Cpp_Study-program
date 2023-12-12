// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'10_5'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_10_5_HPP
#define CPP_PRIMER_STUDYING_10_5_HPP

/**
 * @title
 * 10.5 泛型算法结构
 */

#include "10.hpp"

class Exercise_10_5 {
 public:
    /**
     * @title
     * 10.5.1 5类迭代器
     */
    /**
     * @title
     * 练习10.38
     * @description
     * 列出5个迭代器类别，以及每类迭代器所支持的操作。
     */
    /*
     * 输入迭代器：只读，不写；单遍扫描，只能递增；还支持相等性判定运算符（==、!=）、解引用运算符（*）（只出现在赋值运算符右侧）和箭头运算符（->）。
     *
     * 输出迭代器：只写，不读；单遍扫描，只能递增，支持解引用运算符（*）（只出现在赋值运算符左侧）。
     *
     * 前向迭代器：可读写；多遍扫描，只能递增，支持所有输入、输出迭代器的操作。
     *
     * 双向迭代器：可读写；多遍扫描，可递增递减，支持所有前向迭代器操作。
     *
     * 随机访问迭代器：可读写，多遍扫描，支持全部迭代器运算，除了上述迭代器类别支持的操作外，还有比较两个迭代器相对位置的关系运算符（<、<=、>和>=）、迭代器和一个整数值的加减运算（+、+=、-和-=）令迭代器在序列中前进或后退给定整数个元素、两个迭代器上的减法运算符（-）得到其距离以及下标运算符。
     */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习10.39
     * @description
     * list上的迭代器属于哪类？vector呢？
     */
    /*
     * list：双向迭代器
     * vector：随机访问呢迭代器
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习10.40
     * @description
     * 你认为copy要求哪类迭代器？reverse和unique呢？
     */
    /*
     * copy：输出迭代器
     * reverse：双向迭代器
     * unique：前向迭代器
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 10.5.2 算法形参模式
     */

    /**
     * @title
     * 练习10.41
     * @description
     * 仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
     * @code
     * replace(beg,end,old_val,new_val);
     * replace(beg,end,pred,new_val);
     * replace_copy(beg,end,dest,old_val,new_val);
     * replace(beg,end,dest,pred,new_val);
     */
    /*
     * 1. 在[beg,end)范围内，将old_val替换为new_val
     * 2. 在[beg,end)范围内，将pred所指定的元素替换为new_val
     * 3. 在[beg,end)范围内，将old_val替换为new_val，且将写入位置设定为dest
     * 4. 在[beg,end)范围内，将pred所指定的元素替换为new_val，且将写入位置设定为dest
     * */
    static void meaninglessFunction_4();
};

#endif  // CPP_PRIMER_STUDYING_10_5_HPP
