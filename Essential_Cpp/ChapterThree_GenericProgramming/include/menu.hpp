/**
 * @file menu.hpp
 * @author AaronLi
 * @date 2023-02-05-上午11:11
 * @description
 */

#ifndef CHAPTERTHREE_MENU_HPP
#define CHAPTERTHREE_MENU_HPP


#include <iostream>
#include <string>
#define ADDRESSBOOK_MAXSIZE 1000
using namespace std;

/**
 * @description
 * <p> 联系人结构 </P>
 * <p> 联系人信息包括（姓名、性别、年龄、联系电话、家庭住址）<p>
 */

struct ContactPerson {
    string person_Name;
    string person_Gender = "man";
    int    person_Age{};
    string person_PhoneNumber{};
    string person_Address;
};

struct AddressBook {
    ContactPerson contactPerson[ADDRESSBOOK_MAXSIZE];
    int           addressBook_Size{};
};

void showMenu();
void showTitle();
void showDividingLine();
void menu(AddressBook* addressBook);
bool exit();
void addPerson(AddressBook* person);
void printPerson(AddressBook* person);
int isExist(AddressBook* person,const string& name);
void deletePerson(AddressBook* person);
void modifyingPerson(AddressBook* person);
void cleanPerson(AddressBook* person);

#endif  // CHAPTERTHREE_MENU_HPP
