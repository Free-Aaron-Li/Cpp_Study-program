/**
 * @author AaronLi
 * @date 2023-02-16-下午10:24
 * @license GPL-3.0
 */
#include "boss.hpp"

#include <utility>

Boss::Boss(int id, std::string name, int dept_id) {
    this->worker_id_            = id;
    this->worker_name_          = std::move(name);
    this->worker_department_id_ = dept_id;
}

void Boss::ShowInfo() {
    std::cout << "职工编号：" << this->worker_id_ << "\t职工姓名：" << this->worker_name_
              << "\t\t职工岗位：" << this->get_DepartmentName() << "\t\t岗位职责：管理公司所有事务。"
              << std::endl;
}

std::string Boss::get_DepartmentName() { return std::string("总裁"); }