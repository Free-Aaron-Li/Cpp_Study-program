//
// Created by AaronLi on 23-4-5.
//

#ifndef CPP_PRIMER_2_1_HPP
#define CPP_PRIMER_2_1_HPP

/**
 * @title
 * <p> 2.1节练习——基本内置类型 </P>
 * @description
 */

#include <iostream>
typedef int ElemType;

class Exercise_2_1{
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
};

#endif //CPP_PRIMER_2_1_HPP
