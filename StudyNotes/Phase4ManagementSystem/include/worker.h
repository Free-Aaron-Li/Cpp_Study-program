//
// Created by AaronLi on 23-2-16.
//

#ifndef PHASE4_WORKER_H
#define PHASE4_WORKER_H

#include <iostream>
#include <string>

/* 职工抽象类 */
class Worker {
 public:
    /* 职工编号 */
    int         worker_id_;
    /* 职工姓名 */
    std::string worker_name_;
    /* 部门编号 */
    int         worker_department_id_;

 public:
    /* 显示个人信息 */
    virtual void        ShowInfo()           = 0;
    /* 获取岗位名称 */
    virtual std::string get_DepartmentName() = 0;
};

#endif  // PHASE4_WORKER_H
