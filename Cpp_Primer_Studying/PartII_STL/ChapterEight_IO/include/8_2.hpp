// This file is part of Cpp_Primer_Studying project.
// This program is called:8_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_8_2_HPP
#define CPP_PRIMER_STUDYING_8_2_HPP

/**
 * @title
 * 8.2 文件输入输出
 */

#include "8.hpp"

class Exercise_8_2{
 public:
    /**
     * @title
     * 8.2.1节联系
     */

    /**
     * @title
     * 联系8.4
     * @description
     * 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存入vector中。
     */
     static void exercise_8_4();

     /**
      * @title
      * 练习8.5
      * @description
      * 重写上面的程序，将每个单词作为一个独立的元素进行存储
      */
      static void exercise_8_5();

      /**
       * @title
       * 练习8.6
       * @description
       * 重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。
       */
       static void exercise_8_6();

};
#endif  // CPP_PRIMER_STUDYING_8_2_HPP
