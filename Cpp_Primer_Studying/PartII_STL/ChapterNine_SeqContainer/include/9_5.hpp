// This file is part of Cpp_Primer_Studying project.
// This program is called:9_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_9_5_HPP
#define CPP_PRIMER_STUDYING_9_5_HPP

/**
 * @title
 * 9.5 额外的string操作
 */

#include <fstream>
#include "9.hpp"

class Exercise_9_5 {
 public:
    /**
     * @title
     * 9.5.1 构造string的其他方法 练习
     */

    /**
     * @title
     * 练习9.41
     * @description
     * 编写程序，从一个vector<char>初始化一个string。
     */
    static void exercise_9_41();

    /**
     * @title
     * 练习9.42
     * @description
     * 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？
     */
    static void exercise_9_42();

    /**
     * @title
     * 9.5.2 改变string的其他方法 练习
     */

    /**
     * @title
     * 练习9.43
     * @description
     * 编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器及
     * insert和erase函数将s中所有oldVal替换为newVal.测试你的程序，用它替换通用的简写形式，
     * 如，将“tho”替换为“though”，将“thru”替换为“through”。
     */
    static void exercise_9_43();

    /**
     * @title
     * 练习9.44
     * @description
     * 重写上一题的函数，这次使用一个下标和replace。
     */
    static void exercise_9_44();

    /**
     * @title
     * 练习9.45
     * @description
     * 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如“Mr.”或“Ms.”）
     * 和后缀（如“Jr.”或“III”）的字符串。使用迭代器及insert和append函数将前缀和后最添加到给定名字中，
     * 将生成的新string返回。
     */
    static void exercise_9_45();

    /**
     * @title
     * 练习9.46
     * @description
     * 重写上一题的函数，这次使用位置和长度来管理string,并只使用insert。
     */
    static void exercise_9_46();

    /**
     * @title
     * 9.5.3 string搜索操作
     */

    /**
     * @title
     * 练习9.47
     * @description
     * 编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。
     * 编写两个版本的程序,第一个要使用find_first_of，第二个要使用find_first_not_of。
     */
    static void exercise_9_47();

    /**
     * @title
     * 练习9.48
     * @description
     * 假定name和numbers的定义如325页所示，numbers.find(name)返回什么？
     */
    static void exercise_9_48();

    /**
     * @title
     * 练习9.49
     * @description
     * 如果一个字母延伸到中线之上，如d或f,则称其有上出头部分（ascender）。
     * 如果一个字母延伸到中线之下，如p或g,则称其有下出头部分（descender）。
     * 编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。
     */
    static void exercise_9_49();

    /**
     * @title
     * 9.5.5 数值转换
     */

    /**
     * @title
     * 练习9.50
     * @description
     * 编写程序处理一个vector<string>，其元素都表示整型值。计算vector中所有元素之和。
     * 修改程序,使之计算表示浮点值的string之和。
     */
    static void exercise_9_50();

    /**
     * @title
     * 练习5.51
     * @description
     * 设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。
     * 你的构造函数应该能够处理不同数据格式，如january 1,1900、1/1/1990、Jan 1 1900等。
     */
     static void exercise_9_51();
};
#endif  // CPP_PRIMER_STUDYING_9_5_HPP