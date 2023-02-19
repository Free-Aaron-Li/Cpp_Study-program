/**
 * @author AaronLi
 * @date 2023-02-15-上午11:29
 * @license GPL-3.0
 */

#ifndef STUDYNOTES_WORK_MANAGER_H
#define STUDYNOTES_WORK_MANAGER_H

#pragma once /* 防止头文件重复包含 */
#include <fstream>
#include <iostream>

#include "boss.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "worker.h"

#define FILENAME "data.txt"

class WorkManager {
 public:
    WorkManager();

    /* 展示菜单 */
    static void ShowMenu();

    /* 选择界面 */
    [[noreturn]] void ChoiceMenu();

    /* 1、退出系统*/
    static void ExitSystem();

    /* 2、记录职工人数 */
    int worker_number_;

    /* 3、职工数组指针 */
    Worker** worker_array_;

    /* 4、添加职工 */
    void AddNewWorker(int add_worker_number, Worker** worker_array) const;
    void AddWorker();

    /* 5、保存文件 */
    void Save() const;

    /* 6、读取文件 */
    bool       file_is_empty;
    static int get_WorkerNumber();

    /* 7、初始化数组 */
    void InitWorkerArray() const;

    /* 8、显示职工信息 */
    void ShowWorkerInfo() const;

    /* 职工是否存在
     * 返回值为-1表示不存在
     * */
    [[nodiscard]] int  WorkerIsExist(int worker_id) const;
    /* 9、删除职工 */
    void DeleteWorker();

    /* 10、修改职工信息 */
    void RemoveWorkerInfo() const;

    /* 按照职工号查找 */
    void FindWorkerById() const;

    /* 按照职工姓名查找 */
    void FindWorkerByName() const;

    /* 11、查找职工 */
    void FindWorker() const;

    /* 12、排序职工编号 */
    void SortWorker() const;

    /* 13、清空职工记录 */
    void CleanFile();

    ~WorkManager();
};

#endif  // STUDYNOTES_WORK_MANAGER_H
