// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

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

    /**
     * @title
     * 11.3.2 添加元素
     */

    /**
     * @title
     * 练习11.20
     * @description
     * 重写11.1节练习的单词计数程序，使用insert代替下标操作。您认为哪个程序更容易编写和阅读？解释原因。
     */
    static void exercise_11_20(const std::vector<std::string>& data);

    /**
     * @title
     * 练习11.21
     * @description
     * 假定word_count是一个string到size_t的map,word是一个string,解释下面循环的作用：
     * @code
     * while(cin>>word)
     *  ++word_count.insert({word,0}).first->second;
     */
    /*
     * 读取word，并记录对应word的数目
     * */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习11.22
     * @description
     * 给定一个map<string,vector<int>>，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型。
     */
    /*
     * 参数类型：std::pair<std::string,std::vector<int>>
     * 返回类型：std::pair<std::map<std::string,std::vector<int>>::iterator,bool>
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习11.23
     * @description
     * 11.2.1节中的map以孩子的姓为关键字，保存他们的名的vector,用multimap重写此map。
     */
    static void exercise_11_23(const std::vector<std::string>& data);

    /**
     * @title
     * 11.3.4 map的下标操作
     */

    /**
     * @title
     * 练习11.24
     * @description
     * 下面的程序完成什么功能？
     * @code
     * map<int,int> m;
     * m[0]=1;
     */
    /*
     * 为类型为map的m对象添加一个关键字-值对，其值为{0,1}
     * */
    static void meaninglessFunction_7();

    /**
     * @title
     * 练习11.25
     * @description
     * 对比下面程序与上一题程序
     * @code
     * vector<int> v;
     * v[0]=1;
     */
    /*
     * 为空的类型为vector类型的v对象添加一个值，在v的首位添加元素1
     * */
    static void meaninglessFunction_8();

    /**
     * @title
     * 练习11.26
     * @description
     * 可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个map,然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返回的类型。
     */
    static void exercise_11_26();

    /**
     * @title
     * 11.3.5 访问元素
     */

    /**
     * @title
     * 练习11.27
     * @description
     * 对于什么问题你会使用count来解决？什么时候你会选择find呢？
     */
    /*
     * 当需要考虑容器中给定关键字数目时，选择count
     * 当仅需要查找特定的（或者第一个匹配的）关键字时，选择find
     * */
    static void meaninglessFunction_9();

    /**
     * @title
     * 练习11.28
     * @description
     * 对于一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。
     */
    static void exercise_11_28();

    /**
     * @title
     * 练习11.29
     * @description
     * 如果给定的关键字不再容器中，upper_bound、lower_bound和equal_range分别会返回什么？
     */
    /*
     * 若给定关键字不在容器中，前两个操作显然应构成一个空范围，它们返回相当的迭代器，指出关键字的正确插入位置——不影响关键字的排序。
     * 如果给定关键字比容器中所有关键字都大，则此位置是容器的尾后位置end。
     * equal_range将会返回均指向关键字可插入位置的相同迭代器的pair。
     * */
    static void meaninglessFunction_10();

    /**
     * @title
     * 练习11.30
     * @description
     * 对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。
     */
    /*
     * pos为pair，其中两成员变量为迭代器，圈定符合给定关键字的范围，pos.first为一个迭代器，指向第一个符合给定关键字的关键字-值对。->second显露该关键字-值对的值
     * */
    static void meaninglessFunction_11();

    /**
     * @title
     * 练习11.31
     * @description
     * 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不再map中时也能正常运行。
     */
    static void exercise_11_31(const std::vector<std::string>& data);

    /**
     * @title
     * 练习11.32
     * @description
     * 使用上一题定义的multimap编写一个程序，按字典序打印作者列表和他们的作品。
     */
    /*
     * 查看exercise_11_31程序中print()函数
     * */
    static void meaninglessFunction_12();

    /**
     * @title
     * 11.3.6 一个单词转换的map
     */

    /**
     * @title
     * 练习11.33
     * @description
     * 实现你自己版本的单词转换程序。
     */
    static void exercise_11_33(std::ifstream& rule_dictionary, std::ifstream& input_file);

    /**
     * @title
     * 练习11.34
     * @description
     * 如果你将transform函数中的find替换为下标运算符，会发生什么情况？
     */
    /*
     * 由于下标运算的副作用：当关键字未找到，将自动构造一个pair（值初始化）
     * 所以，对于不是我们所找的关键字，采用下标运算也会将word添加如规则map中，这显然不是所期望的。
     * */
    static void meaninglessFunction_13();

    /**
     * @title
     * 练习11.35
     * @description
     * 在buildMap中，如果进行如下改写，会有什么效果？
     * @code
     * trans_map[key]=value.substr(1);
     * 改为：trans_map.insert({key,value.substr(1)});
     */
    /*
     * 在buildMap中我们合理利用了下标运算的副作用，当trans_map中关键字不存在会自动添加。
     * 如果采用insert方式，那么会导致trans_map中无任何关键字，不符合期望
     * */
    static void meaninglessFunction_14();

    /**
     * @title
     * 练习11.36
     * @description
     * 我们的程序并没有检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。
     */
    /*
     * 其实书中buildMap函数中已经检测了这种情况，“value.size()>1”。如果出现上述的问题，会抛出一个异常。
     * */
    static void meaninglessFunction_15();
};

#endif  // CPP_PRIMER_STUDYING_11_3_HPP
