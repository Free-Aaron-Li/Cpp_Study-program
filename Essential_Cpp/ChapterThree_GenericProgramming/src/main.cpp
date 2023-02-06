/**
 * @file main.cpp
 * @author AaronLi
 * @date 2023-02-03-下午12:22
 * @description
 */

#include "menu.hpp"

int main() {
    /* 初始化 */
    AddressBook addressBook;
    addressBook.addressBook_Size = 0;
    menu(&addressBook);
}
