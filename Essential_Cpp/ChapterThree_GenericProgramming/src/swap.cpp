/**
 * @file Chapter1_1_find.cpp
 * @author AaronLi
 * @date
 * 2023-01-25-下午4:44
 * @description
 * <p> test <p>
 * @link
 */
#include "swap.hpp"

void swap(int a, int b) {
    int temp = a;
    a        = b;
    b        = temp;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}