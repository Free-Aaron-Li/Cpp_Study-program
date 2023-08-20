// This file is part of Cpp_Primer_Studying project.
// This program is called:9_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_9_5_HPP
#define CPP_PRIMER_STUDYING_9_5_HPP

/**
 * @title
 * 9.5 额外的string操作
 */

#include "9.hpp"

class Exercise_9_5{
 public:
    /**
     * @title
     * 9.5.1 构造string的其他方法 练习
     */

    /**
     * @title
     * 练习9.41
     * @description
     * 编写程序，从一个vector<char>初始化一个string。
     */
     static void exercise_9_41();

     /**
      * @title
      * 练习9.42
      * @description
      * 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？
      */
      static void exercise_9_42();

      /**
       * @title
       * 9.5.2 改变string的其他方法 练习
       */

      /**
       * @title
       * 练习9.43
       * @description
       * 编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器及
       * insert和erase函数将s中所有oldVal替换为newVal.测试你的程序，用它替换通用的简写形式，
       * 如，将“tho”替换为“though”，将“thru”替换为“through”。
       */
       static void exercise_9_43();

       /**
        * @title
        * 练习9.44
        * @description
        * 重写上一题的函数，这次使用一个下标和replace。
        */
        static void exercise_9_44();

};
#endif  // CPP_PRIMER_STUDYING_9_5_HPP