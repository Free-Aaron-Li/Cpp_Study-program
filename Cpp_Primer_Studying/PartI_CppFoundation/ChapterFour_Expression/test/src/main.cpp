// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include <iostream>
#include <vector>

/**
 * @title
 * 探究左值与右值
 * @description
 * 在4.1基础中提到左值和右值，虽然其本身概念继承于C语言，但是其概念在C++中得以扩展。
 */
void
test_RvalueAndLvalue() {
    /**
     * 广义上的左右值指的是运算符左侧对象称为左值，运算符右侧对象称为右值。其目的本质上是为了帮助程序员记忆。<br>
     * 在C++中提到左值表达式的求值结果是一个对象或者一个函数，但凡是必有例外：某些左值，例如常量对象实际上不能作为赋值语句的左侧运算对象。<br>
     * 在本书（《C++ Primer》）中做出这样的归纳：<br>
     * <ul>
     * <li>当一个对象被用作右值的时候，用的是对象的值（内容）；当对象被用作左值的时候，用的是对象的身份（内存地址）。</li>
     * </ul>
     * 但是归纳并不意味着真理，在实际的使用中，不同的运算符对运算对象有着不同的要求。这里提到一个重要原则<b>在需要右值的地方可以用左值来代替，但是不能把右值当成左值使用。当一个左值被当成右值使用时，实际使用的是它的内容（值）；当对象被用作左值的时候，用的是对象的身份（内存地址）</b>
     */

    /**
     * 赋值运算符需要一个非常量的左值作为左侧运算对象
     */
    int number_1 = 0;
    int number_2 = number_1; /* 返回的也是一个左值 */
    std::cout << "the result is " << number_2 << "\n";

    /**
     * 取地址符作用于一个左值运算对象，返回一个指向该运算对象的指针<br>
     * 该指针是一个右值
     */
    int *p_1 = &number_1;
    std::cout << "the pointer is " << p_1 << " and the value of the pointer to the object is " << *p_1 << "\n ";

    /**
     * 内置解引用运算符、下标运算符、迭代器解引用运算符 、string和vector的下标运算符的求值结果都是左值。
     */
    std::cout << "the p_1 is " << p_1 << " and the value of the pointer to the number_1 object is " << *p_1
              << std::endl;
    std::vector<int> vector_1(10, 1);
    std::cout << "the vector first value is " << vector_1[0]
              << "\n"; /* 在这里，下标实际上是用来确定该vector的内存位置，也是一个左值 */
    auto iterator_1 = vector_1.begin(); /* auto is std::vector<int>::iterator */
    std::cout << "the value of the iterator to the vector_1 object is " << *iterator_1 << "\n";

    /**
     * 总结来说：还是那个重要原则，根据上下文和实际情况合适判断。<br>
     * 虽然本质上左值和右值是帮助程序员记忆方便，但是在某些情况下如果不能弄清楚运算符的运算对象的左右值，可能会造成不必要的麻烦。
     */
    int                                      number_3, number_4;
    decltype(number_3 = number_1 + number_2) i =
      number_1; /* 使用decltype关键字，如果其作用于一个表达式，返回一个引用类型，例如这里的int & */
    int           *p_2 = &number_1;
    int           *p_3 = &number_2;
    decltype(*p_2) j   = number_2; /* int &，解引用符号生成的是左值 */
    decltype(&p_2) k   = &p_3;     /* int**，取地址符号生成的是右值 */
}


int test_number = 1;

int
test_evaluationOrder_test_1() {
    return test_number++;
}
int
test_evaluationOrder_test_2() {
    return test_number += 3;
}


/**
 * 求值顺序的探讨
 */
void
test_evaluationOrder() {
    int i = 0;
    /**
     * <<运算符并未明确规定何时以及如何对运算对象进行求值，没有明确的执行顺序，那么该表达式就是错误的。因为您无法确定是i先执行还是++i先执行，得到的答案不论如何都是错误的
     * */
    std::cout << i << " " << ++i << "\n";

    /**
     * 同理：这下面一句也是错误的。
     * 你无法判断是test_1()先执行还是test_2()先执行。
     */
    int number = test_evaluationOrder_test_1() * test_evaluationOrder_test_2();
    std::cout << number << "\n";
}

/**
 * 对算术运算异常和溢出的探讨
 */
void
test_ArithmeticOperations() {
    /* 若short类型占16位，那么short最大数值为32767 */
    short value = 32767;
    value++;
    std::cout << value << "\n"; /* -32768 */
    /**
     * 由于值溢出，发生“环绕（wrapped around）”，然符号位由0变为1，导致结果为负数
     */
}

void
test_assignmentOperation() {
    int k = {};
    /**
     * 无论左侧运算对象的类型是什么，初始值列表都可以为空。此时，编译器创建一个值初始化的临时量并将其赋给左侧运算对象。
     */
    std::cout << k << "\n";

    /**
     * 赋值运算符的返回值
     */
    int i;
    if (i = 1024) std::cout << "true";
    else std::cout << "false";
}

void
test_iterator() {
    std::vector<std::string>           vector{10, "1"};
    std::vector<int>                   vector_1{10, 1};
    std::vector<std::string>::iterator i = vector.begin();
    std::vector<int>::iterator         j = vector_1.begin();
    // vector.empty();
    // i.empty();   迭代器中并没有empty方法
    // i->empty();
    // std::cout << ++*i << "\n";
    std::cout << ++*j << "\n";
    std::cout << i++->empty() << "\n";
}

void
test_4_23() {
    std::string s  = "word";
    std::string p1 = s + ((s[s.size() - 1] == 's') ? "" : "s");
    std::cout << p1;
}

int
main() {
    // test_RvalueAndLvalue();
    // test_evaluationOrder();
    // test_ArithmeticOperations();
    // test_assignmentOperation();
    // test_iterator();
    test_4_23();
    return 0;
}