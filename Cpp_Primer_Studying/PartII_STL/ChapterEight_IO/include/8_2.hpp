// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_2.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_8_2_HPP
#define CPP_PRIMER_STUDYING_8_2_HPP

/**
 * @title
 * 8.2 文件输入输出
 */

#include "8.hpp"
#include <fstream>

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
       static void exercise_8_6(const std::string& str);

       /**
        * @title
        * 8.2.2节练习
        */

       /**
        * @title
        * 练习8.7
        * @description
        * 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。
        */
        static void exercise_8_7(const std::string& str_1,const std::string& str_2);

        /**
         * @title
         * 练习8.8
         * @description
         * 修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。
         */
         static void exercise_8_8(const std::string& str_1,const std::string& str_2);

};
#endif  // CPP_PRIMER_STUDYING_8_2_HPP
