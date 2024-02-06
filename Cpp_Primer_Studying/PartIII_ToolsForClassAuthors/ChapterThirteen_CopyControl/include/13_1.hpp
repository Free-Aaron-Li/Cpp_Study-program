// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_1'.
// If there are no special instructions, this file is used as an exercise and
// test file.
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
   *      HasPtr(const std::string &s = std::string()) : ps(new
   * std::string(s)),i(0){} private: std::string *ps; int i;
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
   *  -
   * 调用shared_ptr的析构函数，将其引用计数减1,引用计数变为0,销毁指向的vector对象
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

  /**
   * @title
   * 13.1.4 三/五原则
   */

  /**
   * @title
   * 练习13.14
   * @description
   * 假定numbered是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为mysn的数据成员中。
   * 假定numbered使用合成的拷贝控制成员，并给定如下函数：
   * void f (numbered s) { cout << s.mysn <<endl;}
   * 则下面代码输出什么内容？
   * @code
   * numbered a,b = a,c = b;
   * f(a); f(b); f(c);
   */
  /*
   * 如果依赖合成版本，则简单赋值需要给新对象。让a、b、c三者mysn值一致。
   * */
  static void exercise_13_14();

  /**
   * @title
   * 练习13.15
   * @description
   * 假定numbered定义了一个拷贝构造函数，能生成新的序号。这会改变上一题中调用的输出结果吗？
   * 如果会改变，为什么？新的输出结果是什么？
   */
  static void exercise_13_15();

  /**
   * @title
   * 练习13.16
   * @description
   * 如果f中的参数是const
   * numbered&，将会怎样？这会改变输出结果吗？如果会改变，为什么？新的输出结果是什么？
   */
  /*
   * 由于f中参数类型由类类型转为引用类型，s指向的都是实参的引用，序号自然是实参的序号。
   * */
  static void exercise_13_16();

  /**
   * @title
   * 练习13.17
   * @description
   * 分别编写前三题中所描述的numbered 和 f，验证你是否正确预测了输出结果。
   */
  /*
   * 请查看上述代码⬆️。
   * */
  static void meaninglessFunction_10();

  /**
   * @title
   * 13.1.6 阻止拷贝
   */

  /**
   * @title
   * 练习13.18
   * @description
   * 定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，
   * 以及接受一个表示雇员姓名的string的构造函数。每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。
   */
  static void exercise_13_18();

  /**
   * @title
   * 练习13.19
   * @description
   * 你的Employee类需要定义它自己的拷贝控制成员吗？如果需要，为什么？
   * 如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。
   */
  static void exercise_13_19();

  /**
   * @title
   * 练习13.20
   * @description
   * 解释当我们拷贝、赋值或销毁TextQuery和QueryResult类对象时会发生什么？
   */
  /*
   * 当TextQuery销毁时，合成版本会销毁其file和wm成员。对file成员，会将shared_ptr的引用计数减1，
   * 若变为0，则销毁所管理的动态vector对象（会调用vector和string的析构函数）。对wm，调用map的析构函数（从而调用string、shared_ptr和set的析构函数），
   * 会正确释放资源。
   *
   * 当QueryResult销毁时，合成版本会销毁其sought、lines和file成员。
   * 类似TextQuery，string、shared_ptr、set、vector的析构函数可能被调用，因为这些类都有设计良好的拷贝控制成员，会正确释放资源。
   *
   * 当拷贝一个TextQuery时，合成版本会拷贝file和wm成员。对file，shared_ptr的引用计数会加1。对wm，
   * 会调用map的拷贝构造函数（继而调用string、shared_ptr和set的拷贝构造函数），因此会正确进行拷贝操作。
   * 赋值操作类似，只不过会将原来的资源释放掉，例如，原有的file的引用计数会减1。QueryResult的拷贝和赋值类似。
   * */
  static void meaninglessFunction_11();

  /**
   * @title
   * 练习13.21
   * @description
   * 你认为TextQuery和QueryResult类需要定义它们自己版本的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？
   * 实现你认为这两个类需要的拷贝控制操作。
   */
  /*
   * 两个类虽然都未定义拷贝控制成员，但它们用智能指针管理共享的动态对象（输入文件内容，查询结果的行号集合），
   * 用标准库容器保存大量容器。而这些标准库机制都有设计良好的拷贝控制成员，用合成的拷贝控制成员简单的拷贝、赋值、销毁它们，
   * 即可保证正确的资源管理。因此，这两个类并不需要定义自己的拷贝控制成员。
   *
   * 实际上，这两个类的类对象之间就存在资源共享，目前的设计已能很好地实现这种共享，同类对象之间的共享也自然能够解决。
   * */
  static void meaninglessFunction_12();
};

#endif // CPP_PRIMER_STUDYING_13_1_HPP
