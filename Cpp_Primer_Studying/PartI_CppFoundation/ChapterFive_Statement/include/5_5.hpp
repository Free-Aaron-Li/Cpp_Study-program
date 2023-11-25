// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_5_HPP
#define CPP_PRIMER_STUDYING_5_5_HPP

/**
 * @title
 * 5.5 跳转语句
 */

#include "5.hpp"

class Exercise_5_5 {
 public:
    /**
     * @title
     * 5.5.1节练习
     */

    /**
     * @title
     * 练习5.20
     * @description
     * 编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用while循环一次读取一个单词，
     * 当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
     */
    static void exercise_5_20();

    /**
     * @title
     * 5.5.2节练习
     */

    /**
     * @title
     * 练习5.21
     * @description
     * 修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。
     */
    static void exercise_5_21();

    /**
     * @title
     * 5.5.3节练习
     */

    /**
     * @title
     * 练习5.22
     * @description
     * 本节的最后一个例子跳回到begin，其实使用循环能更好地完成该任务。重写这段代码，注意不要使用goto语句。
     */
    static void exercise_5_22();
};
#endif  // CPP_PRIMER_STUDYING_5_5_HPP
