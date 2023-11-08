//
// Created by AaronLi on 23-4-8.
//

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_2_2_H
#define CPP_PRIMER_2_2_H

/**
 * @title
 * <p> 2.2 变量 </P>
 */

#include <iostream>
typedef int ElemType;

class Exercise_2_2{
public:
    
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
#endif //CPP_PRIMER_2_2_H
