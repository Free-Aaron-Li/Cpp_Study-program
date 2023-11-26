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
};
#endif  // CPP_PRIMER_STUDYING_12_3_HPP
