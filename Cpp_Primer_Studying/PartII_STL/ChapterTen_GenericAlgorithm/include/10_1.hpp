// This file is part of Cpp_Primer_Studying project.
// This program is called:10_1.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_10_1_HPP
#define CPP_PRIMER_STUDYING_10_1_HPP

/**
 * @title
 * 10.1 概述
 */

#include "10.hpp"

class Exercise_10_1{
 public:
    /**
     * @title
     * 10.1 概述
     */

    /**
     * @title
     * 练习10.1
     * @description
     * 头文件algorithm定义了一个名为count的函数，它类似find,接受一对迭代器和一个值作为参数。
     * count返回给定值在序列中出现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。
     */
     static void exercise_10_1();

     /**
      * @title
      * 练习10.2
      * @description
      * 重做上一题，但读取string序列存入list中。
      */
      static void exercise_10_2();

};

#endif  // CPP_PRIMER_STUDYING_10_1_HPP
