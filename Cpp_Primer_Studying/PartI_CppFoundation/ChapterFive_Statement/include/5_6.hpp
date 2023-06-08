// This file is part of Cpp_Primer_Studying project.
// This program is called:5_6.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_6_HPP
#define CPP_PRIMER_STUDYING_5_6_HPP

/**
 * @title
 * 5.6 try语句块和异常处理
 */

#include "5.hpp"
#include <stdexcept>

class Exercise_5_6{
 public:
    /**
     * @title
     * 5.6.3节练习
     */

    /**
     * @title
     * 练习5.23
     * @description
     * 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
     */
     static void exercise_5_23();

     /**
      * @title
      * 练习5.24
      * @description
      * 修改您的程序，使得当第二个数是0时抛出异常。先不要设定catch字句，运行程序并真的为除数输入0，看看会发生什么？
      */
      static void exercise_5_24();

      /**
       * @title
       * 练习5.25
       * @description
       * 修改上一题的程序，使用try语句块取捕获异常。catch字句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。
       */
       static void exercise_5_25();
};
#endif  // CPP_PRIMER_STUDYING_5_6_HPP
