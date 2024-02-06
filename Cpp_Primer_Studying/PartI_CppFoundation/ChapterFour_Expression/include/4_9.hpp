// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_9_HPP
#define CPP_PRIMER_STUDYING_4_9_HPP

/**
 * @title
 * 4.9 sizeof运算符
 */

#include "4.hpp"

class Exercise_4_9 {
public:
  /**
   * @title
   * 练习4.28
   * @description
   * 编写一段程序，输出每一种内置类型所占空间的大小。
   */
  static void exercise_4_28();

  /**
   * @title
   * 练习4.29
   * @description
   * 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？
   * @code
   * int x[10]; int *p=x;
   * cout<<sizeof(x)/sizeof(*p)<<endl;
   * cout<<sizeof(p)/sizeof(*p)<<endl;
   */
  /* 第一个输出语句：输出10，sizeof(x)得到的是int类型数组中所有元素类型大小的和，为20；sizeof(*x)得到的是指针p所指向的对象的类型int的大小，为2。所以其结果为10。
   * 第二个输出语句：输出0，sizeof(p)得到的是指针所占空间的大小，为2，sizeof(*p)前面已经说过为2，所以结果为0。
   *
   * 错误，首先int类型为4字节，指针类型为8字节。所以答案应该为10，2
   * */
  static void exercise_4_29();

  /**
   * @title
   * 练习4.30
   * @description
   * 根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后表达式的含义与原来的含义相同。
   * @code
   * (a) sizeof x + y              (b) sizeof p->mem[i]
   * (c) sizeof a < b              (d) sizeof f()
   */
  /* a：(sizeof x)+y
   * b：sizeof(p->mem[i])
   * c：(sizeof a) < b
   * d：sizeof (f())
   * */
  static void meaninglessFunction_1();
};
#endif // CPP_PRIMER_STUDYING_4_9_HPP
