// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:7_4.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_7_4_HPP
#define CPP_PRIMER_STUDYING_7_4_HPP

/**
 * @title
 * 7.4 类的作用域
 */

#include "7.hpp"

class Exercise_7_4 {
 public:
    /**
     * @title
     * 练习7.33
     * @description
     * 如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
     * pos Screen::size() const
     * {
     *      return height*width;
     * }
     */
    /* 返回类型属于类的成员，需要添加类作用域。修改为：Screen::pos Screen::size() const{} */
    static void meaninglessFunction_1();

    /**
     * @title
     * 7.4.1节练习
     */

    /**
     * @title
     * 练习7.34
     * @description
     * 如果我们把第236页Screen类的pos的typedef放在类的最后一行会发生什么情况？
     */
    /*
     * 对于类全部可见后才能编译函数体，这种只适用于成员函数中的名字，对于声明中使用的名字，包括返回类型或者参数列表中使用的名字，
     * 都必须在使用之前确保可见。如果没有找到对应名字的声明，那么编译器会在定义该类的作用域中继续查找，但是注意：编译器只会考虑在使用该函数之前的声明，
     * 所以，由于post声明在类的最后一行，编译器无法找到pos的声明变化报错。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.35
     * @description
     * 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
     * @code
     * 1 | typedef string Type;
     * 2 | Type initVal();
     * 3 | class Exercise(){
     * 4 | public:
     * 5 |      typedef double Type;
     * 6 |      Type setVal(Type);
     * 7 |      Type initVal();
     * 8 | private:
     * 9 |      int val;
     * 10| };
     * 11| Type Exercise::setVal(Type parm){
     * 12|      val=parm+initVal();
     * 13|      return val;
     * 14| }
     */
    /*
     * Type：
     * 全局作用域下，Type表示string
     * Exercise作用域下，Type表示string，类中不能够重新定义在外层作用域中已经定义的名字。
     * initVal：
     * 2处使用的是全局作用域下的定义
     * 7处使用的是Exercise作用域下的定义
     * 11处使用的是Exercise作用域下的定义
     *
     * 应该将第5行删除。
     * */
};
#endif  // CPP_PRIMER_STUDYING_7_4_HPP
