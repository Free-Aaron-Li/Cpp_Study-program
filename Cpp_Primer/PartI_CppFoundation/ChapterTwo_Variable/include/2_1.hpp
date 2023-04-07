//
// Created by AaronLi on 23-4-5.
//

#ifndef CPP_PRIMER_2_1_HPP
#define CPP_PRIMER_2_1_HPP

/**
 * @title
 * <p> 2.1 基本内置类型 </P>
 */

/**
 * @title
 * <p> 2.1节练习——基本内置类型 </P>
 * @description
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

    /* 有区别，前者代表月份为9月份，天数为7（使用的是十进制表示）；后者代表月份为9月份（用十进制表示），天数为7（用八进制表示）*/

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

    /**
     * @title
     * <p> 2.2 变量 </P>
     */

    /**
     * @title
     * <p> 2.2.1节练习——变量定义 </P>
     */

    /**
     * @title
     * <p> 练习2.9 </P>
     * @description
     *  解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。
     * @code
     *  (a) std::cin &gt;&gt; int input_value;        (b) int i = {3.14};
     *  (c) double salary = wage = 9999,99;     (d) int i = 3.14;
     */

    /* 问题①：非法，input_value未被定义即使用
     * 问题②：错误，存在丢失信息风险
     * 问题③：非法，并不能在一个运算式中对多个变量初始化，其中wage并未定义，而salary才被定义
     * 问题④：并不会报错，但是信息会被截断，仅保留整数部分
     * */

    /**
     * @title
     * <p> 练习2.10 </P>
     * @description
     *  下列变量的初值分别是什么？
     * @code
     *  std::string global_str;
     *  int global_int;
     *  int main(){
     *      int local_int;
     *      std::string local_str;
     *  }
     */

    /* global_int 是全局变量，所以初值为 0 。 local_int 是局部变量并且没有初始化，它的初值是未定义的。 
     * global_str 和 local_str 是 string 类的对象，该对象定义了默认的初始化方式，即初始化为空字符串。 
     * */
    
    /**
     * @title
     * <p> 2.2.2节练习——变量声明和定义的关系 </P>
     */

    /**
     * @title
     * <p> 练习2.11 </P>
     * @description
     *  指出下面的语句是声明还是定义：
     * @code
     *  (a) extern int ix = 1024;
     *  (b) int iy;
     *  (c) extern int iz;
     */
     
    /* a：定义
     * b：定义
     * c：声明
     * */     
    
    /**
     * @title
     * <p> 2.2.3节练习——标识符 </P>
     */

    /**
     * @title
     * <p> 练习2.12 </P>
     * @description
     *  请指出下面的名字中哪些是非法的？
     * @code
     *  (a)int double = 3.14;       (b)int _;
     *  (c)int catch-22;            (d)int 1_or_2=1;
     *  (e)double Double =3.14;
     */
     
    /* a：非法，double为C++关键字
     * b：合法，标识符运行下划线
     * c：非法，标识符只能由字母、数字和下划线构成
     * d：非法，标识符开头只能为字母、下划线
     * e：合法，标识符对字母大小写敏感
     * */     
    
    /**
     * @title
     * <p> 2.2.4节练习——名字的作用域 </P>
     */

    /**
     * @title
     * <p> 练习2.13 </P>
     * @description
     *  下面程序中j的值是多少？
     * @code
     *  int i = 42;
     *  int main(){
     *      int i = 100;
     *      int j = i;
     *  }
     */
     
    /* j为100，内层嵌套定义域重写外层作用域的定义 */     
    
    /**
     * @title
     * <p> 练习2.14 </P>
     * @description
     *  下面的程序合法吗？如果合法，它将输出什么？
     * @code
     *  int i =100,sum = 0;
     *  for (int i =0; i!= 10; ++i){
     *   sum+=i;
     *  }
     *  std::cout &lt;&lt; i &lt;&lt; " " &lt;&lt; sum &lt;&lt; std::endl;
     */

    /* 合法，输出 100 45 */
};

#endif //CPP_PRIMER_2_1_HPP
