// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

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
};
#endif  // CPP_PRIMER_STUDYING_11_2_HPP
