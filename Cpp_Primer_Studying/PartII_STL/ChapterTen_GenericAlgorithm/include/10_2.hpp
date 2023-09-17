// This file is part of Cpp_Primer_Studying project.
// This program is called:10_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_10_2_HPP
#define CPP_PRIMER_STUDYING_10_2_HPP

/**
 * @title
 * 10.2 初识泛型算法
 */

#include "10.hpp"

class Exercise_10_2 {
 public:
    /**
     * @title
     * 10.2.1 只读算法
     */

    /**
     * @title
     * 练习10.3
     * @description
     * 用accumulate求一个vector<int>中元素之和。
     */
    static void exercise_10_3();

    /**
     * @title
     * 练习10.4
     * @description
     * 假定v是一个vector<double>，那么调用accumulate(v.cbegin(),v.cend(),0)有何错误（如果存在的话）？
     */
    /* 结果仍然为int类型，发生精度损失 */
    static void exercise_10_4();

    /**
     * @title
     * 练习10.5
     * @description
     * 在本节对名册（roster)调用equal的例子中，如果两个名册中保存的都是C风格字符串而不是string,会发生什么？
     */
    /*
     * 在equal算法的说明中提到：
     * This compares the elements of two ranges using == and returns true or false depending
     * on whether all of the corresponding elements of the ranges are equal.
     * 虽然没有提到是否是 operator == ，但是实际上equal算法重载了==运算符。所以无论是C风格字符串还是string,其比较的都是元素，而非地址值。
     * */
    static void exercise_10_5();

    /**
     * @title
     * 10.2.2 写容器元素的算法
     */

    /**
     * @title
     * 练习10.6
     * @description
     * 编写程序，使用fill_n将一个序列中的int值都设置为0。
     */
    static void exercise_10_6();

    /**
     * @title
     * 练习10.7
     * @description
     * 下面程序是否有错误？如果有，请改正。
     * @code
     * (a) vector<int> vec; list<int> lst; int i;
     *     while (cin >> i)
     *        lst.push_back(i);
     *     copy(lst.cbegin(), lst.cend(), vec.begin());
     * (b) vector<int> vec;
     *     vec.reserve(10);
     *     fill_n(vec.begin(), 10, 0);
     */
    /*
     * a. 错误，算法总是通过迭代器操作容器，因此不能直接向容器添加、删除元素，无法改变容器大小。
     * 对于copy算法，要求目标序列至少要包含与源序列一样多的元素。
     * 而此程序中，vec进行缺省初始化，它是空的，copy无法进行。如需改变容器大小，需要使用一类特殊的称为插入器的迭代器。
     * 我们可以将第三个参数改为back_inserter(vec)，通过它，copy算法即可将lst中元素的拷贝插入到vec的末尾。
     *
     * b. 错误，泛型算法对于容器的要求并不是有足够的空间，而是足够的元素。此时vec仍然为空，没有任何元素。
     * 而算法又不具备向容器添加元素的能力，因此fill_n仍然失败。
     * 这里，我们还是需要使用back_inserter来让fill_n有能力向vec添加元素。
     * 其实，只要有能力做到这一点，空间大小并不是问题，容器都能根据需要自动扩容。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习10.8
     * @description
     * 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？
     */
     /*
      * 标准库算法其实并不知道“容器”的存在，算法依靠的是传入的参数。
      * 标准库算法从来不直接操作容器，它们只操作迭代器，从而间接访问容器。
      * 能不能插入和删除元素，不在于算法，而在于传递给它们的迭代器是否具有这样的能力。
      * */

};

#endif  // CPP_PRIMER_STUDYING_10_2_HPP
