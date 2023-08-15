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
};
#endif  // CPP_PRIMER_STUDYING_9_3_HPP
