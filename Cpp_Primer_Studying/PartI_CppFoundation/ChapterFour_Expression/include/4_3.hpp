// This file is part of Cpp_Primer_Studying project.
// This program is called:4_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_3_HPP
#define CPP_PRIMER_STUDYING_4_3_HPP

/**
 * @title
 * 4.3 逻辑和关系运算符
 */

#include "4.hpp"

class Exercise_4_3 {
 public:
    /**
     * @title
     * 练习4.8
     * @description
     * 说明在逻辑与、逻辑或及相等性运算符中运算对象求值的顺序
     */
    /* 逻辑与：当逻辑与左侧运算表达式为真才会执行逻辑与右侧表达式，否则返回false。只有左右的表达式均为真才会返回true；
     * 逻辑或：当逻辑或左侧运算表达式为假才会执行逻辑或右侧表达式，否则返回true。 只要左右的表达式有一个为真便返回true；
     * 相等性运算符：如参与运算的运算对象为真，且执行语句为if(object)，返回true。如参与运算的运算对象为假，其执行语句为if(!object)，返回true。
     * */
    static void meaninglessFunction_1();


    /**
     * @title
     * 练习4.9
     * @description
     * 解释在下面的if语句中条件部分的判断过程。
     * @code
     * const char *cp="Hello World";
     * if(cp&&*cp)
     */
    /* const char *cp="Hello World";语句可以拆分为：const char temporary[]="Hello World";const char *cp=temporary;
     * 所以，cp代表指针，不可能为0，*cp用于解引用该字符串字面值常量字符数组的首元素，也不为0，所以if语句返回true。
     * */
    static void exercise_4_9();

    /**
     * @title
     * 练习4.10
     * @description
     * 为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。
     */
    static void exercise_4_10();

    /**
     * @title
     * 练习4.11
     * @description
     * 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。
     */
    /* a>b&&b>c&&c>d */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习4.12
     * @description
     * 假设i、j和k是三个整数，说明表达式i!=j<k的含义。
     */
    /* j首先和k进行比较，再和i进行不等于比较。例如：i=1,j=2,k=3，则该表达式为假 */
    static void exercise_4_12();
};

#endif  // CPP_PRIMER_STUDYING_4_3_HPP
