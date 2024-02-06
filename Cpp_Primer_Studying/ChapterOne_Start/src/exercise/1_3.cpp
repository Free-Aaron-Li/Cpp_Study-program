// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-04-01-下午10:22
 * @license GPL-3.0
 */

#include "1_3.hpp"

void Exercise_1_3::ErrorComment() {
    /*
     * this is a correct comment
     */
    std::cout << "this is test!" << std::endl;
    std::cout << "如果嵌套使用注释，将会出现该错误“expected primary-expression before ‘/’ token”" << std::endl;
}

void Exercise_1_3::LegalComment() {
    //  std::cout<< /* "*/" */;
    //  std::cout<<"*/"; 
    //  std::cout << /* "/*" */;
    //  std::cout<< /* "*/" /* "/*" */;
    std::cout<<"最终，仅有第二和第四条合法"<<std::endl;
}