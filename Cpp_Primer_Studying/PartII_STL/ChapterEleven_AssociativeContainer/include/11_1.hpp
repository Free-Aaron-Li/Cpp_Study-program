// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_11_1_HPP
#define CPP_PRIMER_STUDYING_11_1_HPP

/**
 * @title
 * 11.1 使用关联容器
 */

#include "11.hpp"

class Exercise_11_1 {
 public:
    /**
     * @title
     * 11.1.0 使用关联容器
     */

    /**
     * @title
     * 练习11.1
     * @description
     * 描述map和vector的不同
     */
    /*
     * 学习关联容器，理解与顺序容器的不同，最关键的是理解其基础的数据结构，随后它所表现出来的一些性质就很自然能够理解了。
     * 两类容器的根本差别在于，顺序容器中的元素是“顺序”存储的（链表容器中的元素虽然不是在内存中“连续”存储的，但仍然是按“顺序”存储的）。理解“顺序”的关键，是理解容器支持的操作形式以及效率。
     * 对于vector这样的顺序容器，元素在其中按顺序存储，每个元素有唯一对应的位置编号，所有操作都是按编号（位置）进行的。例如，获取元素（头、尾、用下标获取任意位置）、插入删除元素（头、尾、任意位置）、遍历元素（按元素位置顺序逐一访问）。底层的数据结构是数组、链表，简单但已能保证上述操作的高效。而对于依赖值的元素访问，例如查找（搜索）给定值（find），在这种数据结构上的实现是要通过遍历完成的，效率不佳。
     * 而map这种关联容器，就是为了高效实现“按值访问元素”这类操作而设计的。为了达到这一目的，容器中的元素是按关键字值存储的，关键字值与元素数据建立起对应关系，这就是“关联”的含义。底层数据结构是红黑树、哈希表等，可高效实现按关键字值查找、添加、删除元素等操作。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习11.2
     * @description
     * 分别给出最合适使用list、vector、deque、map以及set的例子。
     */
    /*
     * vector：如果元素很小（如int），大致数目可知，运行过程中不会剧烈变化，大部分情况仅在末尾增删元素，频繁访问任意位置元素
     * deque：频繁在头部和尾部增删元素
     * list：元素较大（如大的类对象），数量预先不只，程序运行中剧烈变化，对元素访问多是顺序访问
     * map：适合某些特征具有相关联的对象
     * set：适合某些特征简单集合
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习11.3
     * @description
     * 编写你自己的单词计数程序。
     */
    static void exercise_11_3(const std::vector<std::string>& words);

    /**
     * @title
     * 练习11.4
     * @description
     * 扩展你的程序，忽略大小写和标点。例如，“example.”、“example,”和“Example”应该递增相同的计数器。
     */
    static void exercise_11_4(const std::vector<std::string>& words);
};
#endif  // CPP_PRIMER_STUDYING_11_1_HPP
