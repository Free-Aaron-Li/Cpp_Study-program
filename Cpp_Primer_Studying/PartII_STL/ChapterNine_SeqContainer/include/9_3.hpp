// This file is part of Cpp_Primer_Studying project.
// This program is called:9_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_9_3_HPP
#define CPP_PRIMER_STUDYING_9_3_HPP

/**
 * @title
 * 9.3 顺序容器
 */

#include "9.hpp"

class Exercise_9_3 {
 public:
    /**
     * @title
     * 9.3.1 向顺序容器添加元素 练习
     */

    /**
     * @title
     * 练习9.18
     * @description
     * 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。
     */
    static void exercise_9_18();

    /**
     * @title
     * 练习9.19
     * @description
     * 重写上题的程序，用list代替deque。列出程序要做出哪些改变。
     */
    /* 只需要将list替换deque即可 */
    static void exercise_9_19();

    /**
     * @title
     * 练习9.20
     * @description
     * 编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到deque中，
     * 而奇数值元素都拷贝到另一个deque中。
     */
    static void exercise_9_20();

    /**
     * @title
     * 练习9.21
     * @description
     * 如果我们将第308页中使用insert返回值将元素添加到list中的循环程序改写为紧挨那个元素插入到vector中，
     * 分析循环将如何工作。
     */
    static void exercise_9_21();

    /**
     * @title
     * 练习9.22
     * @description
     * 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
     * @code
     * vector<int>::iterator   iter=iv.begin()
     *                         mid=iv.begin()+iv.size()/2;
     * while(iter!=mid)
     *     if(*iter==some_val)
     *         iv.insert(iter,2*some_val);
     */
    /* 由于迭代器发生变化，程序将会一直运行直至内存溢出。具体修改参见下方程序 */
    static void exercise_9_22();

    /**
     * @title
     * 9.3.2 访问元素 练习
     */

    /**
     * @title
     * 练习9.23
     * @description
     * 在本节第一个程序中，若c.size()为1,则val、val2、val3和val4的值会是什么？
     */
    /*
     * 假设c第一个元素值为x,则
     * val为x，val2为x，val3为x，val4为x
     *
     * 但是其前提是容器不能是forward_list
     * */
    static void exercise_9_23();

    /**
     * @title
     * 练习9.24
     * @description
     * 编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。
     * 在一个空vector上测试你的程序。
     */
     static void exercise_9_24();

     /**
      * @title
      * 9.3.3 删除元素 练习
      */

     /**
      * @title
      * 练习9.25
      * @description
      * 对于第312页中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？
      * 如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？
      */
      /*
       * 当elem1和elem2相同时，并不会删除容器中元素
       * 当elem2为尾后迭代器，而elem1不是时，会删除从elem1至elem2中所有元素
       * */
     static void exercise_9_25();

     /**
      * @title
      * 练习9.26
      * @description
      * 使用下面代码定义的ia,将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，
      * 从vector中删除偶数元素。
      * @code
      * int ia[]={0,1,1,2,3,5,8,13,21,55,89};
      */
      static void exercise_9_26();

};
#endif  // CPP_PRIMER_STUDYING_9_3_HPP
