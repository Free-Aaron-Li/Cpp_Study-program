/**
 * @author AaronLi
 * @date 2023-02-15-上午11:29
 * @license GPL-3.0
 */

#include "work_manager.h"

WorkManager::WorkManager() {}

// 展示菜单
void WorkManager::ShowMenu() {
    std::cout << "****************************************" << std::endl;
    std::cout << "********** 欢迎使用职工管理系统 ***********" << std::endl;
    std::cout << "***********  0、退出管理系统  ************" << std::endl;
    std::cout << "***********  1、增加职工信息  ************" << std::endl;
    std::cout << "***********  2、显示职工信息  ************" << std::endl;
    std::cout << "***********  3、删除职工信息  ************" << std::endl;
    std::cout << "***********  4、修改职工信息  ************" << std::endl;
    std::cout << "***********  5、查找职工信息  ************" << std::endl;
    std::cout << "***********  6、按照编号排序  ************" << std::endl;
    std::cout << "***********  7、清空所有文档  ************" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << std::endl;
}

/* 选择 */

[[noreturn]] void WorkManager::ChoiceMenu() {
    int choice = 0;
    while (true) {
        ShowMenu();
        std::cout << "请输入您的选项：";
    choice_one:
        std::cin >> choice;
        switch (choice) {
        case 0:  /* 退出系统*/
            ExitSystem();
            break;
        case 1:  // 添加职工
            break;
        case 2:  // 显示职工
            break;
        case 3:  // 删除职工
            break;
        case 4:  // 修改职工
            break;
        case 5:  // 查找职工
            break;
        case 6:  // 排序职工
            break;
        case 7:  // 清空文件
            break;
        default:
            std::cerr << "抱歉，您输入的选项有误，请重新输入：";
            goto choice_one;
        }
    }
}

void WorkManager::ExitSystem() {
    std::cout<<"欢迎您的下一次使用！"<<std::endl;
    exit(0);
}

WorkManager::~WorkManager() {}
