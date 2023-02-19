/**
 * @author AaronLi
 * @date 2023-02-15-上午11:29
 * @license GPL-3.0
 */


#ifndef STUDYNOTES_WORK_MANAGER_H
#define STUDYNOTES_WORK_MANAGER_H

#pragma once /* 防止头文件重复包含 */
#include <iostream>


class WorkManager {
 public:
    WorkManager();

    /* 展示菜单 */
    static void ShowMenu();

    /* 选择界面 */
    [[noreturn]] static void ChoiceMenu();

    /* 1、退出系统*/
    static void ExitSystem();

    ~WorkManager();
};

#endif  // STUDYNOTES_WORK_MANAGER_H













