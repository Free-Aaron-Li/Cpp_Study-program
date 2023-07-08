// This file is part of Cpp_Primer_Studying project.
// This program is called:7_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_2_HPP
#define CPP_PRIMER_STUDYING_7_2_HPP

/**
 * @title
 * 7.2 访问控制与封装
 */

#include "7.hpp"
#include "sales_data_private.hpp"

class Exercise_7_2 {
 public:
    /**
     * @title
     * 练习7.16
     * @description
     * 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？
     */
    /* 没有限定，作为接口的构造函数和一部分成员函数应该在public说明符之后，数据成员和作为实现部分的函数则应该在private说明符之后
     */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.17
     * @description
     * 使用class和struct时有区别吗？如果有，是什么？
     */
    /* 有，二者决定在第一个访问说明符之前定义的成员的访问权限，如果是class，则为private，如果是struct，则为public */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.18
     * @description
     * 封装是何含义？它有什么用处？
     */
    /* 通过访问说明符将类成员的具体实现进行隐藏，
     * 用处：
     * 1. 将成员与操作作为一个整体
     * 2. 通过不同的权限对成员和操作进行控制
     * 3. 成员属性私有化，防止随意修改成员
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.19
     * @description
     * 在你的Person类中，你将把哪些成员声明成public的？哪些成员声明成private的？解释你这样做的原因。
     */
    /* 详情查看include/person.hpp文件，具体原因参照练习7.16 */
};
#endif  // CPP_PRIMER_STUDYING_7_2_HPP
