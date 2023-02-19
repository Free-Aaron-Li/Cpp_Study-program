/**
 * @author AaronLi
 * @date 2023-02-16-下午10:17
 * @license GPL-3.0
 */
#include "manager.hpp"

#include <utility>

Manager::Manager(int id, std::string name, int dept_id) {
    this->worker_id_            = id;
    this->worker_name_          = std::move(name);
    this->worker_department_id_ = dept_id;
}

void Manager::ShowInfo() {
    std::cout << "职工编号：" << this->worker_id_ << "\t职工姓名：" << this->worker_name_
              << "\t\t职工岗位：" << this->get_DepartmentName()
              << "\t\t岗位职责：完成老板交给的任务，并下发任务给员工。" << std::endl;
}

std::string Manager::get_DepartmentName() { return std::string("经理"); }