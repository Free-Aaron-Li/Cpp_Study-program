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

    /**
     * @title
     * 练习12.3
     * @description
     * StrBlob需要const版本的push_back和pop_back吗？如果需要，添加进去。否则，解释为什么不需要。
     */
    /*
     * push_back和pop_back的语义分别是向StrBlob对象共享的vector对象增删元素。
     * 因此，我们不应该为其重载const版本，因为常量StrBlob对象不应该被允许修改共享vector对象内容。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习12.4
     * @description
     * 在我们的check函数中，没有检查i是否大于0。为什么可以忽略这个检查？
     */
    /*
     * i为无符号类型。即i为非负数，所以不需要检查小于0的情况。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习12.5
     * @description
     * 我们未编写接受一个initializer_list explicit参数的构造函数。讨论这个设计策略的优点和缺点。
     */
    /*
     * 未编写接受一个初始化列表参数的显示构造函数，意味着可以进行列表向StrBlob的隐式转换，即可以在需要该类型的地方可以使用列表进行替代。
     * 而且，可以进行拷贝形式的初始化（如赋值）。这令程序编写更为简单方便。
     * 但是这种隐式转换并不是总是好的。例如，列表中可能并非都是合法的值。再比如，对于接受StrBlob的函数，传递给它一个列表，会去创建一个临时的StrBlob对象并用列表对其初始化，然后将其传递给函数，当函数完成后，此对象将被丢弃并且再也无法访问。对于这些情况，定义显示构造函数是解决方法。
     * */
    static void meaninglessFunction_4();
};
#endif  // CPP_PRIMER_STUDYING_12_1_HPP
