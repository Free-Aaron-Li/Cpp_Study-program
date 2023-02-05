/**
 * @file menu.cpp
 * @author AaronLi
 * @date 2023-02-05-上午11:05
 * @description ${DESCRIPTION}
 */
#include <menu.hpp>

void showMenu() {
    cout << "*************************" << endl;
    cout << "*******1.添加联系人*******" << endl;
    cout << "*******2.显示联系人*******" << endl;
    cout << "*******3.删除联系人*******" << endl;
    cout << "*******4.查找联系人*******" << endl;
    cout << "*******5.修改联系人*******" << endl;
    cout << "*******6.清空联系人*******" << endl;
    cout << "*******7.退出通讯录*******" << endl;
    cout << "*************************" << endl;
}

void menu() {
    int  select_number = 0;
    bool tag           = true;
    do {
        showMenu();
        cout << "请输入命令执行编号：";
        cin >> select_number;
        switch (select_number) {
        case 1: cout << "1.添加联系人" << endl; break;
        case 2: cout << "2.显示联系人" << endl; break;
        case 3: cout << "3.删除联系人" << endl; break;
        case 4: cout << "4.查找联系人" << endl; break;
        case 5: cout << "5.修改联系人" << endl; break;
        case 6: cout << "6.清空联系人" << endl; break;
        case 7: tag = exit();
        default: break;
        }
    } while (tag);
}

bool exit() {
    string option = " ";
    cout << "是否选择退出(Y/N)：";
    cin >> option;
    if (option == "Y" || option == "y") {
        cout << "欢迎下次使用" << endl;
        return false;
    }
    return true;
}

void addPerson(AddressBook* person) {
    if (person->addressBook_Size == ADDRESSBOOK_MAXSIZE) {
        cerr << "抱歉，通讯录已满，无法添加！";
        return;
    }
    else {
        /* 姓名 */
        cout << "请输入联系人姓名：";
        if (
          person->contactPerson[person->addressBook_Size].person_Name.length()
          < 10) {
            cin >> person->contactPerson[person->addressBook_Size].person_Name;
        }
    }
}
