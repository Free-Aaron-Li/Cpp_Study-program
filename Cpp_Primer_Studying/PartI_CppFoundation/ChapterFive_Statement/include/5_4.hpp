// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

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

    /**
     * @title
     * 练习5.16
     * @description
     * while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一值。for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。
     * 根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果使用一致循环，你倾向于使用哪种呢？为什么？
     */
    /* 我跟倾向于使用while循环，因为在大多数情况下，我都认为while循环比起for循环更简洁。 */
    static void exercise_4_16();

    /**
     * @title
     * 练习5.17
     * @description
     * 假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，
     * 把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2和0、1、1、2、3、5、8，则程序的返回结果应该为真。
     */
    static void exercise_5_17();

    /**
     * @title
     * 5.4.4节练习
     */

    /**
     * @title
     * 练习5.18
     * @description
     * 说明下列循环的含义并改正其中的错误。
     * @code
     * (a) do
     *         int v1,v2;
     *         cout<<"Please enter two numbers to sum:";
     *         if(cin>>v1>>v2)
     *             cout<<"Sum is: "<<v1+v2<<endl;
     *     while(cin);
     * (b) do {
     *         ...
     *     }while(int ival=get_response());
     * (c) do {
     *         int ival=get_response();
     *     } while (ival);
     */
    /* a：输入两个数据并进行加法运算，将结果输出（如果输入正确，进行迭代执行语句）。应该在do和while之间添加作用域，否则v1v2无法在输入流中运用。
     * b：C++不允许在条件部分定义变量，因为如果变量的使用在定义之前，则显然是不合理的。应该将ival定义在do-while之前。
     * c：ival的作用域在do后面的块中，while中使用的ival在其作用域之外，无效。应该将ival定义在do-while之前。
     * */

    /**
     * @title
     * 练习5.19
     * @description
     * 编写一段程序，使用do while循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。
     */
    static void exercise_5_19();
};
#endif  // CPP_PRIMER_STUDYING_5_4_HPP
