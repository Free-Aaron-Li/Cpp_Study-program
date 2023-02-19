//
// Created by AaronLi on 23-2-16.
//

#ifndef PHASE4_MANAGER_HPP
#define PHASE4_MANAGER_HPP

#include "worker.h"

/* 经理类，继承于职工抽象类 */
class Manager : public Worker {
 public:
    /**
     * @param
     * int id   : the id of the manager <br>
     * string name : the name of the manager <br>
     * int dept_id : the department id of the manager <br>
     * @return
     * @description
     * 构造函数
     */
    Manager(int id, std::string name, int dept_id);

    /* 显示个人信息 */
    void ShowInfo() override;

    /* 获取职工岗位名称 */
    std::string get_DepartmentName() override;
};


#endif  // PHASE4_MANAGER_HPP
