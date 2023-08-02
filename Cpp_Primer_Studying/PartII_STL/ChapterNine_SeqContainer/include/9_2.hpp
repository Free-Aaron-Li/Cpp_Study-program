// This file is part of Cpp_Primer_Studying project.
// This program is called:9_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_9_2_HPP
#define CPP_PRIMER_STUDYING_9_2_HPP

/**
 * @title
 * 9.2 容器库概览
 */

#include "9.hpp"

class Exercise_9_2 {
 public:
    /**
     * @title
     * 9.2节练习
     */

    /**
     * @title
     * 练习9.2
     * @description
     * 定义一个list对象，其元素类型是int的deque。
     */
    static void exercise_9_2();

    /**
     * @title
     * 9.2.1节练习
     */

    /**
     * @title
     * 练习9.3
     * @description
     * 构成迭代器范围的迭代器有何限制？
     */
    /*
     * 1. 迭代器所指向的位置必须在同一容器内或者同一容器尾元素的下一个位置
     * 2. begin迭代器必须在end迭代器之前
     *
     * 迭代器在实现时会有以下限制：
     * 一维性：迭代器只能顺序访问元素，无法直接跳转到指定位置或反向遍历。
     * 消耗性：当迭代器访问过某个元素后，该元素无法再次被访问，因为迭代器只能顺序遍历可迭代对象中的元素，无法回溯。
     * 有限性：迭代器的遍历范围是有限制的，一旦超出可迭代对象的范围，将会引发异常。
     * 阻塞性：在某些情况下，迭代器可能会阻塞程序的的其他部分，直到所有元素都被处理完毕。
     * 单一性：每个可迭代对象只能有一个迭代器，因为在遍历过程中，迭代器会不断消耗可迭代对象中的元素，如果同时存在多个迭代器，会导致数据不一致。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习9.4
     * @description
     * 编写函数，接受一对指向vector<int>的迭代器和一个int值。
     * 在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
     */
    static void exercise_9_4();

    /**
     * @title
     * 练习9.5
     * @description
     * 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。
     */
    static void exercise_9_5();

    /**
     * @title
     * 练习9.6
     * @description
     * 下面程序有何错误？你应该如何修改它？
     * @code
     *1 | list<int> lst1;
     *2 |  list<int>::iterator    iter1=lst1.begin(),
     *3 |                         iter2=lst1.end();
     *4 |  while(iter1<iter2){...}
     */
    /*
     * 修改：第4行修改为while(iter1!=iter2){ ... }
     * 与vector和deque不同，list的迭代器不支持<运算，只支持递增、递减、==以及!=运算。
     * 原因在于这几种数据结构实现上的不同。
     * vector和deque将元素在内存中连续保存，而list则是将元素以链表方式存储，
     * 因此前者可以方便地实现迭代器的大小比较（类似指针的大小比较）来体现元素的前后关系。
     * 而在list中，两个指针的大小关系与它们指向的元素的前后关系并不一定是吻合的，实现<运算将会非常困难和低效。
     */


};
#endif  // CPP_PRIMER_STUDYING_9_2_HPP
