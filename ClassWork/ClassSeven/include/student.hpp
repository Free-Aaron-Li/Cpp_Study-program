/**
 * @author AaronLi
 * @data 2023-05-29-下午1:14
 * @license GPL-3.0
 */

#ifndef CLASSWORK_STUDENT_HPP
#define CLASSWORK_STUDENT_HPP

/**
 * @title
 * 学生信息表
 */

#include <iostream>
#include <string>
#include <cmath>

struct Students {
    char student_number[12];        /* 学号 */
    char student_name[20];          /* 姓名 */
    double score_chinese;               /* 语文成绩 */
    double score_math;                  /* 数学成绩 */
    double score_english;               /* 英语成绩 */
    double total_scores;                /* 总分 */
};

class Student {
public:
    /**
     * 学生信息存入
     */
    static void
    getInformation(Students &students, const char student_number[12], const char student_name[20], double score_chinese,
                   double score_math, double score_english);

    /**
     * 成绩进位
     */
    static double scoreCarry(double score);

    /**
     * 打印学生信息
     */
    static void printInformation(Students &students, int tab_number = 3);

};

#endif //CLASSWORK_STUDENT_HPP
