// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.
*@author AaronLi *@data 2023 - 06 - 03 - 下午6 : 44 * @license GPL -
    3.0 * /

#ifndef CPP_PRIMER_3_6_HPP
#define CPP_PRIMER_3_6_HPP

/**
 * @title
 * 3.6 多维数组
 */

#include <iostream>
#include <string>
#include <vector>

        class Exercise_3_6 {
public:
  /**
   * @title
   * 3.6节练习
   */

  /**
   * @title
   * 练习3.43
   * @description
   * 编写3个不同版本的程序，令其均能输入ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通的for语句，其中版本2要求用下标运算符，版本3要求用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。
   */
  static void exercise_3_43();

  /**
   * @title
   * 练习3.44
   * @description
   * 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
   */
  static void exercise_3_44();

  /**
   * @title
   * 练习3.45
   * @description
   * 再次改写程序，这次使用auto关键字
   */
  static void exercise_3_45();
};
#endif // CPP_PRIMER_3_6_HPP
