// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_13_2_HPP
#define CPP_PRIMER_STUDYING_13_2_HPP

/**
 * @title
 * 13.2 拷贝控制的资源管理
 */

#include "Has_Ptr.hpp"
#include "13.hpp"

class Exercise_13_2 {
 public:
    /**
     * @title
     * 13.2.0
     */

    /**
     * @title
     * 练习13.22
     * @description
     * 假定我们希望HasPtr的行为像一个值。即，对于对象所指向的string成员，每个对象有一份自己的拷贝。
     * 我们将在下一节介绍拷贝控制成员的定义。但是，你已经学会了定义这些成员所需的所有只是。在继续学习下一节之前，
     * 为HasPtr编写拷贝构造函数和拷贝赋值运算符。
     */
    static void exercise_13_22();
};
#endif  // CPP_PRIMER_STUDYING_13_2_HPP
