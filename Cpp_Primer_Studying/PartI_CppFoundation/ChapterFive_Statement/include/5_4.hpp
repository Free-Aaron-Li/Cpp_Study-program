// This file is part of Cpp_Primer_Studying project.
// This program is called:5_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_5_4_HPP
#define CPP_PRIMER_STUDYING_5_4_HPP

/**
 * @title
 * 5.4 迭代语句
 */

#include "5.hpp"

class Exercise_5_4 {
 public:
    /**
     * @title
     * 5.4.1节练习
     */

    /**
     * @title
     * 练习5.14
     * @description
     * 编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。
     * 要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如，如果输入是<br>
     * how how now now brown cow cow<br>
     * 那么输出应该表明单词now连续出现了3次。
     */
    static void exercise_5_14();

    /**
     * @title
     * 5.4.2节练习
     */

    /**
     * @title
     * 练习5.15
     * @description
     * 说明下列循环的含义并改正其中的错误。
     * @code
     * (a) for (int ix=0;ix!=sz;++ix){...}
     *     if(ix!=sz)
     *     ...
     * (b) int ix;
     *     for(ix!=sz;++ix){...}
     * (c) for(int ix=0;ix!=sz;++ix,++sz){...}
     */
    /* a：在for语句中已经存在条件ix!=sz，那么后面的if语句永远为真
     * b：ix仅定义，并未初始化，严格意义来讲，这条语句是可以执行的，内置类型在函数内并未初始化，其可能生成不确定值。在这里使用gcc编译器默认ix=0，为了程序的安全性考虑，应该给ix初始化。
     * c：为初始化sz
     * */
    static void meaninglessFunction_1();
};
#endif  // CPP_PRIMER_STUDYING_5_4_HPP
