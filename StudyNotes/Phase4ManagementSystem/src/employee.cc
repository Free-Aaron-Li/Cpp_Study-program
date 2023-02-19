/**
 * @author AaronLi
 * @date 2023-02-16-下午9:55
 * @license GPL-3.0
 */
#include "employee.hpp"

Employee::Employee(int id, std::string name, int dept_id) {
    this->worker_id_            = id;
    this->worker_name_          = name;
    this->worker_department_id_ = dept_id;
}

void Employee::ShowInfo(){
    std::cout << "职工编号：" << this->worker_id_ << "\t职工姓名：" << this->worker_name_
              << "\t\t职工岗位：" << this->get_DepartmentName() << "\t\t岗位职责：完成经理交代的任务。"
              << std::endl;
}

std::string Employee::get_DepartmentName() { return std::string("员工"); }