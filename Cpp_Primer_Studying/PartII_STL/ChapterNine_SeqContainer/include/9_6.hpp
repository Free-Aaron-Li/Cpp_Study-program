// This file is part of Cpp_Primer_Studying project.
// This program is called:9_6.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_9_6_HPP
#define CPP_PRIMER_STUDYING_9_6_HPP

/**
 * @title
 * 9.6 容器适配器
 */

#include <stack>
#include "9.hpp"

class Exercise_9_6 {
 public:
    /**
     * @title
     * 9.6.0 容器适配器
     */

    /**
     * @title
     * 练习9.52
     * @description
     * 使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，
     * 从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）
     * 表达式已经处理完毕，被其运算结果所替代。
     */
     /*
      * 此题全部内容应该是做出一个简易的计算器，本题仅做出“获取括号内内容”部分，
      * 所以在形式上并没有将其计算器框架搭建，而是仅对本题内容进行解答。
      * 如果希望获得框架内容，请看参考：
      * https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.52.cpp
      * */
    static void exercise_9_52();

};

#endif  // CPP_PRIMER_STUDYING_9_6_HPP
