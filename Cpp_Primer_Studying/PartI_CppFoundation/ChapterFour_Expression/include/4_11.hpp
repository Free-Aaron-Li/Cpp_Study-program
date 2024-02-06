// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_11_HPP
#define CPP_PRIMER_STUDYING_4_11_HPP

/**
 * @title
 * 4.11 类型转换
 */

#include "4.hpp"

class Exercise_4_11 {
public:
  /**
   * @title
   * 4.11.1节练习
   */

  /**
   * @title
   * 练习4.34
   * @description
   * 根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换：
   * @code
   * float fval; double dval; int ival; char cval;
   * (a) if (fval)                (b) dval=fval+ival;
   * (c) dval+ival*cval;
   */
  /* a：fval如果为0，则转换为布尔类型，且值为false；否则转换为布尔类型，值为true。
   * b：ival将转换为float类型，与fval值相加得到float类型的初始值，初始值类型转换为double类型并赋值给dval。
   * c：cval将提示为int类型，并与ival相加得到int类型值，再转换为double类型与dval相加。
   * */
  static void exercise_4_34();

  /**
   * @title
   * 练习4.35
   * @description
   * 假设有如下的定义，<br>
   * char cval;&emsp;int ival;&emsp;unsigned int ui;<br>
   * float fval;&emsp;double dval;<br>
   * 请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
   * @code
   * (a) cval='a'+3;             (b) fval=ui-ival*1.0;
   * (c) dval=ui*fval;           (d) cval=ival+fval+dval;
   */
  /* a：发生了，'a'字面值转为int类型并与3相加得到初始值，初始值再转换为char类型赋值给cval。
   * b：发生了，ival转换为double类型，ui转换为double类型，得到的初始值转换为float类型。
   * c：发生了，ui转换为float类型，初始值转换为double类型。
   * d：发生了，ival、fval转换为double类型，初始值转换为char类型。
   * */
  static void meaninglessFunction_1();

  /**
   * @title
   * 4.11.3节练习
   */

  /**
   * @title
   * 练习4.36
   * @description
   * 假设i是int类型，d是double类型，书写表达式i*=d使其执行整数类型的乘法而非浮点类型的乘法。
   */
  /* i*=static_cast<int>d */
  static void meaninglessFunction_2();

  /**
   * @title
   * 练习4.37
   * @description
   * 用命名的强制类型转换改写下列旧式的转换语句。
   * @code
   * int i; double d; const string *ps; char *pc; void *pv;
   * (a) pv=(void*)ps;                (b) i=int(*pc);
   * (c) pv=&d;                       (d) pc=(char *)pv;
   */
  /* a：pv=static_cast<void *>ps;
   * b：i=static_cast<int>*pc;
   * c：pv=static_cast<void *>d;
   * d：pc=static_cast<char *>pv;
   * */
  static void meaninglessFunction_3();

  /**
   * @title
   * 练习4.38
   * @description
   * 说明下面这条表达式的含义。
   * @code
   * double slope=static_cast<double>(j/i);
   */
  /* 将j/i得到的字面值强制类型转换为double类型赋值给slope */
  static void meaninglessFunction_4();
};
#endif // CPP_PRIMER_STUDYING_4_11_HPP
