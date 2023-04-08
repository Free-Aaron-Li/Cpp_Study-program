//
// Created by AaronLi on 23-4-8.
//

#ifndef CPP_PRIMER_2_3_HPP
#define CPP_PRIMER_2_3_HPP

/**
 * @title
 * <p> 2.3 复合类型 </P>
 */

#include <iostream>
typedef int ElemType;

class Exercise_2_3{
public:
    
    /**
     * @title
     * <p> 2.3.1节练习——引用 </P>
     */
    
    /**
     * @title
     * <p> 练习2.15 </P>
     * @description
     *  下面的哪个定义是不合法的？为什么？
     * @code
     *  (a) int ival =1.0;      (b) int &rval1 = 1.01;
     *  (c) int &rval2 = ival;  (d) int &rval3;
     */
     
    /* a：合法
     * b：不合法，引用无法与字面值绑定
     * c：合法
     * d：不合法，引用必须初始化
     * */     
   
    /**
     * @title
     * <p> 练习2.16 </P>
     * @description
     *  考查下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操作？
     * @code
     *  int i = 0, &r1 = i;     double d = 0, &r2 = d;
     *  (a) r2 = 3.14159;       (b) r2 = r1;
     *  (c) i = r2;             (d) r1 = d;
     */
     
    /* a：合法，覆写d的初始值为3.14159
     * b：合法，将进行自动转换，i的值赋予d，并将值转换：int->double
     * c：合法，将d值赋予i，double->int，自动截断信息
     * d：合法，将d值赋予i，double->int，自动截断信息
     * */     
    
    /**
     * @title
     * <p> 练习2.17 </P>
     * @description
     *  执行下面的代码段将会输出什么结果？
     * @code
     *  int i, &ri = i;
     *  i = 5; ri = 10;
     *  std::cout &lt;&lt; i &lt;&lt; " " &lt;&lt; ri &lt;&lt; std::endl;
     */
     
    /* 将输出得到 10 10
     * */     
};

#endif //CPP_PRIMER_2_3_HPP
