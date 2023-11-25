// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.
#ifndef CPP_PRIMER_1_4_HPP
#define CPP_PRIMER_1_4_HPP

/**
 * @title
 * <p> 1.4练习——控制流 </P>
 */

#include <iostream>

typedef int ElemType;

class Exercise_1_4 {
 public:
    /**
     * @title
     * <p> 1.4.1练习——while语句 </P>
     */

    /**
     * @title
     * <p> 练习1.9 </P>
     * @description
     *  编写程序，使用while循环将50到100的整数相加。
     */
    static void SumFiftyToHundred();

    /**
     * @title
     * <p> 练习1.10 </P>
     * @description
     *  除了++运算符（前缀递增运算符）将运算对象的值增加1以外，还有一个递减运算符（--）
     *  实线将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
     */
    static void Decline();

    /**
     * @title
     * <p> 练习1.11 </P>
     * @description
     *  编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
     */
    static void Integer();

    /**
     * @title
     * <p> 1.4.2练习——for语句 </P>
     */

    /**
     * @title
     * <p> 练习1.12 </P>
     * @description
     *  下面的for循环完成了什么功能？sum的终值是多少？
     *  @code
     *  int sum = 0;
     *  for( int i=-100;i <= 100; ++i)
     *      sum +=i;
     */
    static void Sum();

    /**
     * @title
     * <p> 练习1.14 </P>
     * @description
     *  对比for循环和while循环，两种形式的优缺点各是什么？
     */
    static void ForAndWhile();

    /**
     * @title
     * <p> 1.4.3练习——读取数量不定的输入数据 </P>
     */

    /**
     * @title
     * <p> 练习1.16 </P>
     * @description
     *  编写程序，从cin读取一组数，输出其和。
     */
    static void OutputSum();
    /**
     * @title
     * <p> 1.4.4例题 </P>
     */

    /**
     * @title
     * <p> 例题1——统计输入值次数 </P>
     */
    static void StatisticalFrequency();
    /**
     * @title
     * <p> 1.4.4练习——if语句 </P>
     */
    /**
     * @title
     * <p> 练习1.17 </P>
     * @description
     *  如果输入的所有值都是相等的，本节的程序（即例题1）的程序会输出什么？如果没有重复值，输出又会怎么样？
     */

    // 问题①：输入多少个值，便会输出多少个值数目
    // 问题②：输入多少个值，便会输出多少个输入值

    /**
     * @title
     * <p> 练习1.18 </P>
     * @description
     *  编译并运行本节的程序（即例题1），给它输入全都相等的值。再次运行程序，输入没有重复的值。
     */
    // 结论如上

    /**
     * @title
     * <p> 练习1.19 </P>
     * @description
     *  修改你为1.4.1节练习1.11所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。
     */
    static void IntegerPlus();
};

#endif  // CPP_PRIMER_1_4_HPP
