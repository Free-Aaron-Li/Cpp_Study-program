// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.
*@author AaronLi *@data 2023 - 05 - 30 - 下午8 : 00 * @license GPL -
    3.0 * /

#ifndef CPP_PRIMER_3_4_HPP
#define CPP_PRIMER_3_4_HPP

/**
 * @title
 * 3.4 迭代器介绍
 */

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

        class Exercise_3_4 {
public:
  /**
   * @title
   * 3.4.1节练习
   */

  /**
   * @title
   * 练习3.21
   * @description
   * 请使用迭代器重做3.3.3节的第一个练习
   */
  static void outputVector();

  /**
   * @title
   * 练习3.22
   * @description
   * 修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后再输出它。
   */
  static void outputText();

  /**
   * @title
   * 练习3.23
   * @description
   * 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值变成原来的两倍。输出vector对象的内容，检验程序是否正确。
   */
  static void iterateVector();

  /**
   * @title
   * 3.4.2节练习
   */

  /**
   * @title
   * 练习3.24
   * @description
   * 请使用迭代器重做3.3.3节的最后一个练习。
   */
  static void outputVector2();

  /**
   * @title
   * 练习3.25
   * @description
   * 3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。
   */
  static void exercise_3_25();

  /**
   * @title
   * 练习3.23
   * @description
   * 在100页的二分搜索程序中，为什么用的是mid=beg+(end-beg)/2，而非mid=(beg+end)/2？
   */
  /* beg是无法和end进行加法 */
};

#endif // CPP_PRIMER_3_4_HPP
