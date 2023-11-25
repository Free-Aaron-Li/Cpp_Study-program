// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

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

    /**
     * @title
     * 5.3.2节练习
     */

    /**
     * @title
     * 练习5.9
     * @description
     * 编写一段程序，使用一系列if语句统计从cin读入的文本中有多少个元音字母。
     */
    static void exercise_5_9();

    /**
     * @title
     * 练习5.10
     * @description
     * 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。
     */
    static void exercise_5_10();

    /**
     * @title
     * 练习11
     * @description
     * 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
     */
    static void exercise_5_11();

    /**
     * @title
     * 练习5.12
     * @description
     * 修改统计元音字母的程序，使其能够统计以下含有两个字符的字符序列的数量:ff、fl和fi。
     */
    static void exercise_5_12();

    /**
     * @title
     * 练习5.13
     * @description
     * 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
     * @code
     *  (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
     *      char ch = next_text();
     *      switch (ch) {
     *          case 'a': aCnt++;
     *          case 'e': eCnt++;
     *          default: iouCnt++;
     *      }
     *  (b) unsigned index = some_value();
     *      switch (index) {
     *          case 1:
     *              int ix = get_value();
     *              ivec[ ix ] = index;
     *              break;
     *          default:
     *              ix = ivec.size()-1;
     *              ivec[ ix ] = index;
     *      }
     *  (c) unsigned evenCnt = 0, oddCnt = 0;
     *      int digit = get_num() % 10;
     *      switch (digit) {
     *          case 1, 3, 5, 7, 9:
     *              oddcnt++;
     *              break;
     *          case 2, 4, 6, 8, 10:
     *             evencnt++;
     *              break;
     *      }
     *  (d) unsigned ival=512, jval=1024, kval=4096;
     *      unsigned bufsize;
     *      unsigned swt = get_bufCnt();
     *      switch(swt) {
     *          case ival:
     *              bufsize = ival * sizeof(int);
     *              break;
     *          case jval:
     *              bufsize = jval * sizeof(int);
     *              break;
     *          case kval:
     *              bufsize = kval * sizeof(int);
     *              break;
     *          }
     */
    /* a：由于在每个case分支语句上加上break，选中的分支及其之后分支上的语句都会被执行。
     * b：由于ix定义在case
     * 1分支上，C++规定不允许跨过变量的初始化语句直接跳转到该变量作用域内的另一个位置。所以default语句无法编译通过。
     * c：无法使用逗号运算符将多个case标签写在一行，应该使用引号。
     * d：case标签必须是整型常量表达式，所以应该这样写：const unsigned ival=512,jval=1024,kval=4096;
     * */
    static void meaninglessFunction_3();
};
#endif  // CPP_PRIMER_STUDYING_5_3_HPP
