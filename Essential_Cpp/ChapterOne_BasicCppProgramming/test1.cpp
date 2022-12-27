/**
 * @file test1.cpp
 * @author AaronLi
 * @date 2022-12-25-下午10:44
 * @description 第一个代码,输入姓名
 * @link 
 */

#include <iostream>
#include <string>

/* 标准库所驻之命名空间std */
using namespace std;

int main() {
    string user_firstname;
    string user_lastname;
    /* cout cin 为两个iostream类对象output 运算符 << */
    cout << "Please enter your first name: ";
    /* input 运算符 >> */
    cin >> user_firstname;
    cout << "Please enter your last name: ";
    cin >> user_lastname;
    cout << '\n'
         << "Hello, "
         << user_firstname
         << " "
         << user_lastname
         << " ... and goodbye \n";

    return 0;
}