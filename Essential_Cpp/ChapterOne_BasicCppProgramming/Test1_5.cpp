/**
 * @file test1_5.cpp
 * @author AaronLi
 * @date 2022-12-28-下午2:24
 * @description
 * <p> 练习1.5 </p>
 * <p></p>
 * <p>
 * 编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。
 * 如果用户的确输入了有效名称，就响应一些信息。请以两种方式实现：第一种使用C-style字符串，第二种使用string对象。
 * </p>
 * @link 
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/**
 * @date 22-12-28 下午3:02
 * @description 使用string存储姓名，并根据长度做出响应
 */

int main() {
    string user_name;

    cout << "Welcome,Please enter your username: ";
    cin >> user_name;

    switch (user_name.size()) {
        case 0:
            cerr << "NO！Your name can't be empty";
            break;
        case 1:
            cout << "Ahh! Your name is 1 character long.This is really unique！\n"
                 << "Hello! " << user_name << endl;
            break;
        default:
            cout << "Hello! "<<user_name<<",Welcome!"<<endl;
            break;
    }
    return 0;
}

/**
 * @date 22-12-28 下午3:03
 * @description 使用C-style字符串存储姓名，并根据姓名长度做出响应。
 */
/*

int main() {
    */
/* 必须分配一个大小固定的空间 *//*

    const int nm_size = 128;
    char user_name[nm_size];
    cout << "Welcome,Please enter your username: ";
    cin >> setw(nm_size) >> user_name;

    switch (strlen(user_name)) {
        case 0:
            cerr << "NO！Your name can't be empty";
            break;
        case 1:
            cout << "Ahh! Your name is 1 character long.This is really unique！\n"
                 << "Hello! " << user_name << endl;
            break;
        case 127:
            cerr << "Oh! This is the longest name you can fill in. You have a very special name. Well, how do you pronounce it?";
        default:
            cout << "\n Hello! Welcome "<<user_name
            <<"Nice to meet you";
            break;
    }
    return 0;
}
*/
