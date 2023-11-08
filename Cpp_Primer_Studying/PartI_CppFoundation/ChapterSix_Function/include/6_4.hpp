// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_4.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_4_HPP
#define CPP_PRIMER_STUDYING_6_4_HPP

/**
 * @title
 * 6.4 函数重载
 */

#include "6.hpp"

class Exercise_6_4 {
 public:
    /**
     * @title
     * 练习6.39
     * @description
     * 说明在下面声明中第二条声明语句是何含义。如果有非法的声明，请指出来。
     * @code
     * (a) int calc(int,int);
     *     int calc(const int,const int);
     * (b) int get();
     *     double get();
     * (c) int *reset(int *);
     *     double *reset(double *);
     */
    /* b非法，函数重载需要函数名相同，函数的形参列表中参数数量或者参数类型不尽相同 */
    static void meaninglessFunction_1();
};
#endif  // CPP_PRIMER_STUDYING_6_4_HPP
