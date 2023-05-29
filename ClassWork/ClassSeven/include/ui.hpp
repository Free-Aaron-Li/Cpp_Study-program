/**
 * @author AaronLi
 * @data 2023-05-29-下午3:32
 * @license GPL-3.0
 */
#ifndef CLASSWORK_UI_HPP
#define CLASSWORK_UI_HPP

/**
 * @title
 * UI设计
 */

#include <regex>
#include "student.hpp"

class UI {
public:
    int flag = 0;
public:
    /**
     * 首页面
     */
    static void homePage();

    /**
     * 选择项——数字
     */
    static int selectNumber();

    /**
     * 选择项——字符
     */
    static int selectChar();

    /**
     * 信息展示
     */
    static void print(int tab_number);

    /**
     * 打印列表界面
     */
    void printList(Students *students, int tab_number = 3) const;

    /**
     * 成绩输入
     */
    int inputInformation(Students *students);

    /**
     * 总成绩降序排序
     */
    int *totalScores_descendingOrder(Students *students);

    /**
     * 降序排序界面
     */
    void sortShow(Students *students, int tab_number = 3);

    /**
     * 查找学号
     */
    int searchStudentNumber(Students *students, const std::string &target_number) const;

    /**
     * 查找姓名
     */
    int searchStudentName(Students *students, const std::string &target_name) const;

    /**
     * 查找界面
     */
    void searchShow(Students *students, int tab_number = 3) const;

    /**
     * 界面逻辑
     */
    void InterfaceLogic(Students *students,int tab_number = 3);
};


#endif //CLASSWORK_UI_HPP
