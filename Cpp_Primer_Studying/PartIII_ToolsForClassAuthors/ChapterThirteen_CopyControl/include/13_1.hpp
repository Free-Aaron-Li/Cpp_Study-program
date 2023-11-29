// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_13_1_HPP
#define CPP_PRIMER_STUDYING_13_1_HPP

/**
 * @title
 * 13.1 拷贝、赋值与销毁
 */

#include "13.hpp"

class Exercise_13_1 {
 public:
    /**
     * @title
     * 13.1.1 拷贝构造函数
     */

    /**
     * @title
     * 练习13.1
     * @description
     * 拷贝构造函数是什么？什么时候使用它？
     */
    /*
     * 如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，那么此构造函数是拷贝构造函数。
     * 当拷贝初始化时使用拷贝构造函数完成，但并不总是使用。
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习13.2
     * @description
     * 解释为什么下面的声明是非法的：
     * @code
     * Sales_data::Sales_data(Sales_data rhs);
     */
    /*
     * 拷贝构造函数第一个参数必须为引用类型。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习13.3
     * @description
     * 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？
     */
    /*
     * 拷贝StrBlob时，仅需拷贝其唯一元素data，调用shared_ptr的拷贝构造函数进行拷贝，引用计数加1。
     * 拷贝StrBlob时，对wptr成员，调用weak_ptr的拷贝构造函数进行拷贝，引用计数不变；拷贝curr，则直接进行内存复制。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习13.4
     * @description
     * 假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
     * @code
     * Point global;
     * Point foo_bar(Point arg)
     * {
     *      Point local = arg, *heap = new Point(global);
     *      *heap = local;
     *      Point pa[4] = {local,*heap};
     *      return *heap;
     * }
     */
    /*
     * 1. local采用拷贝初始化时用到；
     * 2. 使用花括号初始化数组时用到；
     * 3. foo_bar函数返回类型为非引用类型，返回*heap时用到；
     * 4. local拷贝到*heap地址时用到；
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习13.5
     * @description
     * 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是ps本身的位置。
     * @code
     * class HasPtr{
     * public:
     *      HasPtr(const std::string &s = std::string()) : ps(new std::string(s)),i(0){}
     * private:
     *      std::string *ps;
     *      int i;
     * }
     */
    static void exercise_13_5();

    /**
     * @title
     * 13.1.2 拷贝赋值运算符
     */

    /**
     * @title
     * 练习13.6
     * @description
     * 拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？
     */
    /*
     * 拷贝赋值运算符本身是一个重载的赋值运算符，定义为类的成员函数，
     * 左侧运算符对象绑定到隐式的this参数，右侧运算符对象为所属类类型，作为该成员函数的参数，函数返回指向其左侧运算对象的引用。
     *
     * 当对类对象进行赋值时，会使用拷贝赋值运算符
     *
     * 通常情况下，合成拷贝赋值运算符会将左侧对象的非static成员逐个赋予左侧对象的对应成员，
     * 这些赋值操作由成员类型的拷贝赋值运算符来完成。
     *
     * 若一个类并没有定义自己的拷贝赋值运算符，编译器会自动合成拷贝赋值运算符。同时，对于某些类，
     * 会禁止该类型的对象赋值（编译器将合成赋值运算符设为delete）
     * */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习13.7
     * @description
     * 当我们将一个StrBlob赋值给另一个StrBlob时，会发生什么？赋值StrBlobPtr呢？
     */
    /*
     * 与练习13.3类似，不再赘述。
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习13.8
     * @description
     * 为13.1.1节练习13.5中的HasPtr类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。
     */
    static void exercise_13_8();

    /**
     * @title
     * 13.1.3 析构函数
     */

    /**
     * @title
     * 练习13.9
     * @description
     * 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？
     */
    /*
     * 析构函数完成与构造函数相反的工作：释放对象使用的资源，销毁非static类型数据成员。
     * 从语法上看，其是类的一个成员函数，名字由波浪号接类名，没有返回值也不接受参数。
     *
     * 当一个类没有定义析构函数时，编译器会为它合成析构函数
     *
     * 合成的析构函数体为空，但这并不意味着它什么也不做，当空函数体执行完后，非静态数据成员会逐个销毁。
     * 也就是说，成员是在析构函数体之后隐含的析构阶段中进行销毁。
     * */
    static void meaninglessFunction_7();

    /**
     * @title
     * 练习13.10
     * @description
     * 当一个StrBlob对象销毁时会发生什么？一个StrBlobPtr对象销毁时呢？
     */
    /*
     * 编译器将生成合成析构函数。
     *
     * 对于StrBlob，在合成析构函数空函数体执行完后，会进行隐式析构阶段：
     *  - 销毁非static数据成员data
     *  - 调用shared_ptr的析构函数，将其引用计数减1,引用计数变为0,销毁指向的vector对象
     *
     * 对于StrBlobPtr，在合成析构函数空函数体执行完后，会进行隐式析构阶段：
     *  - 调用weak_ptr的析构函数，销毁wptr，引用计数不变
     *  - 销毁内置类型curr
     * */
    static void meaninglessFunction_8();

    /**
     * @title
     * 练习13.11
     * @description
     * 为前面练习中的HasPtr类添加一个析构函数。
     */
    static void exercise_13_11();

    /** @title
     * 练习13.12
     * @description
     * 在下面的代码片段中会发生几次析构函数的调用？
     * @code
     * bool fcn(const Sales_data *trans,Sales_data accum){
     *      Sales_data item1(*trans),item2(accum);
     *      return item1.isbn() != item2.isbn();
     * }
     */
    /*
     * 函数结束，item1与item2生命周期结束被销毁。
     *
     * 函数结束，accum作为临时对象的生命周期结束，被销毁。
     *
     * 共三次。
     * */
    static void meaninglessFunction_9();

    /**
     * @title
     * 练习13.13
     * @description
     * 理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，为该类定义这些成员，每个成员都打印自己的名字：
     * @code
     * struct X{
     *      X() { std::cout << "X()" << std::endl;}
     *      X(const X&) { std::cout << "X(const X&)" << std::endl;}
     * };
     * 给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象：将它们作为非引用和引用参数传递；动态分配它们；
     * 将它们存在在容器中；诸如此类。观察程序的输出，知道你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。
     * 当你观察程序输出时，记住编译器可以略过拷贝构造函数的调用。
     */
    static void exercise_13_13();
};

#endif  // CPP_PRIMER_STUDYING_13_1_HPP
