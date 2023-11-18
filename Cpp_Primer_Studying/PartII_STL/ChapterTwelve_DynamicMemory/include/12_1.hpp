// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_12_1_HPP
#define CPP_PRIMER_STUDYING_12_1_HPP

/**
 * @title
 * 12.1 动态内存与智能指针
 */

#include "12.hpp"

class Exercise_12_1 {
 public:
    /**
     * @title
     * 12.1.1 shared_ptr类
     */

    /**
     * @title
     * 练习12.1
     * @description
     * 在此代码的结尾，b1和b2各包含多少个元素？
     * @code
     * StrBlob b1;
     * {
     *      StrBlob b2 = {"a", "an", "the"};
     *      b1=b2;
     *      b2.push_back("about");
     * }
     */
    /*
     * b1与b2一致，包含4个元素
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习12.2
     * @description
     * 编写你自己的StrBlob类，包含const版本的front和back。
     */
    static void exercise_12_2();
};
#endif  // CPP_PRIMER_STUDYING_12_1_HPP
