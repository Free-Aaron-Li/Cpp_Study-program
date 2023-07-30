// This file is part of Cpp_Primer_Studying project.
// This program is called:sales_data.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <utility>

class SalesData;

/* 类相关的非成员函数 */
inline SalesData     add(const SalesData &, const SalesData &);
inline std::ostream &print(std::ostream &, const SalesData &);
inline std::istream &read(std::istream &, SalesData &);

class SalesData {
 public:
    SalesData() = default; /* 默认构造函数，希望这个函数的作用等同于合成默认构造函数 */
    SalesData(std::string &str) : _bookNo(std::move(str)) {}
    /* std::move()将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝，因此，通过std::move()，可以避免不必要的拷贝操作
     */
    SalesData(std::string &str, unsigned number, double price) :
        _bookNo(std::move(str)), _units_sold(number), _revenue(price * number) {}
    SalesData(std::istream &istream) { read(istream, *this); }
    // SalesData():_bookNo(""),_units_sold(0),_revenue(0.0){}

 public:
    std::string isbn() const { return _bookNo; }
    SalesData  &combine(const SalesData &);
    double      avg_price() const;

 public:
    std::string _bookNo;           /* ISBN number */
    unsigned    _units_sold = 0;   /* the number of sales of a book */
    double      _revenue    = 0.0; /* the total of sales of a book */
};

inline SalesData &SalesData::combine(const SalesData &trans) {
    _units_sold += trans._units_sold;
    _revenue += trans._revenue;
    return *this; /* returns the object that calls the function */
}

inline double SalesData::avg_price() const {
    if (_units_sold)
        return _revenue / _units_sold;
    else
        return 0.0;
}

inline SalesData add(const SalesData &left_data, const SalesData &right_data) {
    /* 将lhs的副本初始化sum，默认情况下，拷贝类的对象其实是拷贝对象的数据成员。 */
    SalesData sum = left_data;
    sum.combine(right_data);
    return sum;
}

/* 一般来说，执行输出任务的函数应该尽量减少对格式化的控制，这样可以确保由用户决定是否执行换行 */
/* _bookNo,_units_sold,_revenue,arg_price,\t */
inline std::ostream &print(std::ostream &ostream, const SalesData &item) {
    ostream << item.isbn() << "\t" << item._units_sold << "\t" << item._revenue << "\t" << item.avg_price();
    return ostream;
}

/* _bookNo,_units_sold,sales_price */
inline std::istream &read(std::istream &istream, SalesData &item) {
    double sales_price;
    istream >> item._bookNo >> item._units_sold >> sales_price;
    item._revenue = item._units_sold * sales_price;
    return istream;
}

#endif
