// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

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

    /**
     * @title
     * 13.2.1 行为像值的类
     */

    /**
     * @title
     * 练习13.23
     * @description
     * 比较上一节练习中你编写的拷贝控制成员和这一节的代码。确定你理解了你的代码和我们的代码之间的差异（如果有的话）
     */
    /*
     * 在编写拷贝赋值运算符时，并没有采取一个正确顺序。
     * 在将右侧运算对象拷贝到临时对象前，先释放了当前对象中的内存。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习13.24
     * @description
     * 如果本节中的HasPtr版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？
     */
    /*
     * 如果未定义析构函数，在销毁对象时合成的析构函数不会释放_ps指向的内存，造成内存泄露。
     * 如果未定义拷贝构造函数，在拷贝对象时，合成的拷贝构造函数仅会简单赋值_ps成员，使得两个Has_Ptr指向相同的string。
     * 形成行为像指针的类。如果其中一个对象_ps指向的string被销毁，另一个对象的_ps成为空悬指针。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习13.25
     * @description
     * 假定希望定义StrBlob的类值版本，而且我们希望继续使用shared_ptr,这样我们的StrBlobPtr类就仍能使用指向vector的weak_ptr了。
     * 你修改后的类将需要一个拷贝构造函数和一个拷贝赋值运算符，但不需要析构函数。解释拷贝构造函数和拷贝赋值函数运算符必须要做什么。
     * 解释为什么不需要析构函数。
     */
    /*
     * 拷贝构造函数和赋值运算符中应该将数据各拷贝一份，而不是仅仅拷贝shared_ptr，这样得到的对象仍然指向同一个vector。
     * 不需要析构函数是因为其管理的全部资源仅有string的vector,其由shared_ptr负责管理。当对象被销毁时，会自动调用shared_ptr的析构函数，
     * 其会正确调整引用计数，当计数为0时，自动释放资源。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习13.26
     * @description
     * 对上一题中描述的StrBlob类，编写你自己的版本。
     */
    /*
     * 参考：https://github.com/jaege/Cpp-Primer-5th-Exercises/tree/master/ch13/13.26
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 13.2.2 定义行为像指针的类
     */

    /**
     * @title
     * 练习13.27
     * @description
     * 定义你自己的使用引用版本的HasPtr。
     */
    /*
     * 查看：Has_Ptr.hpp文件下Like_pointer_HasPtr类
     * */
    static void meaninglessFunction_5();


    /**
     * @title
     * 练习13.28
     * @description
     * 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
     */
    static void exercise_13_28();
};
#endif  // CPP_PRIMER_STUDYING_13_2_HPP
