/**
 * @file struct.cpp
 * @author AaronLi
 * @date 2023-02-04-下午10:09
 * @description
 */
#include "struct.hpp"

#include <random>

void allocatorSpace( Teacher teacherArray[], int length ) {
    static random_device                   seed;              /* 硬件生成随机数种子 */
    static ranlux48                        engine( seed() );  /* 利用种子生成随机数引擎 */
    static uniform_int_distribution< int > distrib( 1, 100 ); /* 设置随机数范围，并设为正态分布 */

    string teacherName = "老师_";
    string studentName = "学生_";
    string number      = "ABCDEFGHIGK";

    for ( int i = 0; i < length; ++i ) {
        teacherArray[ i ].teacher_name = teacherName + number[ i ];
        for ( int j = 0; j < 5; ++j ) {
            teacherArray[ i ].studentArray[ j ].student_name = studentName + to_string( j );
            teacherArray[ i ].studentArray[ j ].score        = distrib( engine );
        }
    }
}

void print( Teacher teacherArray[], int length ) {
    for ( int i = 0; i < length; ++i ) {
        cout << "老师姓名：" << teacherArray[ i ].teacher_name << endl;
        for ( auto& j : teacherArray[ i ].studentArray ) {
            cout << "学生姓名：" << j.student_name << " ,学生成绩：" << j.score << endl;
        }
    }
}
