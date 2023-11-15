// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_11_3_HPP
#define CPP_PRIMER_STUDYING_11_3_HPP

/**
 * @title
 * 11.3 关联容器操作
 */

#include "11.hpp"

class Exercise_11_3 {
 public:
    /**
     * @title
     * 11.3.1 关联容器迭代器
     */

    /**
     * @title
     * 练习11.15
     * @description
     * 对一个int到vector<int>的map,其mapped_type、key_type和value_type分别有什么不同？
     */
    /*
     * mapped_type仅存在于map和multimap中，用于表示map（multimap）中每个关键字关联的类型，在此例中表示int
     * key_type用于表示关联容器中关键字类型，本例中表示为string
     * value_type表示容器中元素类型，在set（multiset）中value_type与key_type一致，在map（multimap）中表示为pair<...>，本例中为pair<int,string>
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习11.16
     * @description
     * 使用一个map迭代器编写一个表达式，将一个值赋予一个元素。
     */
    static void exercise_11_16();

    /**
     * @title
     * 练习11.17
     * @description
     * 假定c是一个string的multiset,v是一个string的vector,解释下面的调用。指出每个调用是否合法：
     * @code
     * copy(v.begin(),v.end(),inserter(c,c.end()));
     * copy(v.begin(),v.end(),back_inserter(c));
     * copy(c.begin(),c.end(),inserter(v,v.end()));
     * copy(c.begin(),c.end(),back_inserter(v));
     */
    /*
     * 1. 不合法，v的关键字为const
     * 2. 不合法，v的关键字为const
     * 3. 合法，将v的数据插入c的尾部
     * 4. 合法，将v的数据插入c的尾部
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习11.18
     * @description
     * 写出第382页循环中map_it的类型，不要使用auto或decltype。
     */
    /*
     * std::pair<const std::string,std::size_t>::iterator
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习11.19
     * @description
     * 定义一个变量，通过对11.2.2节中的名为bookstore的multiset调用begin()来初始化这个变量。写出变量的类型，不要使用auto或decltype。
     */
    /*
     * std::pair<Sales_data,bool(*)(const Sales_data&,const Sales_data&)>::iterator mset_iter=bookstore.begin();
     * */
    static void meaninglessFunction_4();
};

#endif  // CPP_PRIMER_STUDYING_11_3_HPP
