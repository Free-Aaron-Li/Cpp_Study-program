// This file is part of Cpp_Primer_Studying project.
// This program is called:7_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_4_HPP
#define CPP_PRIMER_STUDYING_7_4_HPP

/**
 * @title
 * 7.4 类的作用域
 */

#include "7.hpp"

class Exercise_7_4{
 public:
    /**
     * @title
     * 练习7.33
     * @description
     * 如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
     * pos Screen::size() const
     * {
     *      return height*width;
     * }
     */
     /* 返回类型属于类的成员，需要添加类作用域。修改为：Screen::pos Screen::size() const{} */
    static void meaninglessFunction_1();

};
#endif  // CPP_PRIMER_STUDYING_7_4_HPP
