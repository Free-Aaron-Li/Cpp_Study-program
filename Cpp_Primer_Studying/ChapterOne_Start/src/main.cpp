// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

/**
 * @author AaronLi
 * @date 2023-03-26-下午7:32
 * @license GPL-3.0
 */

#include "1_2.hpp"
#include "1_3.hpp"
#include "1_4.hpp"
#include "1_5.hpp"

void test_1_2() {
    Exercise_1_2::Hello();
    Exercise_1_2::Multiplication();
    Exercise_1_2::Output();
    Exercise_1_2::legal();
}

void test_1_3() {
    Exercise_1_3::ErrorComment();
    Exercise_1_3::LegalComment();
}

void test_1_4() {
    /** 1.4.1节练习 */
    //Exercise_1_4::SumFiftyToHundred();
    //Exercise_1_4::Decline();
    //Exercise_1_4::Integer();
    //Exercise_1_4::Sum();
    //Exercise_1_4::ForAndWhile();
    /** 1.4.3节练习 */
    //Exercise_1_4::OutputSum();
    /** 1.4.4节例题*/
    Exercise_1_4::StatisticalFrequency();
}

void test_1_5() {
    //Exercise_1_5::Book();
    //Exercise_1_5::BookSum();
    //Exercise_1_5::BooksSum();
    Exercise_1_5::SalesRecordSum();
}

int main() {
    //test_1_2();
    //test_1_3();
    //test_1_4();
    test_1_5();
    return 0;
}
