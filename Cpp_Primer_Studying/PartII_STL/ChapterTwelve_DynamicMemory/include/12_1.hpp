// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_12_1_HPP
#define CPP_PRIMER_STUDYING_12_1_HPP

/**
 * @title
 * 12.1 动态内存与智能指针
 */

#include "12.hpp"

class Exercise_12_1 {
 public:
    /**
     * @title
     * 12.1.1 shared_ptr类
     */

    /**
     * @title
     * 练习12.1
     * @description
     * 在此代码的结尾，b1和b2各包含多少个元素？
     * @code
     * StrBlob b1;
     * {
     *      StrBlob b2 = {"a", "an", "the"};
     *      b1=b2;
     *      b2.push_back("about");
     * }
     */
    /*
     * b1与b2一致，包含4个元素
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习12.2
     * @description
     * 编写你自己的StrBlob类，包含const版本的front和back。
     */
    static void exercise_12_2();

    /**
     * @title
     * 练习12.3
     * @description
     * StrBlob需要const版本的push_back和pop_back吗？如果需要，添加进去。否则，解释为什么不需要。
     */
    /*
     * push_back和pop_back的语义分别是向StrBlob对象共享的vector对象增删元素。
     * 因此，我们不应该为其重载const版本，因为常量StrBlob对象不应该被允许修改共享vector对象内容。
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习12.4
     * @description
     * 在我们的check函数中，没有检查i是否大于0。为什么可以忽略这个检查？
     */
    /*
     * i为无符号类型。即i为非负数，所以不需要检查小于0的情况。
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习12.5
     * @description
     * 我们未编写接受一个initializer_list explicit参数的构造函数。讨论这个设计策略的优点和缺点。
     */
    /*
     * 未编写接受一个初始化列表参数的显示构造函数，意味着可以进行列表向StrBlob的隐式转换，即可以在需要该类型的地方可以使用列表进行替代。
     * 而且，可以进行拷贝形式的初始化（如赋值）。这令程序编写更为简单方便。
     * 但是这种隐式转换并不是总是好的。例如，列表中可能并非都是合法的值。再比如，对于接受StrBlob的函数，传递给它一个列表，会去创建一个临时的StrBlob对象并用列表对其初始化，然后将其传递给函数，当函数完成后，此对象将被丢弃并且再也无法访问。对于这些情况，定义显示构造函数是解决方法。
     * */
    static void meaninglessFunction_4();

    /**
     * @title
     * 12.1.2 直接管理内存
     */

    /**
     * @title
     * 练习12.6
     * @description
     * 编写函数，返回一个动态分配的int的vector。将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。再将vector传递给另一个函数，读取读入的值。记得在恰当的时刻delete
     * vector。
     */
    static void exercise_12_6();

    /**
     * @title
     * 练习12.7
     * @description
     * 重做上一题，这次使用shared_ptr而不是内置指针。
     */
    static void exercise_12_7();

    /**
     * @title
     * 练习12.8
     * @description
     * 下面的函数是否有错误？如果有，解释错误原因。
     * @code
     * bool b() {
     *      int* p = new int;
     *      // ...
     *      return p;
     * }
     */
    /*
     * 从程序片段看，猜测其目的是通过new返回的指针值区分内存分配是否成功。但是普通new调用在分配失败时抛出bad_alloc异常，并不会返回nullptr。
     * 程序可能达不到预期效果，可以将new int改为new(nothrow) int避免上述问题。
     * 但是这仍然不是一个优雅的解决方案，应该通过捕获异常或者判断返回的指针来返回false或者true,而是不依赖类型转换。
     * */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习12.9
     * @description
     * 解释下面代码执行的结果：
     * @code
     * int *q = new int(42), *r = new int(100);
     * r = q;
     * auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
     * r2 = q2;
     */
    /*
     * 这段代码非常好地展示了智能指针在管理内存上的优点。
     * 对于普通指针部分，首先分配了两个int型对象，指针分别保存在p和r中。接下来，将指针q的值赋予了r，这带来了两个非常严重的内存管理问题：
     *      1．首先是一个直接的内存泄漏问题，r和q一样都指向42的内存地址，而r中原来保存的地址——100的内存再无指针管理，变成“孤儿内存”，从而造成内存泄漏。
     *      2．其次是一个“空悬指针”问题。由于r和q指向同一个动态对象，如果程序编写不当，很容易产生释放了其中一个指针，而继续使用另一个指针的问题。
     *      继续使用的指针指向的是一块已经释放的内存，是一个空悬指针，继续读写它指向的内存可能导致程序崩溃甚至系统崩溃的严重问题。
     * 而shared_ptr则可很好地解决这些问题。首先，分配了两个共享的对象，分别由共享指针p2和q2指向，因此它们的引用计数均为1。
     * 接下来，将q2赋予r2。赋值操作会将q2指向的对象地址赋予r2，并将r2原来指向的对象的引用计数减1，将q2指向的对象的引用计数加1。
     * 这样，前者的引用计数变为0，其占用的内存空间会被释放，不会造成内存泄漏。而后者的引用计数变为2，也不会因为r2和q2之一的销毁而释放它的内存空间，因此也不会造成空悬指针的问题。
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 12.1.3 shared_ptr和new结合使用
     */

    /**
     * @title
     * 练习12.10
     * @description
     * 下面的代码调用了第413页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？
     * @code
     * shared_ptr<int> p(new int(42));
     * process(shared_ptr<int>(p));
     */
    /*
     * 此调用是正确的，利用p创建一个临时的shared_ptr赋予process的参数ptr,p和ptr都指向相同的int对象，引用计数被正确地置为2。
     * process执行完毕后，ptr被销毁，引用计数建1,只有p指向动态内存
     * */
    static void meaninglessFunction_7();

    /**
     * @title
     * 练习12.11
     * @description
     * 如果我们像下面这样调用process,会发生什么？
     * @code
     * process(shared_ptr<int>(p.get());
     */
    /*
     * 这样调用是错误的。p.get获得普通指针，指向p所共享的int对象。
     * 这样利用此指针创建一个shared_ptr，与正常利用p创建一个shared_ptr区别在于不会形成正确的动态对象共享。
     * 编译器会认为p和ptr是使用两个地址创建的两个不相干的shared_ptr，而非共享同一个动态对象。二者均为1,当process执行完毕后，
     * ptr引用计数为0，所管理的内存被释放，同时p管理相同的内存，导致p成为一个空悬指针。
     * */
    static void meaninglessFunction_8();

    /**
     * @title
     * 练习12.12
     * @description
     * p和sp的定义如下，对于接下来的process的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
     * @code
     * auto p = new int();
     * auto sp = make_shared<int>();
     * (a) process(sp);
     * (b) process(new int());
     * (c) process(p);
     * (d) process(shared_ptr<int>(p));
     */
    /*
     * a. 合法，值传递给process一个shared_ptr
     * b. 不合法，普通指针无法隐式转换为智能指针
     * c. 不合法，普通指针无法隐式转换为智能指针
     * d. 不合法，将普通指针交由智能指针管理，其引用计数为1,当函数结束，引用计数为0并释放p所指向的内存，p成为空悬指针。
     * */
    static void exercise_12_12();

    /**
     * @title
     * 练习12.13
     * @description
     * 如果执行下面的代码，会发生什么？
     * @code
     * auto sp = make_shared<int>();
     * auto p = sp.get();
     * delete p;
     */
    /*
     * 将智能指针转换为普通指针，为p提供访问sp指向内存的权限。通过p删除sp指向的内存，导致sp成为空悬指针。
     * */
    static void meaninglessFunction_9();

    /**
     * @title
     * 12.1.4 智能指针和异常
     */

    /**
     * @title
     * 练习12.14
     * @description
     * 编写你自己版本的用shared_ptr管理connection的函数。
     */
    static void exercise_12_14();

    /**
     * @title
     * 练习12.15
     * @description
     * 重写第一题的程序，用lambda代替end_connection函数。
     */
    static void exercise_12_15();

    /**
     * @title
     * 12.1.5 unique_ptr
     */

    /**
     * @title
     * 练习12.16
     * @description
     * 如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。
     */
    /*
     * 错误原因：程序调用了delete函数。
     * 原因是，标准库为了禁止unique_ptr的拷贝和赋值，将其拷贝构造函数和赋值函数声明为delete
     * */
    static void exercise_12_16();

    /**
     * @title
     * 练习12.17
     * @description
     * 下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
     * @code
     * int ix = 1024, *pi = &ix, *pi2 = new int(2014);
     * typedef unique_ptr<int> IntP;
     * (a) IntP p0(ix);             (b) IntP p1(pi);
     * (c) IntP p2(pi2);            (d) IntP p3(&ix);
     * (e) IntP p4(new int(2048));  (f) IntP p5(p2.get());
     */
    /*
     * a. 不合法，无法将int转换为指针
     * b. 合法，从程序结构上合法，但是逻辑上非法。pi指向的非动态内存，智能指针无法释放非动态内存
     * c. 合法
     * d. 与b项一致
     * e. 合法
     * f. 合法，从程序结构上合法，但逻辑上非法。会造成空悬指针
     * */
    static void meaninglessFunction_10();

    /**
     * @title
     * 练习12.18
     * @description
     * shared_ptr为什么没有release成员？
     */
    /*
     * 因为我们可以让尽可能多的shared_ptr指向同一个内存。因此，内存的所有权不需要由一个指针释放并传递给另一个指针。
     * */
    static void meaninglessFunction_11();
};

#endif  // CPP_PRIMER_STUDYING_12_1_HPP
