/**
 * @author AaronLi
 * @data 2023-05-16-上午12:42
 * @license GPL-3.0
 */

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_2_5_HPP
#define CPP_PRIMER_2_5_HPP

/**
 * @title
 * 2.5 处理类型
 */
class Exercise_2_5 {
public:
    /**
     * @title
     * 2.5.2节练习
     */

    /**
     * @title
     * 练习2.33
     * @description
     * 利用本节定义的变量，判断下列语句的运行结果。
     * @code
     *  (a) a=42; b=42; c=42;
     *  (b) d=42; e=42; g=42;
     */
    /* a. a为整型，所以a=42；b为整型，所以b=42；c为整型，所以c=42；
     * b. d为整型指针，错误；e为指向整型常量的指针，即含有底层const，为指针常量，错误；g为整型常量引用，无法被非常量赋值，当g含有顶层const才能被赋值,错误。
     * */

    /**
     * @title
     * 练习2.34
     * @description
     *  基于上一个练习的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的判断正确吗？如果不对，请反复研读本节的示例知道你明白错在何处为止。
     */
    /* haha😃,i'm a genius */

    /**
     * @title
     * 练习2.35
     * @description
     *  判断下列定义推断出的类型是什么，然后编写程序进行验证
     * @code
     *  (a) const int i=42;
     *  (b) auto j=i;const auto &k=i; auto *p=&i;
     *  (c) const auto j2=i,&k2=i;
     */
    /* a. i为整型常量，值为42；
     * b. j为整型变量，值为42，auto为int；k为常量引用，auto为int；p为指向整型常量的指针，拥有底层const，auto为const int；
     * c. j2为整型常量，值为42，auto为int；ke为整型引用；
     * */

    /**
     * @title
     *  2.5.3节练习
     */

    /**
     * @title
     * 练习2.36
     * @description
     * 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
     * @code
     *  int a=3,b=4;
     *  decltype(a) c=a;
     *  decltype((b)) d=a;
     *  ++c;
     *  ++d;
     */
    /* a:int
     * b:int
     * c:int
     * d:int&
     * */

    /**
     * @title
     * 练习2.37
     * @description
     *  赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果i是int，则表达式i=x的类型是int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。
     * @code
     *  int a=3,b=4;
     *  decltype(a) c=a;
     *  decltype(a=b) d=a;
     */
    /* a:int，3
     * b:int，4
     * c:int，3
     * d:int&，3
     * */

    /**
     * @title
     * 练习2.38
     * @description
     * 说明由decltype指定类型和由auto指定类型有何区别。请举出一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。
     */
    /* 问题①：
     * 1. 处理顶层const不同，auto会自动忽略顶层const，而decltype会返回变量的所有类型（包括顶层const和引用）
     * 2. decltype的结果类型与表达式形式密切相关
     * 问题②：
     * int i=10;auto b=i;decltype(i) e=i;
     * 问题③：
     * const int i=10;auto e=i;decltype(i) f=i;
     * */
};

#endif //CPP_PRIMER_2_5_HPP
