// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

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

class Exercise_2_3 {
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

    /**
     * @title
     * <p> 2.3.2节练习——指针 </P>
     */

    /**
     * @title
     * <p> 练习2.18 </P>
     * @description
     *  编写代码分别更改指针的值以及指针所指对象的值。
     */

    static void Pointer();

    /**
     * @title
     * <p> 练习2.19 </P>
     * @description
     *  请说明指针和引用的主要区别
     */

    void test_2_19() {
        /* ①、指针本身即为对象，而引用无法作为对象
         * ②、指针可以先后指向多个对象，而引用只能指向一个对象
         * ③、指针可以在定义时不初始化，而引用必须初始化
         * */
    };

    /**
     * @title
     * <p> 练习2.20 </P>
     * @description
     *  请叙述下面这段代码的作用
     * @code
     *  int i = 42;
     *  int *p1 = &i;
     *  *p1 = *p1 * *p1;
     */

    void test_2_20() {
        /* 定义初始化p1指向对象i，解引用p1使得i的值平方,得到i=176 */
    };

    /**
     * @title
     * <p> 练习2.21 </P>
     * @description
     *  请解释下述定义。这些定义中有非法的吗？如果有，为什么？
     * @code
     *  int i = 0;
     *  (a) double* dp = &i;        (b) int *ip = i;        (c) int *p = &i;
     */

    void test_2_21() {
        /* a：非法，不能将int类型的指针赋值给double类型的指针
         * b：非法，无法将定义为int类型的指针赋值
         * c：合法，初始化p指针指向对象i
         * */
    }

    /**
     * @title
     * <p> 练习2.22 </P>
     * @description
     *  假设p是一个int型指针，请说明下述代码的含义。
     * @code
     *  if (p) //...
     *  if (*p) //...
     */
    void test_2_22() {
        /* ①、如果指针p非空，则条件通过
         * ②、如果指针p指向的对象非0，则条件通过
         * */
    }

    /**
     * @title
     * <p> 练习2.23 </P>
     * @description
     *  给定指针p，你能知道它是否指向一个合法的对象吗？如果能，叙述判断思路；如果不能，也请说明原因。
     */

    void test_2_23() {
        /* 不能，因为首先需要判断指针是否合法，才能判断对象是否合法。仅给定一个指针，无法判断。
         * */
    }

    /**
     * @title
     * <p> 练习2.24 </P>
     * @description
     *  在下面这段代码中为什么p合法而lp非法？
     * @code
     *  int i = 42;     void *p = &i;  long *lp = &i;  
     */

    void test_2_24() {
        /* void*是一种特殊的指针类型，可以存放任意对象的地址，所以p指针合法。但是lp指针类型为long，而对象i类型为int，无法将对象i地址赋值给lp指针。
         * */
    }
    
    /**
     * @title
     * <p> 2.3.3节练习——理解复合类型的声明 </P>
     */
     
    /**
     * @title
     * <p> 练习2.25 </P>
     * @description
     *  说明下列变量的类型和值。
     * @code
     *  (a) int* ip,i, &r = i;      (b) int i, *ip = 0;     (c) int* ip, ip2;
     */
    void test_2_25() {
        /* a：int类型指针ip，未初始化；int类型变量i；引用变量i的引用r
         * b：int类型变量i；int类型空指针ip
         * c：int类型指针ip，未初始化；int类型变量ip2
         * */
    }
};

#endif //CPP_PRIMER_2_3_HPP
