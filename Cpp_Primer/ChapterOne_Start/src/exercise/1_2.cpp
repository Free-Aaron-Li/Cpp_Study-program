/**
 * @author AaronLi
 * @date 2023-03-29-下午6:09
 * @license GPL-3.0
 */
#include "1_2.hpp"

void Exercise::Hello() { std::cout << "Hello,World" << std::endl; }

void Exercise::Multiplication() {
    ElemType value_1 = 0;
    ElemType value_2 = 0;
    ElemType result;

    std::cout << "输入第一个元素值：";
    std::cin >> value_1;
    std::cout << "输入第二个元素值：";
    std::cin >> value_2;

    result = value_1 * value_2;
    std::cout << "两元素乘积为：" << value_1 << "*" << value_2 << "=" << result << std::endl;

    IsolationZone();
}

void Exercise::Output() {
    ElemType value_1 = 0;
    ElemType value_2 = 0;

    std::cout << "输入第一个元素值：";
    std::cin >> value_1;
    std::cout << "输入第二个元素值：";
    std::cin >> value_2;

    std::cout << "两元素乘积为：" << value_1 << "*" << value_2 << "=" << value_1 * value_2
              << std::endl;

    IsolationZone();
}

/**
 * @description
 * <p> 不合法 </P>
 * 使用“;”表示语句的结束。<br>
 * 解决思路：<br>
 * 1、删除前两个“;”。<br>
 * 2、在第二条和第三条语句前添加@code std::cout
 */

void Exercise::legal() {
    ElemType v1 = 1;
    ElemType v2 = 2;
    /* 方法一 */
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    /* 方法二 */
    std::cout << "The sum of " << v1;
    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
}

void Exercise::IsolationZone() { std::cout << "**************************" << std::endl; }
