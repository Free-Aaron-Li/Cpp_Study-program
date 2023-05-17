/**
 * @author AaronLi
 * @data 2023-05-17-下午11:26
 * @license GPL-3.0
 */

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
};

#endif //CPP_PRIMER_3_2_HPP
