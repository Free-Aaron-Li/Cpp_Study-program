// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_11_2_HPP
#define CPP_PRIMER_STUDYING_11_2_HPP

/**
 * @title
 * 11.2 关联容器概述
 */

#include "11.hpp"

class Exercise_11_2 {
 public:
    /**
     * @title
     * 11.2.1 定义关联容器
     */
    /**
     * @title
     * 练习11.5
     * @description
     * 解释map和set的区别。你如何选择使用哪个？
     */
    /*
     * 需要查找给定值所对应的数据时，使用map。因为map保存的是<关键字,值>对
     * 仅需判断给定值是否正确时，使用set。set仅保存关键字
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习11.6
     * @description
     * 解释set和list的区别。你如何选择使用哪个？
     */
    /*
     * 如果需要顺序访问这些元素，或者按照位置访问，则选择list
     * 如果需要快速判定是否有元素等于给定值，则选择set
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习11.7
     * @description
     * 定义一个map,关键字是家庭的姓，值是一个vector,保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
     */
    static void exercise_11_7(const std::vector<std::string>& names);

    /**
     * @title
     * 练习11.8
     * @description
     * 编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？
     */
    static void exercise_11_8(const std::vector<std::string>& data);

    /**
     * @title
     * 11.2.2 关键字类型的要求
     */

    /**
     * @title
     * 练习10.9
     * @description
     * 定义一个map,将单词与一个行号的list关联，list中保存的是单词所出现的行号。
     */
    static void exercise_11_9();

    /**
     * @title
     * 练习11.10
     * @description
     * 可以定义一个vector<int>::iterator到int的map吗？list<int>::iterator到int的map呢？对于两种情况，如果不能，解释为什么？
     */
    /*
     * 对于vector::iterator可以，因为vector迭代器支持<操作，但是对于list::iterator则不行，因为List元素不是连续存储的，其迭代器不支持比操作。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习11.11
     * @description
     * 不使用decltype重新定义bookstore。
     */
    /*
     * multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 11.2.3 pair类型
     */

    /**
     * @title
     * 练习11.12
     * @description
     * 编写程序，读入string和int的序列，将每个string和int存入一个pair中，pair保存在一个vector中。
     */
    static void exercise_11_12();

    /**
     * @title
     * 练习11.13
     * @description
     * 在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？
     */
    /*
     * 私认为采用make_pair方式创建pair方式最好。其一、易于理解；其二、由编译器推断类型；
     * */
    static void exercise_11_13();

    /**
     * @title
     * 练习11.14
     * @description
     * 扩展你在11.2.1节练习中编写的孩子姓到名的map,添加一个pair的vector,保存孩子的名和生日。
     */
    static void exercise_11_14(const std::vector<std::string>& data);
};
#endif  // CPP_PRIMER_STUDYING_11_2_HPP
