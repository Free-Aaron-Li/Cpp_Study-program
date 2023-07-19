// This file is part of Cpp_Primer_Studying project.
// This program is called:7_6.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_6_HPP
#define CPP_PRIMER_STUDYING_7_6_HPP

/**
 * @title
 * 7.6 类的静态成员
 */

#include "7.hpp"

class Exercise_7_6 {
 public:
    /**
     * @title
     * 练习7.56
     * @description
     * 什么是类的静态成员？它有何优点？静态成员和普通成员有何区别？
     */
    /*
     * 类的静态成员是该类所有对象共享的成员，而不是特定于每个对象。
     * 静态成员在类定义中声明和定义，不依赖于任何对象实例，可以通过类名直接访问，无需创建对象。
     *
     * 静态成员具有以下优点：
     *      共享性：静态成员是所有对象共享的，因此它们可以存储类级别的信息，并且可以在所有对象之间共享。这使得在多个对象之间共享数据变得容易。
     *      全局性：静态成员可以通过类名直接访问，这意味着它们具有全局可见性。在某些情况下，这可以简化代码并提高代码的可读性。
     *      线程安全：由于静态成员不依赖于任何对象实例，因此它们在多线程环境中可能是线程安全的。如果需要跨线程共享数据，静态成员可能是一个好的选择。
     *
     * 静态成员和普通成员之间有以下区别：
     *      访问方式：静态成员可以通过类名直接访问，而普通成员需要通过对象实例来访问。
     *      绑定时间：静态成员在编译时绑定到类，而普通成员在运行时绑定到对象。
     *      可见性：静态成员具有全局可见性，可以在类的任何方法和成员函数中访问。普通成员只能在同一作用域中的其他成员函数中访问。
     *      生命周期：静态成员的生命周期与程序的整个生命周期相同，它们在所有对象之间共享。
     *      普通成员的生命周期与对象实例的生命周期相同，当对象被销毁时，它们的成员也被销毁。
     * 需要注意的是，静态成员不能被继承或封装，并且不能被作为虚函数的参数或返回值类型。
     */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.57
     * @description
     * 编写你自己的Account类。
     */
     static void exercise_7_57();

     /**
      * @title
      * 练习7.58
      * @description
      * 下面的静态数据成员的声明和定义有错误吗？请解释原因。
      * @code
      * // example.h
      * 1 | class Example{
      * 2 | public:
      * 3 |     static double rate=6.5;
      * 4 |     static const int vecSize=20;
      * 5 |     static vector<double> vec(vecSize);
      * 6 | }
      * 7 |
      * // example.c
      * 9 | #include "example.h"
      * 10| double Example::rate;
      * 11| vector<double> Example::vec;
      */
      /*
       * 有错误，
       * 在第10行，应该修改为“double Example::rate=6.5”，
       * 在第11行，应该修改为“static vector<double> Example::vec(Example::vecSize);
       * */
     static void meaninglessFunction_2();

};
#endif  // CPP_PRIMER_STUDYING_7_6_HPP
