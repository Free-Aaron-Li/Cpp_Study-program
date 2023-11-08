// This file is part of Cpp_Primer_Studying project.
// This program is called:7_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
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
     * 7.2.0节练习
     */

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

    /**
     * @title
     * 7.2.1节练习
     */

    /**
     * @title
     * 练习7.20
     * @description
     * 友元在什么时候有用？请分别列举出使用友元的利弊。
     */
    /* 函数需要调用的类中成员为private的时候，通过将该函数设定为友元允许访问类中成员
     * 友元的优点包括：
     *
     * 增强代码的可读性和可维护性：友元函数或类可以在需要时访问另一个类的私有成员，这使得代码更加清晰易读，并且便于维护。
     * 提高代码的复用性：友元函数或类可以在需要时重用另一个类的私有成员，这提高了代码的复用性。
     * 方便实现多态：友元函数可以在继承关系中访问基类的私有成员，这使得多态更加容易实现。
     *
     * 然而，友元也有一些缺点：
     *
     * 破坏了封装性：使用友元意味着将类的私有成员暴露给外部，这可能会破坏类的封装性，导致代码的可信度降低。
     * 可能导致安全性问题：由于友元函数或类可以访问类的私有成员，这可能会导致安全性问题，例如在友元函数中修改类的私有成员可能会导致不可预期的行为。
     * 可能导致代码的可读性和可维护性问题：如果使用过多的友元，可能会导致代码的复杂性增加，降低代码的可读性和可维护性。
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习7.21
     * @description
     * 修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。
     */
    /* 具体查看include/sales_data_private.hpp文件，并未重新修改7_1.cpp中文件，以确保之前练习的合理性。 */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习7.22
     * @description
     * 修改你的Person类使其隐藏实现的细节。
     */
    /* 具体查看include/person.hpp文件 */
    static void meaninglessFunction_6();
};
#endif  // CPP_PRIMER_STUDYING_7_2_HPP
