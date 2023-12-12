// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_5_HPP
#define CPP_PRIMER_STUDYING_4_5_HPP

/**
 * 4.5 递增和递减运算符
 */

#include "4.hpp"

class Exercise_4_5 {
 public:
    /**
     * @title
     * 练习4.17
     * @description
     * 说明前置递增运算符和后置递增运算符的区别。
     */
    /* 前置递增值将运算对象加1后作为左值返回，后置递增指将运算对象的字面值副本作为右值返回，运算对象自己再加1 */
    static void meaninglessFunction_4_17();

    /**
     * @title
     * 练习4.18
     * @description
     * 如果第132页的那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？
     */
    /* 将输出pbeg对象的下一个vector元素内容，其输出结果可能为负数，也可能为不可预知值 */
    static void meaninglessFunction_4_18();


    /**
     * @title
     * 练习4.19
     * @description
     * 假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？
     * @code
     * (a) ptr!=0&&*ptr++           (b) ival++ && ival
     * (c) vec[ival++]<=vec[ival]
     */
    /* a：如果ptr不为空，则解引用ptr，ptr指针加1，该表达式返回true
     * b：ival加1并且该表达式返回true
     * c：将对vec容器中下标为ival的元素进行自身比较，下标加1。应该修改为：vec[++ival]<=vec[ival]
     * */
    static void meaninglessFunction_4_19();
};
#endif  // CPP_PRIMER_STUDYING_4_5_HPP
