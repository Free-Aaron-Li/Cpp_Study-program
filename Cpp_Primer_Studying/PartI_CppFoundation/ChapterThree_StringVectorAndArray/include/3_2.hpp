// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.
*@author AaronLi* @data 2023 - 05 - 17 - 下午11 : 26 * @license GPL
  - 3.0 * /

#ifndef CPP_PRIMER_3_2_HPP
#define CPP_PRIMER_3_2_HPP

#include <iostream>

      /**
       * @title
       * 3.2节 标准库类型string
       */
      class Exercise_3_2 {
 public:
    /**
     * @title
     * 3.2.2节练习
     */

    /**
     * @title
     * 练习3.2
     * @description
     *  编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。
     */
    static void readInWords();

    /**
     * @title
     * 练习3.3
     * @description
     *  请说明string类的输入运算符和getline函数分别是如何处理空白字符的。
     */
    /* 输入运算符：将忽略开头的空白（包括：空格符、换行符、制表符等）直到遇到第一个非空白字符，截止到遇见下一个空白为止（且该空白并不会读取）。
     * getline函数：该函数能够保存空白字符（除了换行符），该函数会从给定的输入流中读取内容，直到遇见换行符为止。同时注意：该函数会将换行符一起读取，但是并不会存入指定的string对象中！
     * */

    /**
     * @title
     * 练习3.4
     * @description
     *  编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
     */
    static void compareStrings();

    /**
     * @title
     * 练习3.5
     * @description
     *  编写一段程序从标准输入中读入多个字符串并将它们连接到一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。
     */

    static void connectionStrings();

    static void connectionStrings_1();

    /**
     * @title
     * 3.2.3节练习
     */

    /**
     * @title
     * 练习3.6
     * @description
     * 编写一段程序，使用范围for语句将字符串内所有字符用X代替。
     */
    static void characterInstead();

    /**
     * @title
     * 练习3.7
     * @description
     * 就上一题完成的程序而言，如果将循环控制变量的类型设为char将会发生什么？先估计一下结果，然后实际编程进行验证
     */
    /* 仅改变其控制变量c的副本，无法修改原本字符串内容 */
    static void characterInstead_1();

    /**
     * @title
     * 练习3.8
     * @description
     * 分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？
     */
    static void characterInstead_2();

    /**
     * @title
     * 练习3.9
     * @description
     * 下面的程序有何作用？它合法吗？如果不合法，为什么？
     * @code
     * string s;
     * count << s[0] << endl;
     */
    /* 合法，输出为“\0”。由于定义了s为string类型 */

    /**
     * @title
     * 练习3.10
     * @description
     * 编写一段程序，读入一个包含标点字符的字符串，将标点符号去除后输出字符串剩余的部分。
     */
    static void punctuationRemoval();

    /**
     * @title
     * 练习3.11
     * @description
     * 下面的范围for语句合法吗？如果合法，c的类型是什么？
     * @code
     * const string s="Keep out!"
     * for (auto &c : s) { ... }
     */
    /* 合法，c类型为“const char &” */
};

#endif  // CPP_PRIMER_3_2_HPP
