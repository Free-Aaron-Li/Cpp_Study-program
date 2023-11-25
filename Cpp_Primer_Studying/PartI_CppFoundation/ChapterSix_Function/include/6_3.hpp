// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_3.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_3_HPP
#define CPP_PRIMER_STUDYING_6_3_HPP

/**
 * @title
 * 6.3 返回类型和return语句
 */

#include "6.hpp"

class Exercise_6_3 {
 public:
    /**
     * @title
     * 6.3.2节练习
     */

    /**
     * @title
     * 练习6.30
     * @description
     * 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。
     */
    /* 在g++8.3上：
     * 错误：在返回‘bool’的函数中，返回语句不带返回值 [-fpermissive]
     * return;
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习6.31
     * @description
     * 什么情况下返回的引用无效？什么情况下返回常量的引用无效？
     */
    /* 返回的引用为局部对象的引用，返回的常量引用是局部常量引用 */
    static void meaninglessFunction_2();


    /**
     * @title
     * 练习6.32
     * @description
     * 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
     * @code
     * int &get(int *arry,int index) {return arry[index];}
     * int main(){
     *      int ia[10];
     *      for(int i=0;i!=10;++i){
     *          get(ia,i)=i;
     *      }
     */
    /* 合法 */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习6.33
     * @description
     * 编写一个递归函数，输出vector对象的内容。
     */
    static void exercise_6_33();

    /**
     * @title
     * 练习6.34
     * @description
     * 如果factorial函数的停止条件如下所示，将发生什么情况？
     * if(val!=0)
     */
    /* 如果传入的实参大于0，最后结果为0，最后结果为1*1*2*3*...*val
     * 如果传入的实参小于0，程序将会一直执行，直到空间内容存满
     * */
    static void meaninglessFunction_4();


    /**
     * @title
     * 练习6.35
     * @description
     * 在调用factorial函数时，为什么我们传入的值是val-1而非val--？
     */
    /* 如果我们传入val--，那么相当于val在返回语句中factorial函数中一直没有变化，程序将会一直执行直到内存已满 */
    static void meaninglessFunction_5();

    /**
     * @title
     * 6.3.3节练习
     */

    /**
     * @title
     * 练习6.36
     * @description
     * 编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。不要使用尾置返回类型、decltype或者类型别名。
     */
    static void exercise_6_36();

    /**
     * @title
     * 练习6.37
     * @description
     * 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？
     */
    /* 使用尾置返回类型方式最为方便，因为任何函数的定义都能够使用尾置返回且尾置返回简单易懂。类型别名需要多写一行且使用过程中需要注意类型别名名称；decltype关键字需要提前知道返回类型指向那个数组且还需要手动添加*
     */
    static void exercise_6_37();

    /**
     * @title
     * 练习6.38
     * @description
     * 修改arrPtr函数，使其返回数组的引用。
     */
    static void exercise_6_38();
};
#endif  // CPP_PRIMER_STUDYING_6_3_HPP
