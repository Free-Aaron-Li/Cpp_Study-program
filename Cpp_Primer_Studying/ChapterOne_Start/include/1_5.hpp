//
// Created by AaronLi on 23-4-5.
//

#ifndef CPP_PRIMER_1_5_HPP
#define CPP_PRIMER_1_5_HPP

/**
 * @title
 * <p> 1.5节练习——类简介 </P>
 * @description
 */

#include <iostream>

typedef int ElemType;

class Exercise_1_5 {
public:
    /**
     * @title
     * <p> 1.5.1节练习——Sales_item类 </P>
     */

    /**
     * @title
     * <p> 练习1.20 </P>
     * @description
     *  根据《C++ Primer》提供的第一章源代码中头文件Sales_item.h。编写一个程序，读取一组书籍销售记录，将每条记录打印在标准输出上
     */

    static void Book();

    /**
     * @title
     * <p> 练习1.21 </P>
     * @description
     *  编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和
     */
    static void BookSum();

    /**
     * @title
     * <p> 练习1.22 </P>
     * @description
     *  编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和
     */
    static void BooksSum();
    /**
     * @title
     * <p> 1.5.2节练习——初识成员函数 </P>
     */
/**
 * @title
 * <p> 练习1.23 </P>
 * @description
 *  编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录
 */
    static void SalesRecordSum();
    /**
     * @title
     * <p> 练习1.24 </P>
     * @description
     *  输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起
     */
    // 具体实现见上一个方法
};

#endif //CPP_PRIMER_1_5_HPP
