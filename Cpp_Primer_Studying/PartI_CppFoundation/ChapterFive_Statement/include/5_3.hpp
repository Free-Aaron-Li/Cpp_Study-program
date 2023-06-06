// This file is part of Cpp_Primer_Studying project.
// This program is called:5_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_3_HPP
#define CPP_PRIMER_STUDYING_5_3_HPP

/**
 * @title
 * 5.3 条件语句
 */

#include "5.hpp"

class Exercise_5_3 {
 public:
    /**
     * @title
     * 5.3.1节练习
     */

    /**
     * @title
     * 练习5.5
     * @description
     * 写一段自己的程序，使用if else语句实现把数字成绩转换成字母成绩的要求。
     */
    static void exercise_5_5();

    /**
     * @title
     * 练习5.6
     * @description
     * 改写上一题的程序，使用条件运算符代替if else语句。
     */
    static void exercise_5_6();

    /**
     * @title
     * 练习5.7
     * @description
     * 改正下列代码段中的错误。
     * @code
     * (a) if (ival1 != ival2)
     *        ival1=ival2
     *      else ival1=ival2=0;
     * (b) if (ival<minval)
     *        minval=ival;
     *        occurs=1;
     * (c) if (int ival = get_value())
     *        cout<<"ival="<<ival<<endl;
     *     if (!ival)
     *        cout<<"ival=0\n";
     * (d) if (ival=0)
     *        ival=get_value();
     */
    /* a：第二句表达式后添加分号。
     * b：应该为if语句添加花括号，构成复合语句。
     * c：应该将ival变量写在复合语句之外。
     * d：if语句中的条件表达式应该写为：“ival==0”
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习5.8
     * @description
     * 什么是“悬垂else”？C++语言是如何处理else字句的？
     */
    /* 悬垂else问题指：当存在多个if和else语句，如何为某个给定的else和哪个if语句进行匹配。
     * else与离它最近的且尚未匹配的if语句匹配。
     * */
    static void meaninglessFunction_2();
};
#endif  // CPP_PRIMER_STUDYING_5_3_HPP
