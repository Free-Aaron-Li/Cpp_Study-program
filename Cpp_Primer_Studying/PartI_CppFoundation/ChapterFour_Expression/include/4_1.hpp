// This file is part of Cpp_Primer_Studying project.
// This program is called:4_1.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#ifndef CPP_PRIMER_STUDYING_4_1_HPP
#define CPP_PRIMER_STUDYING_4_1_HPP

/**
 * @title
 *4.1 基础
 */

#include "4.hpp"

class Exercise_4_1 {
 public:
    /**
     * @title
     * 4.1.2节练习
     */

    /**
     * @title
     * 练习4.1
     * @description
     * 表达式5+10*20/2的求值结果是多少？
     */
    /* 105 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习4.2
     * @description
     * 根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。
     * @code
     * (a)  *vec.begin()        (b) *vec.begin()+1
     */
    /* a：(*vec.begin()
     * b：(*vec.begin()+1)
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 4.1.3节练习
     */

    /**
     * @title
     * 练习4.3
     * @description
     * C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡。你认为这可以接受吗？请说出你的理由。
     */
    /* 我认为这是不能接受的。拿我个人而言，如果我并没有看这本书，或许我一直都不会意识到这种潜在的安全缺陷，这显然是不划算的,
     * C++作为一门严谨的语言，理应当对此有详细的规则。
     * */
};
#endif  // CPP_PRIMER_STUDYING_4_1_HPP
