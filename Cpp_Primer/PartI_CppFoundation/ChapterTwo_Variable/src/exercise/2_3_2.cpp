/**
 * @author AaronLi
 * @date 2023-04-08-下午6:32
 * @license GPL-3.0
 */
#include "2_3.hpp"

void Exercise_2_3::Pointer() {
    ElemType value_1 = 10;
    ElemType value_2 = 20;
    ElemType *pointer_1;
    pointer_1 = &value_1; //set the value

    std::cout << "The value of pointer_1 is " << pointer_1 << " and the value of value_1 is " << value_1 << std::endl;

    /* 更改指针pointer_1的值 */
    pointer_1 = &value_2;

    std::cout << "The value of pointer_1 is " << pointer_1 << " and the value of value_1 is " << value_1 << std::endl;

    /* 更改指针所指向对象的值 */

    *pointer_1 = 100;

    std::cout << "The value of value_1 is " << value_1 << " and the value of value_2 is " << value_2 << std::endl;
}