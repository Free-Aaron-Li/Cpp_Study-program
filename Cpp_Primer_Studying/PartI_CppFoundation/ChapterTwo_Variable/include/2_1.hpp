//
// Created by AaronLi on 23-4-5.
//

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_2_1_HPP
#define CPP_PRIMER_2_1_HPP

/**
 * @title
 * <p> 2.1 基本内置类型 </P>
 */


#include <iostream>

typedef int ElemType;

class Exercise_2_1 {
public:

    /**
     * @title
     * <p> 2.1.1节练习——算术类型 </P>
     */

    /**
     * @title
     * <p> 练习2.1 </P>
     * @description
     *  类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？
     */

    //问题①：它们的区别在于它们所能表示的数值范围不同。     
    //问题②：无符号类型和带符号类型的区别在于无符号类型只能表示非负数，而带符号类型可以表示负数。
    //问题③：float和double都是C语言中的浮点数类型，它们的区别在于它们所能表示的精度不同。例如，float类型的范围为1.2E-38到3.4E+38，而double类型的范围为1.7E-308到1.7E+308 

    /**
     * @title
     * <p> 练习2.2 </P>
     * @description
     *  计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？
     */

    //对于计算这类数据，应该选择浮点型数据类型，所以确定选项为float和double,同时由于双精度浮点数和单精度浮点数的计算代价差别不大，应选择double类型。

    /**
     * @title
     * <p> 2.1.2节练习——类型转换 </P>
     */

    /**
     * @title
     * <p> 练习2.3 </P>
     * @description
     *  读程序写结果
     *  @code 
     *  unsigned u = 10, u2 = 42;
     *  std::count &lt;&lt; u2 -u &lt;&lt; std::endl;
     *  std::count &lt;&lt; u - u2 &lt;&lt; std::endl;
     *  
     *  int i = 10, i2 = 42;
     *  std::count &lt;&lt; i2 - i &lt;&lt; std::endl;
     *  std::count &lt;&lt; i - i2 &lt;&lt; std::endl;
     *  std::count &lt;&lt; i - u &lt;&lt; std::endl;
     *  std::count &lt;&lt; u - i &lt;&lt; std::endl; 
     */

    static void TypeConversion();

    /**
     * @title
     * <p> 练习2.4 </P>
     * @description
     *  编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在
     */

    /* 关键点：当算术表达式中既有无符号又有int值，int将自动转为无符号数 */
    /**
     * @title
     * <p> 2.1.3节练习——字面值常量 </P>
     */

    /**
     * @title
     * <p> 练习2.5 </P>
     * @description
     *  指出下述字面值的数据类型并说明每一组内字面值的区别：
     * @code
     *  (a) 'a',L'a',"a",L"a"
     *  (b) 10,10u,10L,10uL,012,0xC
     *  (c) 3.14,3.14f,3.14L
     *  (d) 10,10u,10.,10e-2
     */

    /* 问题a：字符a，宽字符a，字符串a，宽字符串a */
    /* 问题b：带符号十进制10，无符号十进制10，long类型10，无符号long类型10，八进制10，十六进制10 */
    /* 问题c：double类型3.14，float类型3.14，long double类型3.14 */
    /* 问题d：int类型10，无符号int类型10，double类型10.0，double类型0.1 */

    /**
     * @title
     * <p> 练习2.6 </P>
     * @description
     *  下面两组定义是否有区别，如果有，请叙述之：
     * @code
     *  int month = 9, day = 7;
     *  int month = 09, day = 07;
     */

    /* 有区别，前者代表月份为9，天数为7（使用的是十进制表示）；后者代表月份为9（用十进制表示），天数为7（用八进制表示）*/

    /**
     * @title
     * <p> 练习2.7 </P>
     * @description
     *  下述字面值表示何种含义？它们各自的数据类型是什么？
     * @code
     *  (a) "Who goes with F\145rgus?\012"
     *  (b) 3.14e1L (c) 1024f (d)3.14L
     */

    /* 问题a：“Who goes with Fergus?\n”
     * 问题b：long double类型的31.4
     * 问题c：错误，float类型用于表示浮点数，1024为整型
     * 问题d：long double类型的3.14
     * */

    /**
     * @title
     * <p> 练习2.8 </P>
     * @description
     *  请利用转义序列编写一段程序，要求先输出2M，然后转到新一行。修改程序使其先输出2，然后输出M，最后转到新一行。
     */

    static void Escape();
};

#endif //CPP_PRIMER_2_1_HPP
