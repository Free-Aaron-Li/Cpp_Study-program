// This file is part of Cpp_Primer_Studying project.
// This program is called:10_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_10_3_HPP
#define CPP_PRIMER_STUDYING_10_3_HPP

/**
 * @title
 * 10.3 定制操作
 */

#include "10.hpp"
#include "sales_data_private_10.hpp"

class Exercise_10_3 {
 public:
    /**
     * @title
     * 10.3.1 向算法传递函数
     */

    /**
     * @title
     * 练习10.11
     * @description
     * 编写程序，使用stable_sort和inShorter将传递给你的elimDups版本的vector排序。
     * 打印vector的内容，验证你的程序的正确性。
     */
     static void exercise_10_11();

     /**
      * @title
      * 练习10.12
      * @description
      * 编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()成员。使用这个函数排序一个保存Sales_data对象的vector。
      */
      static void exercise_10_12();

      /**
       * @title
       * 练习10.13
       * @description
       * 标准库定义了名为partition的算法，他接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分，而使谓词为false的值会排在后半部分。
       * 算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置。编写函数，接受一个string,返回一个bool值，指向string是否有5个或更多字符。使用此
       * 函数划分words。打印出长度大于等于5的元素。
       */
      static void exercise_10_13();

};

#endif  // CPP_PRIMER_STUDYING_10_3_HPP
