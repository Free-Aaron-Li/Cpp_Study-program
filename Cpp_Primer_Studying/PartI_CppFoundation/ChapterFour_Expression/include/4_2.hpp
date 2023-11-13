// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_2_HPP
#define CPP_PRIMER_STUDYING_4_2_HPP

/**
 * @title
 * 4.2 算术运算符
 */

#include "4.hpp"

class Exercise_4_2 {
 public:
    /**
     * @title
     * 练习4.4
     * @description
     * 在下面的表达式中添加括号，说明其求值的过程及最终结果。编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断
     * @code
     * 12/3*4+5*15+24%4/2
     */
    /* (((12/3)*4)+(5*15)+(24%4)/2)
     * 首先是12/3*4得到16，之后是5*15得到75，最后24%4/2得到0。最终结果为91
     * */
    static void exercise_4_4();

    /**
     * @title
     * 练习4.5
     * @description
     * 写出下列表达式的求值结果。
     * @code
     * (a) -30*3+21/5       (b) -30+3*21/5
     * (c) 30/3*21%5        (d) -30/3*21%4
     */
    /* a：-86
     * b：-18
     * c：1
     * d：-1
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习4.6
     * @description
     * 写出一条表达式用于确定一个整数是奇数还是偶数。
     */
    static void exercise_4_6();

    /**
     * @title
     * 练习4.7
     * @description
     * 溢出是何含义？写出三条将导致溢出的表达式。
     */
    /* 溢出指超出类型所能容纳的最大数值，数据出现进位由正数变为负数、无符号数变为0等未知数值 */
    static void exercise_4_7();
};
#endif  // CPP_PRIMER_STUDYING_4_2_HPP
