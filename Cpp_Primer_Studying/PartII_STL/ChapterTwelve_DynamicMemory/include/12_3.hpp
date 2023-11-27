// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_12_3_HPP
#define CPP_PRIMER_STUDYING_12_3_HPP

/**
 * @title
 * 12.3 使用标准库：文本查询程序
 */
#include "Query.hpp"
#include "12.hpp"

class Exercise_12_3 {
 public:
    /**
     * @title
     * 12.3.1 文本查询程序设计
     */

    /**
     * @title
     * 练习12.27
     * @description
     * TextQuery和QueryResult类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两个类编写你自己的版本。
     */
    static void exercise_12_27();

    /**
     * @title
     * 练习12.28
     * @description
     * 编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并与用户交互来查询单词。使用vector、map和set容器来保存来自文件的数据并生成查询结果。
     */
    static void exercise_12_28();

    /**
     * @title
     * 练习12.29
     * @description
     * 我们曾经用do while循环来编写管理用户交互的循环。用do while重写本节程序，解释你倾向哪个版本，为什么。
     */
    /*
     * 二者都差不多，既不会更简介，也没有实质性改变。
     * 如果是我，我会选择while()而非do while()。
     * 仅因为习惯使然。
     * */
    static void exercise_12_29();

    /**
     * @title
     * 12.3.2 文本查询程序类的定义
     */

    /**
     * @title
     * 练习12.30
     * @description
     * 定义你自己版本的TextQuery和QueryResult类，并执行12.3.1节中的runQueries函数。
     */
    /*
     * 查看include/Query.hpp文件，和exercise_12_27中的代码
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习12.31
     * @description
     * 如果用vector代替set保存行号，会有什么差别？哪种方法更好？为什么？
     */
    /*
     * 在没有仔细分析前，我认为set更好，毕竟没有重复项。
     * 但是，经过《c-primer习题集》的讲解，vector更好。
     * 实际上，根据实际情况分析：vector比起set在感知上差主要有两点：1.
     * vector不会维护元素值的序，set会维护关键字的序；2.同一个单词在同一行可能出现多次，set可以保证关键字不重复。
     * 但是分析可得：
     * 1.
     * 我们逐行读取输入文本，所以每个单词出现的行号必然是按照升序加入到容器中，不必用关联容器保证行号的升序，从性能角度，set基于红黑树实现，插入操作时间复杂性为：O(logn)，而vector的push_back可以达到常量时间。
     * 2.
     * 一个单词在同一行中可能出现多次。set自然可以保证关键字不重复，对vector来说要稍微麻烦点，需要每次添加行号前与最后一个行号比较一下。
     * 总体下来，vector的性能更优。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习12.32
     * @description
     * 重写TextQuery和QueryResult类，用StrBlob代替vector<string>保存输入文件。
     */
    /* TODO 23-11-27 好麻烦，摆烂…… */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习12.32
     * @description
     * 在第15章中我们将扩展查询系统，在QueryResult类中将会需要一些额外的成员。添加名为begin和end的成员，返回一个迭代器，指向一个给定查询返回的行号的set中的位置。再添加一个名为get_file的成员，返回一个shared_ptr，指向QueryResult对象中的文件。
     */
    /* TODO 23-11-27 不想写了…… */
    static void meaninglessFunction_4();
};
#endif  // CPP_PRIMER_STUDYING_12_3_HPP
