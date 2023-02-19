//
// Created by AaronLi on 23-2-16.
//

#ifndef PHASE4_EMPLOYEE_HPP
#define PHASE4_EMPLOYEE_HPP

#include "worker.h"

/* 员工类，继承于职工抽象类 */
class Employee : public Worker {
 public:
    /**
     * @param
     * int id   : the id of the employee <br>
     * string name : the name of the employee <br>
     * int dept_id : the department id of the employee <br>
     * @return
     * @description
     * 构造函数
     */
    Employee(int id, std::string name, int dept_id);

    /* 显示个人信息 */
    void ShowInfo() override ;

    /* 获取职工岗位名称 */
    std::string get_DepartmentName() override;
};


#endif  // PHASE4_EMPLOYEE_HPP
