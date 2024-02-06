// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_7.
// If there are no special instructions, this file is used as an exercise and
// test file.

#ifndef CPP_PRIMER_STUDYING_6_7_HPP
#define CPP_PRIMER_STUDYING_6_7_HPP

/**
 * @title
 * 5.7 函数指针
 */

#include "6.hpp"

class Exercise_6_7 {
public:
  /**
   * @title
   * 练习6.54
   * @description
   * 编写函数的声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。
   */
  static void exercise_6_54();

  /**
   * @title
   * 练习6.55
   * @description
   * 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。
   */
  static void exercise_6_55();

  /**
   * @title
   * 练习6.56
   * @description
   * 调用上述vector对象中的每个元素并输出其结果。
   */
  /* 具体实现可以看上一个练习 */
  static void meaninglessFunction_1();
};
#endif // CPP_PRIMER_STUDYING_6_7_HPP
