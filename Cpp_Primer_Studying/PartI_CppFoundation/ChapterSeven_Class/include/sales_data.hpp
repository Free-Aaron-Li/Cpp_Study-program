// This file is part of Cpp_Primer_Studying project.
// This program is called:sales_data.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class SalesData {
 public:
    std::string _bookNo;           /* ISBN number */
    unsigned    _units_sold = 0;   /* the number of sales of a book */
    double      _revenue    = 0.0; /* the total of sales of a book */

 public:
    std::string isbn() const { return _bookNo; }
    SalesData  &combine(const SalesData &);
    double      avg_price() const;
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
inline std::ostream &print(std::ostream &ostream, const SalesData &item) {
    ostream << item.isbn() << "\t" << item._units_sold << "\t" << item._revenue << "\t" << item.avg_price();
    return ostream;
}

inline std::istream &read(std::istream &istream, SalesData &item) {
    double sales_price;
    istream >> item._bookNo >> item._units_sold >> sales_price;
    item._revenue = item._units_sold * sales_price;
    return istream;
}

#endif
