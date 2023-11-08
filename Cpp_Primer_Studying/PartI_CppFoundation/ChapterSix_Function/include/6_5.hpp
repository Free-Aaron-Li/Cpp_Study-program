// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_5.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_5_HPP
#define CPP_PRIMER_STUDYING_6_5_HPP

/**
 * @title
 * 6.5 特殊用途语言特性
 */

#include "6.hpp"

class Exercise_6_5 {
 public:
    /**
     * @title
     * 练习6.40
     * @description
     * 下面的哪个声明是错误的？为什么？
     * @code
     * (a) int ff(int a,int b=0,int c=0);
     * (b) char *init(int ht=24,int wd,char bckgrnd);
     */
    /* b是错误的，为形参赋予默认值，其后所有形参都必须被赋予默认值 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习6.41
     * @description
     * 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
     * @code
     * char *init(int ht, int wd = 80, char bckgrnd = ' ');
     * (a) init();              (b) init(24,10);                (c) init(14,'*');
     */
    /* a的调用是非法的，init函数的第一个形参并没有被赋予默认值，必须在调用时传入实参;
     * c的调用是与程序员的初衷不符，init被调用时第二个形参传入的实参为char类型，不是int类型，实参值将会经过隐式转换赋给形参
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习6.42
     * @description
     * 给make_plural函数（参见6.3.2节）的第二个形参赋予默认实参's'，利用新版本的函数输出单词success和failure的单词的单数和复数形式。
     */
    static void exercise_6_42();

    /**
     * @title
     * 6.5.2节练习
     */

    /**
     * @title
     * 练习6.43
     * @description
     * 你会把下面当哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
     * (a) inline bool eq(const BigInt&,const BigInt&) { ... }
     * (b) void putValues(int *arr,int size);
     */
     /* 将a放在源文件中，b放在头文件中。因为a函数存在定义，b仅有声明，没有定义。 */
    static void meaninglessFunction_3();


    /**
     * @title
     * 练习6.44
     * @description
     * 将6.2.2节当isShorter函数改写成内联函数。
     */
     static void exercise_6_44();

     /**
      * @title
      * 练习6.45
      * @description
      * 回顾在前面当练习中你编写当那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。
      */
      /* 是 */
     static void meaninglessFunction_4();

     /**
      * @title
      * 练习6.46
      * @description
      * 能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constexpr函数；如果不能，说明原因。
      */
      /*  不能够，string对象的size方法并不是contempt函数 */
     static void meaninglessFunction_5();

     /**
      * @title
      * 6.5.3节练习
      * @description
      * 改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和
      * 关闭调试器的情况下编译并执行这个程序。
      */
      static void exercise_6_47();

      /**
       * @title
       * 练习5.48
       * @description
       * 说明下面这个循环的含义，它对assert的使用合理吗？
       * @code
       * string s;
       * while(cin >> s && s != sought) { }      // 空函数体
       * asset(cin);
       */
       /* 用于判断输入值是否为sought或者输入值是否为EOF，如果判断失败，则会执行assert函数。但是，这是不合理的，应该改成：
        * asset(!cin);asset(s==sought);
        * */
};
#endif  // CPP_PRIMER_STUDYING_6_5_HPP
