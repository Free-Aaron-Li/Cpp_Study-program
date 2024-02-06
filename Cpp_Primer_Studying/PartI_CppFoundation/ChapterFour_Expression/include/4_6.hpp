// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_6_HPP
#define CPP_PRIMER_STUDYING_4_6_HPP

/**
 * @title
 * 4.6 成员访问运算符
 */

#include "4.hpp"

class Exercise_4_6 {
public:
  /**
   * @title
   * 练习4.20
   * @description
   * 假设iter的类型是vector<string>::iterator，说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
   * @code
   * (a) *iter++;             (b) (*iter)++;              (c) *iter.empty()
   * (d) iter->empty();       (e) ++*iter;                (f) iter++->empty();
   */
  /* a：合法，后置递增运算符的优先级高于解引用运算符，等价于：*(iter++)。
   * b：不合法，解引用iter所指向的vector元素，但由于其元素的类型为string，无法加1。
   * c：不合法，点运算符优先级高于解引用运算符，迭代器中并没有empty函数。
   * d：合法，iter指向的是string类型的vector，string类型对象含有empty方法。
   * e：不合法，虽然前置递增运算符的优先级高于解引用运算符，但是其执行顺序参考由内向外，先解引用iter指向的string类型对象，再进行自加。string类型无法自加，错误。
   * f:合法，箭头运算符优先级高于后置递增运算符，所以先执行iter指向的string类型对象进行empty方法，再对iter进行自加。
   * */
  static void meaninglessFunction_4_20();
};
#endif // CPP_PRIMER_STUDYING_4_6_HPP
