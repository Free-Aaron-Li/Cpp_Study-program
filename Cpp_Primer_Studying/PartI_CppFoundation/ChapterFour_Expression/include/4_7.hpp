// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_7_HPP
#define CPP_PRIMER_STUDYING_4_7_HPP

/**
 * @title
 * 条件运算符
 */

#include "4.hpp"

class Exercise_4_7 {
 public:
    /**
     * @title
     * 练习4.21
     * @description
     * 编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数翻倍。
     */
    static void exercise_4_21();

    /**
     * @title
     * 练习4.22
     * @description
     * 本节的示例程序将成绩划分成high pass、pass和fail三种，扩展该程序使其进一步将60分到75分之间的成绩设定为low
     * pass。要求程序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？
     */
    /* 第二个版本，如果仅使用条件运算符，由于其程序逻辑本身比较复杂，加之代码由一行完成。比较难以理解 */
    static void exercise_4_22();

    /**
     * @title
     * 练习4.23
     * @description
     * 因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表指出它的问题在哪里？应该如何修改？
     * @code
     * string s="word";
     * string p1=s+s[s.size()-1]=='s'?"":"s";
     */
    /* 首先我们可以发现，这条表达式一共有6种运算符，分别是赋值运算符、下标运算符、点运算符、条件运算符、加法运算符、相等运算符。
     * 对运算符优先级排序：
     * 点运算符，下标运算符>加法运算符>相等运算符>条件运算符>赋值运算符
     * 由此，我们先推理出编译器运算顺序：
     * 首先：执行s.size()方法获取返回值，接下来执行下标运算符得到下标3，再然后执行加法运算，得到string对象值“wordd”，string对象与char类型字面值s作比较，编译失败。
     * 所以可以修改为：p1 = s + ((s[s.size() - 1] == 's') ? "" : "s");
     * 执行顺序如下：首先获取到s[3]的元素值d，返回false，执行条件运算符，返回s。再然后将s对象与string字面值s相加，得到string字面值“words”并赋值给p1。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习4.24
     * @description
     * 本节的示例程序将成绩划分成high
     * pass、pass和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值过程将是怎样的？
     */
    /* 首先列出示例：finalgrade=(grade>90)?"high pass":(grade<60)?"fail":"pass";
     * 如果grade大于90，那么将会执行：finalgrade="high pass"?"fail":"pass";返回的是fail。
     * 可以这样理解：((grade>90)?"high pass"):(grade<60)?"fail":"pass")
     * 如果grade小于90，正确返回值。
     * */
    static void meaninglessFunction_2(); /* TODO 23-6-5 没有搞明白条件运算符满足左结合律的推理过程 */
};
#endif  // CPP_PRIMER_STUDYING_4_7_HPP
