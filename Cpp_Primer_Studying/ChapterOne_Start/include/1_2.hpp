// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_1_2_HPP
#define CPP_PRIMER_1_2_HPP

/**
 * @description
 * <p> 1.2节练习题——输入输出 </P>
 */

typedef int ElemType; /** 元素类型，默认为int */
#include <iostream>

class Exercise_1_2 {
 public:
    /**
     * @description
     * <p> 隔离带 </P>
     */
    static void IsolationZone();

    /**
     * @description
     * <p> 练习1.3 </P>
     * @def
     *  编写程序，在标准输出上打印Hello,World!
     */
    static void Hello();

    /**
     * @description
     * <p> 练习1.4 </P>
     * @def
     *  我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。
     */
    static void Multiplication();

    /**
     * @description
     * <p> 练习1.5 </P>
     * @def
     *  我们将所有输出去操作放在一条很长语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。
     */
    static void Output();

    /**
     * @description
     * <p> 练习1.6 </P>
     * @def
     *  解释下面程序片段是否合法。
     * <pre>{@code
     *  std::cout &lt;&lt; "The sum of " &lt;&lt; v1;
     *            &lt;&lt; " and " &lt;&lt; v2;
     *            &lt;&lt; " is " &lt;&lt; v1 + v2 &lt;&lt; std::endl;
     * }</pre>
     */
    static void legal();
};

#endif  // CPP_PRIMER_1_2_HPP
