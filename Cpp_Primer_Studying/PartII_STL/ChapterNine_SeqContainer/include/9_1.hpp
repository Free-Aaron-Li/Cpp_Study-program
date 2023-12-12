// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:9_1.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_9_1_HPP
#define CPP_PRIMER_STUDYING_9_1_HPP

/**
 * @title
 * 9.1 顺序容器概述
 */

#include "9.hpp"

class Exercise_9_1 {
 public:
    /**
     * @title
     * 9.1 节练习
     */

    /**
     * @title
     * 练习9.1
     * @description
     * 对于下面的程序任务，vector、deque和list哪种容器最为合适？解释你的选择的理由。
     * 如果没有哪一种容器优于其他容器，也请解释理由。<br/>
     * （a）、读取固定数量的单词，紧挨那个它们按字典序插入到容器中。我们将在下一章看到，关联容器更适合这种问题。<br/>
     * （b）、读取未知数量的单词，总是将新单词插入到末尾。删除操作在头部进行。<br/>
     * （c）、从一个文件读取未知数量的整数。将这些数排序，然后打印到标准输出。
     */
    /*
     * a. list，因为需要按照字典序插入到容器中，那么需要随机插入，三者中仅有list符合要求
     * b. deque，需要在头部进行删除操作，排除vector。由于要求是仅将新单词插入末尾，相对而言deque更符合要求
     * c. vector，由于读取的全为整数，那么可以在数据存入容器后，选择sort进行排序。相对于另外二者，优先选择vector
     * */
    static void meaninglessFunction_1();
};
#endif  // CPP_PRIMER_STUDYING_9_1_HPP
