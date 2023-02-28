/**
 * @author AaronLi
 * @date 2023-02-27-上午11:40
 * @license GPL-3.0
 */
#include "swap.hpp"

void SwapInt(int &a, int &b) {
    int temporary = a;
    a             = b;
    b             = temporary;
}

void SwapDouble(double &a, double &b) {
    double temporary = a;
    a                = b;
    b                = temporary;
}

template <typename T> /* 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型 */
void Swap(T &a, T &b) {
    T temporary = a;
    a           = b;
    b           = temporary;
}

int Test() {
    int a = 10;
    int b = 20;
    SwapInt(a, b);
    std::cout << "a is " << a << "\nb is " << b << "\n";

    double c = 20.1;
    double d = 30.2;
    SwapDouble(c, d);
    std::cout << "c is " << c << "\nd is " << d << "\n";
    std::cout << std::endl;

    Swap(a, b);
    std::cout << "a is " << a << "\nb is " << b << "\n";
    Swap(c, d);
    std::cout << "c is " << c << "\nd is " << d << "\n";
    std::cout << std::endl;

    return 0;
}