// This file is part of Cpp_Primer_Studying project.
// This program is called:10_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_10_2_HPP
#define CPP_PRIMER_STUDYING_10_2_HPP

/**
 * @title
 * 10.2 初识泛型算法
 */

#include "10.hpp"

class Exercise_10_2 {
 public:
    /**
     * @title
     * 10.2.1 只读算法
     */

    /**
     * @title
     * 练习10.3
     * @description
     * 用accumulate求一个vector<int>中元素之和。
     */
    static void exercise_10_3();

    /**
     * @title
     * 练习10.4
     * @description
     * 假定v是一个vector<double>，那么调用accumulate(v.cbegin(),v.cend(),0)有何错误（如果存在的话）？
     */
    /* 结果仍然为int类型，发生精度损失 */
    static void exercise_10_4();

    /**
     * @title
     * 练习10.5
     * @description
     * 在本节对名册（roster)调用equal的例子中，如果两个名册中保存的都是C风格字符串而不是string,会发生什么？
     */
     /*
      * 在equal算法的说明中提到：
      * This compares the elements of two ranges using == and returns true or false depending
      * on whether all of the corresponding elements of the ranges are equal.
      * 虽然没有提到是否是 operator == ，但是实际上equal算法重载了==运算符。所以无论是C风格字符串还是string,其比较的都是元素，而非地址值。
      * */
     static void exercise_10_5();

};

#endif  // CPP_PRIMER_STUDYING_10_2_HPP
