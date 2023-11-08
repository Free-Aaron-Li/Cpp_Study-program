// This file is part of Cpp_Primer_Studying project.
// This program is called:7_1.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_1_HPP
#define CPP_PRIMER_STUDYING_7_1_HPP

/**
 * @title
 * 7.1 定义抽象数据类型
 */

#include "7.hpp"
#include "sales_data_public.hpp"

class Exercise_7_1 {
 public:
    /**
     * @title
     * 练习7.1
     * @description
     * 使用2.6.1节练习定义的Sales_data类为1.6节的交易处理程序编写一个新版本。
     */
    static void exercise_7_1();

    /**
     * @title
     * 7.1.2节练习
     */

    /**
     * @title
     * 练习7.2
     * @description
     * 曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine和isbn成员。
     */
    /* Sales_data类存放于当前工作空间下的include/sales_data.hpp下 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.3
     * @description
     * 修改7.1.1节的交易处理程序，令其使用这些成员。
     */
    static void exercise_7_3();

    /**
     * @title
     * 练习7.4
     * @description
     * 编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
     */
    /* 将Person类存放于本项目include/person.hpp中 */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.5
     * @description
     * 在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。
     */
    /* 应该是const，由于使用Person类中数据时我们并不需要修改数据，仅仅是读取数据。所以应该设定为const */

    /**
     * @title
     * 7.1.3节练习
     */

    /**
     * @title
     * 练习7.6
     * @description
     * 对于函数add、read和print,定义你自己的版本。
     */
    /* 详情请看include/sales_data.hpp文件 */
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.7
     * @description
     * 使用这些新函数重写7.1.2节练习中的交易处理程序。
     */
    static void exercise_7_7();

    /**
     * @title
     * 练习7.8
     * @description
     * 为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？
     */
    /* read函数实现的功能是读取输入流数据并初始化SalesData对象，所以需要使用普通引用，
     * 而print函数仅仅对SalesData对象进行读取操作并不会修改数据，所以使用常量引用。
     * */
    static void meaninglessFunction_4();


    /**
     * @title
     * 练习7.9
     * @description
     * 对于7.1.2节练习中的代码，添加读取和打印Person对象的操作。
     */
    /* 详情查看include/person.hpp文件 */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习7.10
     * @description
     * 在下面这条if语句中，条件部分的作用是什么？
     * if(read(read(cin,data1),data2))
     */
    /* 读取输入流数据并将其流中数据初始化data1和data2对象，同时判断返回状态 */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习7.11
     * @description
     * 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。
     */
     static void exercise_7_11();

     /**
      * @title
      * 练习7.12
      * @description
      * 把只接受一个istream作为参数的构造函数定义移到类的内部。
      */
      /* 详情查看include/sales_data.hpp文件 */
     static void meaninglessFunction_7();

     /**
      * @title
      * 练习7.13
      * @description
      * 使用istream构造函数重写第229页的程序。
      */
      static void exercise_7_13();

      /**
       * @title
       * 练习7.14
       * @description
       * 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。
       */
      /* 详情查看include/sales_data.hpp文件 */

      /**
       * @title
       * 练习7.15
       * @description
       * 为你的Person类添加正确的构造函数。
       */
       /* 详情查看include/person.hpp文件 */
};

#endif  // CPP_PRIMER_STUDYING_7_1_HPP
