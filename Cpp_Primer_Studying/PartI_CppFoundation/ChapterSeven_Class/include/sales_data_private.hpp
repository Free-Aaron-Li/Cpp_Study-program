// This file is part of Cpp_Primer_Studying project.
// This program is called:sales_data_private.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_SALES_DATA_PRIVATE_HPP
#define CPP_PRIMER_STUDYING_SALES_DATA_PRIVATE_HPP

#include <iostream>
#include <string>
#include <utility>

class SalesData_pr;

SalesData_pr  add(const SalesData_pr &, const SalesData_pr &);
std::ostream &print(std::ostream &, const SalesData_pr &);
std::istream &read(std::istream &, SalesData_pr &);

class SalesData_pr {
    /* 类相关的非成员函数 */
    friend SalesData_pr  add(const SalesData_pr &, const SalesData_pr &);
    friend std::ostream &print(std::ostream &, const SalesData_pr &);
    friend std::istream &read(std::istream &, SalesData_pr &);

 public:
    SalesData_pr(std::string str, unsigned number, double price) :
        /*
         * std::move()将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝，因此，通过std::move()，可以避免不必要的拷贝操作
         */
        _bookNo(std::move(str)), _units_sold(number), _revenue(price * number) {
        std::cout << "这是含有三个参数的受委托构造函数\n";
    }
    // SalesData_pr() = default; /* 默认构造函数，希望这个函数的作用等同于合成默认构造函数 */
    SalesData_pr() : SalesData_pr("", 0, 0.0) { /* 形式等于默认构造函数，C++11新特性：委托构造函数 */
        std::cout << " 这是重写的默认构造函数\n";
    };
    SalesData_pr(std::string &str) : SalesData_pr(str, 0, 0.0) { std::cout << "这是自定义isbn编码的委托函数\n"; }
    /* 委托给重写的默认构造函数，默认构造函数又委托给具有三个参数的构造函数，接着执行函数体内内容 */
    SalesData_pr(std::istream &istream) : SalesData_pr() {
        std::cout << "这是需要全部自定义的委托函数\n";
        read(istream, *this);
    }
    // SalesData_pr():_bookNo(""),_units_sold(0),_revenue(0.0){}

 public:
    std::string   isbn() const { return _bookNo; }
    SalesData_pr &combine(const SalesData_pr &);

 private:
    double      avg_price() const { return _units_sold != 0 ? (_revenue / _units_sold) : 0.0; };
    std::string _bookNo;           /* ISBN number */
    unsigned    _units_sold = 0;   /* the number of sales of a book */
    double      _revenue    = 0.0; /* the total of sales of a book */
};

inline SalesData_pr &SalesData_pr::combine(const SalesData_pr &trans) {
    _units_sold += trans._units_sold;
    _revenue += trans._revenue;
    return *this; /* returns the object that calls the function */
}

inline SalesData_pr add(const SalesData_pr &left_data, const SalesData_pr &right_data) {
    /* 将lhs的副本初始化sum，默认情况下，拷贝类的对象其实是拷贝对象的数据成员。 */
    SalesData_pr sum = left_data;
    sum.combine(right_data);
    return sum;
}

/* 一般来说，执行输出任务的函数应该尽量减少对格式化的控制，这样可以确保由用户决定是否执行换行 */
/* _bookNo,_units_sold,_revenue,arg_price,\t */
inline std::ostream &print(std::ostream &ostream, const SalesData_pr &item) {
    ostream << item.isbn() << "\t" << item._units_sold << "\t" << item._revenue << "\t" << item.avg_price();
    return ostream;
}

/* _bookNo,_units_sold,sales_price */
inline std::istream &read(std::istream &istream, SalesData_pr &item) {
    double sales_price;
    istream >> item._bookNo >> item._units_sold >> sales_price;
    item._revenue = item._units_sold * sales_price;
    return istream;
}

#endif  // CPP_PRIMER_STUDYING_SALES_DATA_PRIVATE_HPP
