// This file is part of Cpp_Primer_Studying project.
// This program is called:7_5.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_7_5_HPP
#define CPP_PRIMER_STUDYING_7_5_HPP

/**
 * @title
 * 7.5 构造函数再探
 */

#include "7.hpp"

class Exercise_7_5 {
 public:
    /**
     * @title
     * 7.5.1节练习
     */

    /**
     * @title
     * 练习7.36
     * @description
     * 下面的初始值是错误的，请找出问题所在并尝试修改它。
     * @code
     * struct X{
     *      X(int i,int j):base(i),rem(base%j){}
     *      int rem,base;
     * };
     */
    /*
     * 由于rem与base在类中声明的顺序是rem在前，base在后。所以rem先初始化，但是在构造函数中定义的顺序为base在前，rem在后。
     * 所以导致，使用未定义值初始化rem。
     * 修改为：
     * 1| struct X{
     * 2|      X(int i,int j):rem(i),base(i%j){}
     * 3|      int rem,base;
     * 4| };
     * */
    static void meaninglessFunction_1();

    /**
     * @title
     * 练习7.37
     * @description
     * 使用本节提供的Sales_data类（这里笔者使用的是SalesData类），确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。
     * @code
     * 1| Sales_data first_item(cin);
     * 2|
     * 3| int main(){
     * 4|      Sales_data next;
     * 5|      Sales_data last("9-999-99999-9");
     * 6| }
     */
    /*
     * 行号1：使用了SalesData(std::istream &istream) { read(istream, *this); }，
     * 数据成员：使用输入流中的输入值；
     * 行号4：使用了SalesData(std::string s = "") : _bookNo(std::move(s)){}; ，
     * 数据成员：__bookNo:""，_units_sold：0，_revenue：0.0；
     * 行号5：使用了SalesData(std::string &str) : _bookNo(std::move(str)) {}，
     * 数据成员：__bookNo:str，_units_sold：0，_revenue：0.0；
     * */
    static void meaninglessFunction_2();

    /**
     * @title
     * 练习7.38
     * @description
     * 有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。
     */
    /* SalesData(std::istream &istream=std::cin) { read(istream, *this); }*/
    static void meaninglessFunction_3();

    /**
     * @title
     * 练习7.39
     * @description
     * 如果接受string的构造函数和接受istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？
     */
     /* 不合法，这个时候重载构造函数将会不明确，存在二义性，编译器无法确认是选择使用string对象还是istream对象 */
    static void meaninglessFunction_4();

    /**
     * @title
     * 练习7.40
     * @description
     * 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
     * @code
     * (a) Book         (b) Date        (c) Employee
     * (d) Vehicle      (e) Object      (d) Tree
     */
     /*
      * 我选择a项。
      * 作为Book，其必然少不了ISBN编码、同时还可以加入单价、出版社、作者、版次等等
      * 那么数据成员可以有：_isbn、_unit_price、_publishing_house、_author、_edition_number。
      * 构造函数可以有：
      * Book(std::istream& is){read(is,*this);}
      * Book(std::string isbn bookNo,unsigned long price,std::string house,std::string author,std::string number):
      *     _isbn(bookNo),_unit_price(price),_publishing_house(house),_author(author),_edition_number(number){};
      * Book(std::string isbn bookNo,unsigned long price,std::string house,std::string author="xxx",std::string number):
*     *     _isbn(bookNo),_unit_price(price),_publishing_house(house),_author(author),_edition_number(number){};
      * */
    static void meaninglessFunction_5();
};
#endif  // CPP_PRIMER_STUDYING_7_5_HPP
