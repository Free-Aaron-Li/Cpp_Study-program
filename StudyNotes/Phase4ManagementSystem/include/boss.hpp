//
// Created by AaronLi on 23-2-16.
//

#ifndef PHASE4_BOSS_HPP
#define PHASE4_BOSS_HPP

#pragma once
#include "worker.h"

/* 总裁类，继承于职工抽象类*/
class Boss : public Worker {
 public:
    /**
     * @param
     * int id   : the id of the boss <br>
     * string name : the name of the boss <br>
     * int dept_id : the department id of the boss <br>
     * @return
     * @description
     * 构造函数
     */
    Boss(int id, std::string name, int dept_id);

    /* 显示个人信息 */
    void ShowInfo() override ;

    /* 获取职工岗位信息 */
    std::string get_DepartmentName() override ;
};

#endif  // PHASE4_BOSS_HPP
