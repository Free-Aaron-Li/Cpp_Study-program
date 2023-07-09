// This file is part of Cpp_Primer_Studying project.
// This program is called:7_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_3_HPP
#define CPP_PRIMER_STUDYING_7_3_HPP

/**
 * @title
 * 7.3 类的其他特性
 */

#include "7.hpp"
#include "window_mgr.hpp"

class Exercise_7_3 {
 public:
    /**
     * @title
     * 7.3.1节练习
     */

    /**
     * @title
     * 练习7.23
     * @description
     * 编写你自己的Screen类。
     */
    /* 具体查看include/screen.hpp文件 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.24
     * @description
     * 给你的Screen类添加三个构造函数：一个默认构造函数；
     * 另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；
     * 第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。
     */
    /* 具体查看include/screen.hpp文件 */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.25
     * @description
     * Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？
     */
    /* Screen类中数据成员的类型仅有内置类型和string类型，所有能够进行拷贝和赋值操作。 */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.26
     * @description
     * 将Sales_data::avg_price定义成内联函数。
     */
    /* 查看include/sales_data_private.hpp文件 */
    static void meaninglessFunction_4();

    /**
     * @title
     * 7.3.2节练习
     */

    /**
     * @title
     * 练习7.27
     * @description
     * 给你自己的Screen类添加move、set和display函数，通过执行下面的代码检验你的类是否正确。
     * @code
     * Screen myScreen(5,5,'X');
     * myScreen.move(4,0).set('#').display(cout);
     * cout<<"\n";
     * myScreen.display(cout);
     * cout<<"\n";
     */
    /*
     * 结果为：
     * XXXXXXXXXXXXXXXXXXXX#XXXX
     * XXXXXXXXXXXXXXXXXXXX#XXXX
     */
    static void exercise_7_27();

    /**
     * @title
     * 练习7.28
     * @description
     * 如果move、set和display函数的返回类型不是Screen&而是Screen，则在上一个练习中将会发生什么情况？
     */
    /*
     * 结果为：
     * XXXXXXXXXXXXXXXXXXXX#XXXX
     * XXXXXXXXXXXXXXXXXXXXXXXXX
     */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习7.29
     * @description
     * 修改你的Screen类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？
     */
    /*
     * 正确，首先三个函数的返回类型均为Screen，那么表达式：myScreen.move(4, 0).set('#').display(std::cout);
     * 首先是将光标移动到4,0位置同时返回myScreen的副本，接下来对myScreen的副本进行set操作将4,0位置字符改变为#，同时又返回myScreen副本的副本；
     * 最后打印myScreen的副本的副本。
     * 所以，在第二个表达式中才会出现4,0位置依旧为X的情况。
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习7.30
     * @description
     * 通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。
     */
    /*
     * 优点：
     * 1.清晰性：显式地使用指针访问成员可以增加代码的清晰性。通过明确指出要访问的是哪个对象的成员，可以避免混淆和误解。
     * 2.防止使用未初始化的对象：如果直接使用对象访问成员，如果对象未初始化，可能会导致未定义的行为。
     * 而显式地使用指针访问成员可以避免这种情况，因为指针在未初始化之前默认为空指针，访问空指针会引发未定义行为。
     * 3.避免使用未构造的对象：在某些情况下，可能会在对象的构造函数执行完毕之前访问对象的成员。
     * 显式地使用指针可以避免这种情况，因为指针在构造函数执行完毕之前可以为空指针。
     * 4.更高的效率：由于this指针可能需要在对象的构造函数中初始化，显式地使用指针可以避免额外的开销。
     *
     * 缺点：
     * 1.增加复杂性：显式地使用指针会增加代码的复杂性，因为需要管理额外的指针变量。
     * 2.容易引入错误：如果忘记初始化指针或误用空指针，可能会导致程序崩溃或出现未定义行为。
     * 3.降低代码的可读性：显式地使用指针可能会降低代码的可读性，因为读者需要额外地理解每个指针所指向的对象。
     * */
    static void meaninglessFunction_7();

    /**
     * @title
     * 7.3.3节练习
     */

    /**
     * @title
     * 练习7.31
     * @description
     * 定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。
     */
    static void exercise_7_31();

    /**
     * @title
     * 7.3.4节练习
     */

    /**
     * @title
     * 练习7.32
     * @description
     * 定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。
     */
    /* 具体查看src/exercise/friend.cpp文件 */
};
#endif  // CPP_PRIMER_STUDYING_7_3_HPP
