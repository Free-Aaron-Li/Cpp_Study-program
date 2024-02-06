// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_4'.
// If there are no special instructions, this file is used as an exercise and
// test file.
#ifndef CPP_PRIMER_STUDYING_13_4_HPP
#define CPP_PRIMER_STUDYING_13_4_HPP

/**
 * @title
 * 13.4 拷贝控制示例
 */

#include "13.hpp"
#include "Folder.hpp"
#include "Message.hpp"

class Exercise_13_4 {
public:
  /**
   * @title
   * 13_4 拷贝控制示例
   */

  /**
   * @title
   * 练习13.33
   * @description
   * 为什么Message的成员save和remove的参数是一个Folder&？
   * 为什么我们不将参数定义为Folder或是const Folder&？
   */
  /*
   * 需要将给定Folder指针添加到当前Message的folders集合中。否则在save中将实参拷贝给形参，集合中得到的是一个未知指针。
   * 由于需要调用addMsg和remMsg函数，将当前Message添加（删除）到Folder的messages集合中，需要修改Folder内容，所以不能是const。
   * */
  static void meaninglessFunction_1();

  /**
   * @title
   * 练习13.34
   * @description
   *编写本节所描述的Message。
   */
  /*
   * 查看 include/Message.hpp
   * */
  static void meaninglessFunction_2();

  /**
   * @title
   * 练习13.35
   * @description
   * 如果Message使用合成的拷贝控制成员，将会发生什么？
   */
  /*
   * Message类仅存在string类型的content，和set类型的folders。二者都具有完备的拷贝控制成员，
   * 但是本类中进行拷贝时不仅是简单的拷贝，还需要将Message添加如每个Folder中。
   * 如果使用合成拷贝，那么不能让每个Folder与Message副本相联系。
   * */
  static void meaninglessFunction_3();

  /**
   * @title
   * 练习13.36
   * @description
   * 设计并实现对应的Folder类。此类应该保存一个指向Folder中包含的Message的set。
   */
  /*
   * 查看 include/Folder.hpp
   * */
  static void meaninglessFunction_4();

  /**
   * @title
   * 练习13.37
   * @description
   * 为Message类添加成员，实现向folders添加或删除一个给定的Folder*。
   * 这两个成员类似Folder类的addMsg和remMsg操作。
   */
  /*
   * 查看 include/Message.hpp:
   * - add_Folder(Folder& folder)
   * - remove_Folder(Folder& folder)
   * */
  static void meaninglessFunction_5();

  /**
   * @title
   * 练习13.38
   * @description
   * 我们并未使用拷贝和交换方式设计Message的赋值运算符。你认为其原因是什么？
   */
  /*
   * 1．由于赋值运算符的参数是Message类型，因此会将实参拷贝给形参rhs，这会触发拷贝构造函数，
   * 将实参的contents和folders拷贝给rhs，并调用add_to_Folders将rhs添加到folders的所有文件夹中。
   * 2．随后赋值运算符调用swap交换*this和rhs，首先遍历两者的folders，将它们从自己的文件夹中删除；
   * 然后调用string和set的swap交换它们的contents和folders；最后，再遍历两者新的folders，将它们分别添加到自己的新文件夹中。
   * 3.
   * 最后，赋值运算符结束，rhs被销毁，析构函数调用remove_from_Folders将rhs从自己的所有文件夹中删除。
   * 显然，语义是正确的，达到了预期目的。但效率低下，rhs创建、销毁并两次添加、删除是无意义的。
   * 而采用拷贝赋值运算符的标准编写方式，形参rhs为引用类型，就能避免这些冗余操作，具有更好的性能。
   * */
  static void meaninglessFunction_6();
};
#endif // CPP_PRIMER_STUDYING_13_4_HPP
