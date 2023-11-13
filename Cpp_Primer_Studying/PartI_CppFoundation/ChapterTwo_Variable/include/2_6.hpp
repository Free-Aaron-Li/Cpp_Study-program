// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @data 2023-05-17-上午12:02
 * @license GPL-3.0
 */

#ifndef CPP_PRIMER_2_6_HPP
#define CPP_PRIMER_2_6_HPP

#include <string>

/**
 * @title
 * 2.6 自定义数据结构
 */

class Exercise_2_6 {
public:
    /**
     * @title
     * 2.6.1节练习
     */

    /**
     * @title
     * 练习2.39
     * @description
     * 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会用到。
     * @code
     *  struct Foo{...} 没有分号
     *  int main(){
     *  return 0;
     *  }
     */
    /* 会报错，由于没有分号编译器会将后续内容作为类的定义 */

    /**
     * @title
     * 练习2.39
     * @description
     * 根据自己的理解写出Sales_data类，最好与书中的例子有所区别。
     */
    /*
    struct Sales_data{
       std::string isbn;
       unsigned long sold_number;
       double sales_revenue;
    };
    */

    /**
     * @title
     * 2.6.2节练习
     */

    /**
     * @title
     * 练习2.41
     * @description
     *  使用你自己的Sales_data类重写1.5.1节、1.5.2节和1.6节的练习。眼下先把Sales——data类的定义和main函数放在同一个文件里。
     */
     /* TODO 23-5-17 编写Sales_data类完成练习2.41 */

     /**
      * @title
      * 2.6.3节练习
      */

     /**
      * @title
      * 练习2.42
      * @description
      *  根据你自己的理解重写一个Sales_data.h头文件，并依次为基础重做2.6.2节的练习。
      */

     /* TODO 23-5-17 重写Sales_data.h，重做2.6.2节练习 */
}; 
#endif //CPP_PRIMER_2_6_HPP
