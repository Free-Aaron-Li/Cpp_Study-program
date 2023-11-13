// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:10_4.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_10_4_HPP
#define CPP_PRIMER_STUDYING_10_4_HPP

/**
 * @title
 * 再探迭代器
 */

// #include "Sales_item_10.h"
#include "10.hpp"

class Exercise_10_4 {
 public:
    /**
     * @title
     * 10.4.1 插入迭代器
     */

    /**
     * @title
     * 练习10.26
     * @description
     * 解释三种插入迭代器的不同之处
     */
    /*
     * 在书中前文，我们已经学习了一种插入迭代器back_inserter。插入迭代器又称为插入器，本质是一种迭代器适配器
     * 如前所述，标准库算法为了保证通用性，并不直接操作容器，而是通过迭代器访问容器元素。因此，算法不具备直接向
     * 容器插入元素的能力。而插入器正是帮助算法实现向容器插入元素的机制。
     *
     * 除了back_inserter,标准库还提供了另外两种插入器：front_inserter和inserter。三者的差异在于如何向容向
     * 容器插入元素：
     *      - back_inserter调用push_back
     *      - front_inserter调用push_front
     *      - inserter调用insert
     * 显然，三者决定了插入元素位置的不同。back_inserter总是插入到容器尾元素之后，front_inserter总是插入到
     * 容器首元素之前，而inserter则是插入到给定位置之前。
     *
     * 需要注意的是，这些特点带来的元素插入效果的差异。例如，使用front_inserter插入元素，元素最终在容器中的顺序
     * 与插入顺序相反。例如：插入1 2 3 4，实际效果为：4 3 2 1
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习10.27
     * @description
     * 除了unique之外，标准库还定义了unique_copy的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。
     */
    static void exercise_10_27();

    /**
     * @title
     * 练习10.28
     * @description
     * 一个vector中保存1到9，将其拷贝到三个其他容器中。分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。对每种inserter，估计输出序列是怎么样的，运行程序验证你的估计是否正确。
     */
    static void exercise_10_28();

    /**
     * @title
     * 10.4.2 iostream迭代器
     */

    /**
     * @title
     * 练习10.29
     * @description
     * 编写程序，使用迭代器读取一个文本文件，存入一个vector中的string里。
     */
    static void exercise_10_29();

    /**
     * @title
     * 练习10.30
     * @description
     * 使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序、并将结果写到标准输出。
     */
    static void exercise_10_30();

    /**
     * @title
     * 练习10.31
     * @description
     * 修改前一题的程序，使其只打印不重复的元素。你的程序应使用unique_copy
     */
    static void exercise_10_31();

    /**
     * @title
     * 练习10.32
     * @description
     * 重写1.6节中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。使用sort和10.3.1节中的compareIsbn函数来排序交易记录，然后使用find和accumulate求和。
     */
    /* TODO 23-11-8 Multiple definition */
    static void exercise_10_32();

    /**
     * @title
     * 练习10.33
     * @description
     * 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用istream_iterator读取输入文件。使用ostream_iterator将奇数写入第一个输出文件，每个值都跟着一个空格。将偶数写入第二个输出文件，每个值都独占一行。
     */
    static void exercise_10_33();

    /**
     * @title
     * 10.4.3 反向迭代器
     */

    /**
     * @title
     * 练习10.34
     * @description
     * 使用reverse_iterator逆序打印一个vector。
     */
    static void exercise_10_34();

    /**
     * @title
     * 练习10.35
     * @description
     * 使用普通迭代器逆序打印一个vector。
     */
    static void exercise_10_35();

    /**
     * @title
     * 练习10.36
     * @description
     * 使用find在一个int的list中查找最后一个值为0的元素。
     */
    static void exercise_10_36();

    /**
     * @title
     * 练习10.37
     * @description
     * 给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。
     */
    static void exercise_10_37();
};
#endif  // CPP_PRIMER_STUDYING_10_4_HPP
