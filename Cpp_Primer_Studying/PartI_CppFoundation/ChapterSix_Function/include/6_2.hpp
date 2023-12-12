// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_2.
// If there are no special instructions, this file is used as an exercise and test file.

#ifndef CPP_PRIMER_STUDYING_6_2_HPP
#define CPP_PRIMER_STUDYING_6_2_HPP

/**
 * @title
 * 6.2 参数传递
 */

#include "6.hpp"

class Exercise_6_2 {
 public:
    /**
     * @title
     * 练习6.10
     * @description
     * 编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
     */
    static void exercise_6_10();

    /**
     * @title
     * 6.2.2节练习
     */

    /**
     * @title
     * 练习6.11
     * @description
     * 编写并验证你自己的reset函数，使其作用于引用类型的参数。
     */
    static void exercise_6_11();

    /**
     * @title
     * 练习6.12
     * @description
     * 改写6.2.1节中练习6.10的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更容易使用呢？为什么？
     */
    /* 本人觉得使用引用更加方便，虽然二者实参都是引用传递，但是引用的方式相较于指针传递更加方便，特别在初学者看来引用简直就是福音。
     */
    static void exercise_6_12();

    /**
     * @title
     * 练习6.13
     * @description
     * 假设T是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T)，另一个是 void f(T&)。
     */
    /* 第一种函数声明其形参为T类型，其函数被传值调用，第二种函数声明其形参为T引用类型，其函数被传引用调用。 */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习6.14
     * @description
     * 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。
     */
    /* 第一个例子：如前文所说的reset函数，
     * 第二个例子：输出某个实参自加的值，但是不能改变实参自身值
     * */
    static void meaninglessFunction_2();


    /**
     * @title
     * 练习6.15
     * @description
     * 说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？
     * 为什么s和occurs是引用类型而c不是？
     * 如果令s是普通引用会发生什么情况？
     * 如果令occurs是常量引用会发生什么情况？
     */
    /* ①、s作为目标string对象，仅需要了解该对象中的元素内容，并不需要修改其中的值
     * ②、s作为引用类型，因为string对象其值可能很大，使用引用类型避免值拷贝，c使用值传递目的是c作为指定字符，并不需要被修改，occurs作为额外返回信息，需要作为引用类型
     * ③、s作为普通引用，那么其值可以被修改，在find_char函数中其权限过高，可能会存在string对象被修改现象
     * ④、occurs如果为常量引用，那么其值不能被修改，无法正确计数
     * */
    static void meaninglessFunction_3();

    /**
     * @title
     * 6.2.3节练习
     */

    /**
     * @title
     * 练习6.16
     * @description
     * 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
     * @code
     * bool is_empty(string& s) {return s.empty();}
     */
    /* 由于仅读取string对象s是否为空，并不修改该对象，所以形参应该为const */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习6.17
     * @description
     * 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改成小写形式。在这两个函数中你使用的形参相同吗？为什么？
     */
    /* 不相同，第一个函数仅需要读取而第二个函数则需要修改，所以我会将第一个函数的形参设置为const引用类型，第二个则为普通类型
     */
    static void meaninglessFunction_5();

    /**
     * @title
     * 练习6.18
     * @description
     * 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。<br>
     * （a）名为compare的函数，返回布尔值，两个参数都是matrix类的引用。
     * （b）名为change_val的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。
     */
    /* a：从名字上我们不难看出，compare函数是对matrix类对象的比较，那么不存在修改情况，其函数声明应该为
     * bool compare(const matrix &first,const matrix &last);
     * b：名字为change_val，其功能大概是改变形参对象中的元素，那么我们便不能将其传入目标对象设置为const，其函数声明应该为：
     * vector<int>::iterator change_val(int value,vector<int> &object);
     * */
    static void meaninglessFunction_6();

    /**
     * @title
     * 练习6.19
     * @description
     * 假定有如下声明，判断哪个调用合法，哪个调用不合法。对于不合法的函数调用，说明原因。
     * @code
     * double calc(double);
     * int count(const string &,char);
     * int sum(vector<int>::iterator,vector<int>::iterator,int);
     * vector<int> vec(10);
     * (a) calc(23.4,55.1);             (b) count("abcda",'a');
     * (c) calc(66);                    (d) sum(vec.begin(),vec.end(),3.8);
     */
    /* a：不合法，其声明仅有一个double形参，调用该函数时传入实参存在两个
     * b：合法
     * c：合法
     * d：不合法，sum声明中第三个形参为int类型，而调用时初始化该形参的值为浮点数，类型不匹配。如果想要保留int类型的形参，则应该设置为const类型；如果不想要损失精度，则应该修改为const
     * double类型
     * */
    static void meaninglessFunction_7();

    /**
     * @title
     * 练习6.20
     * @description
     * 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？
     */
    /* 对引用对象我们并不需要修改时，可以设置为常量引用。如果修改，轻则误导调用者该对象可以被修改，重则编译失败） */
    static void meaninglessFunction_8();

    /**
     * @title
     * 6.2.4节练习
     */

    /**
     * @title
     * 练习6.21
     * @description
     * 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和直至所指的值，返回较大的那个。在该函数中指针的类型应该是什么？
     */
    static void exercise_6_21();

    /**
     * @title
     * 练习6.22
     * @description
     * 编写一个函数，令其交换两个int指针
     */
    static void exercise_6_22();

    /**
     * @title
     * 练习6.23
     * @description
     * 参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j：<br>
     * int i=0,j[2]={0,1};
     */
    static void exercise_6_23();

    /**
     * @title
     * 练习6.24
     * @description
     * 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
     * @code
     * void print(const int ia[10]){
     *      for(size_t i=0;i!=10;++i){
     *          cout<<ia[i]<<endl;
     * }
     */
    /* 该函数的参数定义为const int 类型，如果传入的参数数组并未存在10个元素，那么会发生数组越界问题。解决思路：const int
     * (&ia)[10] */

    /**
     * @title
     * 6.2.5节练习
     */

    /**
     * @title
     * 练习6.25
     * @description
     * 编写一个main函数，令其接受两个实参。把实参的内容链接城一个string对象并输出出来。
     */
    /*
       #include <iostream>
       #include <string>

       int main(int argc,char *argv[]){
           if (argv)
               while (*argv++)
                   std::cout<<*argv;
           return 0;
       }
     * */

    /**
     * @title
     * 练习6.26
     * @description
     * 编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参的内容。
     */
    /* 在本项目下的bin目录中存在prog可执行文件（Linux），其源码与练习6.25类似，
     * 只不过将编译条件设置为：g++ -o prog -g main.cpp
     * */

    /**
     * @title
     * 6.2.6节练习
     */
    /**
     * @title
     * 练习6.27
     * @description
     * 编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。
     */
    static void exercise_6_27();

    /**
     * @title
     * 练习6.28
     * @description
     * 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？
     */
    /* 从范围for循环中，可以看到elem类型应该为const string &类型 */
    static void meaninglessFunction_9();

    /**
     * @title
     * 练习6.29
     * @description
     *  在范围for循环中使用initializer_list对象时，应该键循环控制变量声明成引用类型吗？为什么？
     */
    /* 如果不使用引用方式，则elem对象值则通过拷贝得到，如果initializer_list中元素较少，不使用引用类型依旧可以，
     * 但是建议使用引用类型。如果initializer_list中元素较多，则应该使用引用方式，节省资源开销
     * */
};
#endif  // CPP_PRIMER_STUDYING_6_2_HPP
