// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 AaronLi
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.

#include <iostream>
#include <string>

int test_1_subFunction(int value) {
    bool        i;
    char        j;
    wchar_t     k;
    char16_t    m;
    char32_t    u;
    short       q;
    long        w;
    long long   a;
    float       b;
    double      c;
    long double d;
    int         e[] = {};
    std::cout << "bool is " << i << "\n"
              << "char is " << j << "\n"
              << "wchar_t is " << k << "\n"
              << "char16_t is " << m << "\n"
              << "char32_t is " << u << "\n"
              << "short is " << q << "\n"
              << "long is " << w << "\n"
              << "long long is " << a << "\n"
              << "float is " << b << "\n"
              << "double is " << c << "\n"
              << "long double is " << d << "\n"
              << "int array is " << e[0] << "\n";
    return value;
}

/* 对局部对象的探索 */
void test_1() {
    int value = 10;
    /* 函数体是一个语句块，自构成一个作用域，其形参和函数体内变量为局部变量，对函数外层作用域同名声明具有隐藏性 */
    test_1_subFunction(value);

    /* 自动对象的默认初始值探索 */
}

/* 对函数指针形参简化的探索 */
std::string view(const std::string &str) { return str + "~~\n"; }

typedef decltype(view) name;
// typedef decltype(view) *name;
// typedef std::string name(const std::string &);
// typedef std::string (*name)(const std::string &);
// using name=std::string(const std::string &);
// using name=std::string(*)(const std::string &);


std::string print(const std::string &str, name name1) { return str + name1(" world"); }

void test_2() { std::cout << print("hello", view); }

int main() {
    // test_1();
    test_2();
    return 0;
}