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
    cout << "*******2.删除联系人*******" << endl;
    cout << "*******3.查找联系人*******" << endl;
    cout << "*******4.修改联系人*******" << endl;
    cout << "*******5.清空联系人*******" << endl;
    cout << "*******6.退出通讯录*******" << endl;
    cout << "*************************" << endl;
}

void showTitle() {
    cout << "*************************" << endl;
    cout << "******通讯录管理系统*******" << endl;
}

void showDividingLine() { cout << "*********************************************" << endl; }

void menu(AddressBook* addressBook) {
    int  select_number = 0;
    bool tag           = true;
    do {
        showTitle();
        showMenu();
        cout << "请输入命令执行编号：";
        cin >> select_number;
        switch (select_number) {
        case 1: addPerson(addressBook); break;
        case 2: deletePerson(addressBook); break;
        case 3: printPerson(addressBook); break;
        case 4: modifyingPerson(addressBook); break;
        case 5: cleanPerson(addressBook); break;
        case 6: tag = exit();
        default: break;
        }
    } while (tag);
}

bool exit() {
    showDividingLine();
    string option = " ";
    cout << "是否选择退出(Y/N)：";
    cin >> option;
    if (option == "Y" || option == "y") {
        cout << "欢迎下次使用" << endl;
        showDividingLine();
        return false;
    }
    return true;
}

void addPerson(AddressBook* person) {
    showDividingLine();
    if (person->addressBook_Size == ADDRESSBOOK_MAXSIZE) {
        cerr << "抱歉，通讯录已满，无法添加！";
        showDividingLine();
        return;
    }
    else {
        /* 姓名 */
        showDividingLine();
        cout << "请输入联系人姓名：";
        string name = " ";
        do {
            cin >> name;
            if (name.length() <= 0) { cerr << "联系人姓名不能为空，请重新输入联系人姓名" << endl; }
            if (name.length() > 10) {
                cerr << "联系人姓名长度超过10位，请重新输入联系人姓名" << endl;
            }
            else { person->contactPerson[person->addressBook_Size].person_Name = name; }
        } while (name.length() <= 0 || name.length() > 10);

        /* 性别 */
        cout << "请输入联系人性别（男|女）：";
        string gender;
    Tag1:
        cin >> gender;
        if (gender == "男" || gender == "女") {
            person->contactPerson[person->addressBook_Size].person_Gender = gender;
        }
        else {
            cerr << "联系人性别错误！请重新输入" << endl;
            goto Tag1;
        }

        /* 年龄 */
        cout << "请输入联系人年龄：";
        int age = 0;
    Tag2:
        cin >> age;
        if (age < 0 || age > 150) {
            cerr << "联系人年龄超过150岁或为负整数！请重新输入" << endl;
            goto Tag2;
        }
        else { person->contactPerson[person->addressBook_Size].person_Age = age; }

        /* 联系电话 */
        cout << "请输入联系人电话：";
        string phoneNumber = " ";
    Tag3:
        cin >> phoneNumber;
        if (phoneNumber.length() > 11 || phoneNumber.length() <= 0) {
            cerr << "联系人电话号码长度大于11位或电话号码为空，请重新输入" << endl;
            goto Tag3;
        }
        else { person->contactPerson[person->addressBook_Size].person_PhoneNumber = phoneNumber; }

        /* 家庭地址 */
        cout << "请输入联系人家庭地址：";
        string address = " ";
    Tag4:
        cin >> address;
        if (address.length() > 30 || address.length() <= 0) {
            cerr << "家庭地址长度超过30位或为空，请重新输入" << endl;
            goto Tag4;
        }
        else { person->contactPerson[person->addressBook_Size].person_Address = address; }

        /* 更新通讯录名单大小 */
        person->addressBook_Size++;

        cout << "成功添加联系人！" << endl;
        showDividingLine();
    }
}

void printPerson(AddressBook* person) {
    showDividingLine();
    if (person->addressBook_Size == 0) {
        cerr << "当前记录为空" << endl;
        return;
    }
    cout << "请选择查找方式，全部查找（1）或定位查找（2）" << endl;

Print_Tag1:
    int choice = 0;
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < person->addressBook_Size; ++i) {
            cout << "姓名：" << person->contactPerson[i].person_Name << "\t\t";
            cout << "性别：" << person->contactPerson[i].person_Gender << "\t\t";
            cout << "年龄：" << person->contactPerson[i].person_Age << "\t\t";
            cout << "电话号码：" << person->contactPerson[i].person_PhoneNumber << "\t\t";
            cout << "家庭地址：" << person->contactPerson[i].person_Address << endl;
        }
    }
    else if (choice == 2) {
        int number = 0;
        cout << "当前通讯录总共存放有：" << person->addressBook_Size << "位联系人信息" << endl;
        cout << "请输入你想要查询的编号：";
    Print_Tag2:
        cin >> number;
        if (number > person->addressBook_Size || number <= 0) {
            cerr << "查询位置错误！请重新输入：";
            goto Print_Tag2;
        }
        else {
            cout << "第" << number << "位联系人信息如下：" << endl;
            cout << "姓名：" << person->contactPerson[number - 1].person_Name << endl;
            cout << "性别：" << person->contactPerson[number - 1].person_Gender << endl;
            cout << "年龄：" << person->contactPerson[number - 1].person_Age << endl;
            cout << "电话号码：" << person->contactPerson[number - 1].person_PhoneNumber << endl;
            cout << "家庭地址：" << person->contactPerson[number - 1].person_Address << endl;
        }
    }
    else {
        cerr << "输入命令错误，请重新输入：";
        goto Print_Tag1;
    }
    showDividingLine();
}

int isExist(AddressBook* person, const string& name) {
    for (int i = 0; i < person->addressBook_Size; ++i) {
        if (person->contactPerson[i].person_Name == name) { return i; }
    }
    return -1;
}

void deletePerson(AddressBook* person) {
    showDividingLine();
    string Person_Name = " ";
    cout << "请输入想要删除的联系人姓名：";
    cin >> Person_Name;
    int subscript = isExist(person, Person_Name);
    if (subscript == -1) {
        cerr << "抱歉，通讯录中并没有此人！" << endl;
        return;
    }
    else {
        for (int i = subscript; i < person->addressBook_Size; ++i) {
            person->contactPerson[i] = person->contactPerson[i + 1];
        }
        --person->addressBook_Size;
        cout << "成功删除" << endl;
    }
}

void modifyingPerson(AddressBook* person) {
    showDividingLine();
    string Person_Name = " ";
    cout << "请输入想要修改的联系人姓名：";
    cin >> Person_Name;
    int subscript = isExist(person, Person_Name);
    if (subscript != -1) {
        cout << "请输入修改内容" << endl;

    Modify_Tag1:
        cout << "原始信息 姓名：" << person->contactPerson[subscript].person_Name << endl;
        cout << "修改为：";
        string Modifying_Name = " ";
        cin >> Modifying_Name;
        if (Modifying_Name.length() > 10) {
            showDividingLine();
            cerr << "抱歉，姓名长度超过10位！请重新输入" << endl;
            goto Modify_Tag1;
        }
        else { person->contactPerson[subscript].person_Name = Modifying_Name; }

    Modify_Tag2:
        cout << "原始信息 性别：" << person->contactPerson[subscript].person_Gender << endl;
        cout << "修改为：";
        string Modifying_Gender = " ";
        cin >> Modifying_Gender;
        if (Modifying_Gender != "男" || Modifying_Gender != "女") {
            showDividingLine();
            cerr << "抱歉，性别错误！请重新输入" << endl;
            goto Modify_Tag2;
        }
        else { person->contactPerson[subscript].person_Gender = Modifying_Gender; }

    Modify_Tag3:
        cout << "原始信息 年龄：" << person->contactPerson[subscript].person_Age << endl;
        cout << "修改为：";
        int Modifying_Age = 0;
        cin >> Modifying_Age;
        if (Modifying_Age > 150 || Modifying_Age <= 0) {
            showDividingLine();
            cerr << "抱歉，年龄超过150岁或年龄为负整数！请重新输入" << endl;
            goto Modify_Tag3;
        }
        else { person->contactPerson[subscript].person_Age = Modifying_Age; }

    Modify_Tag4:
        cout << "原始信息 电话号码：" << person->contactPerson[subscript].person_PhoneNumber
             << endl;
        cout << "修改为：";
        string Modifying_PhoneNumber = " ";
        cin >> Modifying_PhoneNumber;
        if (Modifying_PhoneNumber.length() > 11 || Modifying_PhoneNumber.length() <= 0) {
            showDividingLine();
            cerr << "抱歉，电话号码超过11位或电话号码为空！请重新输入" << endl;
            goto Modify_Tag4;
        }
        else { person->contactPerson[subscript].person_PhoneNumber = Modifying_PhoneNumber; }

    Modify_Tag5:
        cout << "原始信息 家庭地址：" << person->contactPerson[subscript].person_Address << endl;
        cout << "修改为：";
        string Modifying_Address = " ";
        cin >> Modifying_Address;
        if (Modifying_Address.length() > 30 || Modifying_Address.length() <= 0) {
            showDividingLine();
            cerr << "抱歉，电话地址过长或电话地址为0！请重新输入" << endl;
            goto Modify_Tag5;
        }
        else { person->contactPerson[subscript].person_Address = Modifying_Address; }
    }
    else {
        cerr << "抱歉，通讯录中并没有此人！" << endl;
        return;
    }
}

void cleanPerson(AddressBook* person) {
    showDividingLine();
    cout << "是否选择清空通讯录（Y|N）?" << endl;
    string choice = " ";
    cin >> choice;
    if (choice == "Y" || choice == "y") {
        cout << "你确定吗（Y|N）？" << endl;
        string Finally_Choice = " ";
        cin >> Finally_Choice;
        if (choice == "Y" || choice == "y") {
            person->addressBook_Size = 0;
            cout << "成功清空通讯录" << endl;
        }
        else { return; }
    }
    else { return; }
}
