// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_3.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_8_3_HPP
#define CPP_PRIMER_STUDYING_8_3_HPP

/**
 * @title
 * 8.3 string流
 */

#include <fstream>
#include <sstream>

#include "8.hpp"

class Exercise_8_3 {
 public:
    /**
     * @title
     * 8.3.1节练习
     */

    /**
     * @title
     * 练习8.9
     * @description
     * 使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。
     */
    static void exercise_8_9();

    /**
     * @title
     * 练习8.10
     * @description
     * 编写程序，将来自一个文件中的行保存在一个vector<string>中。然后使用一个istringstream从
     * vector读取数据元素，每次读取一个单词。
     */
    static void exercise_8_10();

    /**
     * @title
     * 练习8.11
     * @description
     * 本节的程序在外层while循环中定义了istringstream对象。如果record对象定义在循环之外，
     * 你需要对程序进行怎样的修改？重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。
     */
    static void exercise_8_11();

    /**
     * @title
     * 练习8.12
     * @description
     * 我们为什么没有在PersonInfo中使用类内初始化？
     */
     /* 没必要，string类型的name和元素类型为string的vector类型phones都会在使用时进行初始化 */
    static void meaninglessFunction_1();


    /**
     * @title
     * 8.3.2节练习
     */

    /**
     * @title
     * 练习8.13
     * @description
     * 重写本节的电话号码程序，从一个命名文件而非cin读取数据
     */
     static void exercise_8_13();

     /**
      * @title
      * 练习8.14
      * @description
      * 我们为什么将entry和nums定义为const auto&？
      */
      /*
       * 范围for语句中遍历的分别是PersonInfo类类型和string类型的vector，
       * 为了避免拷贝带来的不必要资源消耗，所以用引用的方式。
       * 同时，遍历的目的仅进行读操作，所以添加const。
       * */
     static void meaninglessFunction_2();
};
#endif  // CPP_PRIMER_STUDYING_8_3_HPP
