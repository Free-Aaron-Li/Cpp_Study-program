// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:9_4.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_9_4_HPP
#define CPP_PRIMER_STUDYING_9_4_HPP

/**
 * @title
 * 9.4 vector对象是如何增长的
 */

#include "9.hpp"

class Exercise_9_4 {
 public:
    /**
     * @title
     * 9.4.0 练习
     */

    /**
     * @title
     * 练习9.35
     * @description
     * 解释一个vector的capacity和size的区别。
     */
    /*
     * Vector是C++标准库中的一个动态数组，它能够自动地增长和收缩。Capacity和Size是Vector的两个重要属性，下面是它们的详细解释：
     * Capacity（容量）：
     * Capacity表示Vector当前分配的存储容量，也就是当前情况下Vector能够存储的元素个数。
     * 当创建一个Vector时，它会根据初始大小分配相应的存储空间，这个空间大小就是Vector的容量。
     * 当Vector的元素数量超过容量时，Vector会自动分配更大的存储空间并复制原有元素，这个过程称为扩容。扩容后的容量是原容量的两倍。
     *
     * Size（大小）：
     * Size表示Vector当前拥有的元素个数，也就是已经存储在Vector中的元素个数。
     * 它可以通过成员函数size()来获取。
     *
     * 总结来说，Capacity表示Vector的存储能力，Size表示Vector当前实际包含的元素个数。
     * 在初始化Vector时，Capacity是固定的，但在使用过程中，Vector可能会因为元素的增加而自动扩容，使得其Capacity增加。
     */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习9.36
     * @description
     * 一个容器的capacity可能小于它的size吗？
     */
    /* 不可能， */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习9.37
     * @description
     * 为什么list或array没有capacity成员函数？
     */
    /*
     * list本身是链表，所以其元素空间并不是紧密相连的，当新元素加入，会自动在内存空间分配一个新节点（并不一定与前一个节点在内存空间上相连），
     * 当删除某个节点，则其内存空间立即被释放，也就是说size和capacity的大小是相同的。
     *
     * array本身是固定大小的数组，内存空间是一次性分配完成的，大小并不会发生变化。所以不需要capacity。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习9.38
     * @description
     * 编写程序，探究在你的标准库实现中，vector是如何增长的。
     */
    static void exercise_9_38();

    /**
     * @title
     * 练习9.39
     * @description
     * 解释下面程序片段做了什么：
     * @code
     * vector<string> svec;
     * svec.reserve(1024);
     * string word;
     * while(cin>>word)
     *     svec.push_back(word);
     * svec.resize(svec.size()+svec.size()/2);
     */
    /*
     * 首先创建一个足够大（1024）的容器，向容器中传入内容，
     * 根据传入的内容适当扩大容器的内存大小。
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习9.40
     * @description
     * 如果上一题中的程序读入了256个词，在resize之后容器的capacity可能是多少？
     * 如果读入了512个、1000个或1048个呢？
     */
    /*
     * 如果使用g++ 11.2编译器，得到的结果：
     * 256个：1024
     * 512个：1024
     * 1000个：1024
     * 1048个：1572
     * */
    static void meaninglessFunction_5();
};
#endif  // CPP_PRIMER_STUDYING_9_4_HPP
