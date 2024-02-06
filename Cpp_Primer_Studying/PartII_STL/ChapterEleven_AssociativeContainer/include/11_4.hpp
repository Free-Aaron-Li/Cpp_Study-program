// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_4'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_11_4_HPP
#define CPP_PRIMER_STUDYING_11_4_HPP

/**
 * @title
 * 11.4 无序容器
 */

#include "11.hpp"

class Exercise_11_4 {
 public:
    /**
     * @title
     * 11.4.0 无序容器
     */

    /**
     * @title
     * 练习11.37
     * @description
     * 一个无序容器与其有序版本相比有何优势？有序版本有何优势？
     */
    /*
     * 无序版本通常性能更好，使用也更为简单。有序版本的优势是维护了关键字的序。
     * 当元素的关键字类型没有明显的序关系，或是维护元素的序代价非常高时，无序容器非常有用。
     * 但当应用要求必须维护元素的序时，有序版本就是唯一的选择。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习11.38
     * @description
     * 用unordered_map重写单词计数程序和单词转换程序
     */
    /*
     * 仅重写单词计数器程序，如果想要查看单词转换程序请移步：
     * url:<https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch11/11.38.2.cpp#L11>
     * */
    static void exercise_11_38(const std::vector<std::string>& data);
};
#endif  // CPP_PRIMER_STUDYING_11_4_HPP
