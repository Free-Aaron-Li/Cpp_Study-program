/**
 * @file struct.hpp
 * @author AaronLi
 * @date 2023-02-04-下午9:59
 * @description
 */

#ifndef CHAPTERTHREE_STRUCT_HPP
#define CHAPTERTHREE_STRUCT_HPP

#endif  // CHAPTERTHREE_STRUCT_HPP
#include <iostream>
#include <string>

using namespace std;

struct Student {
  string student_name;
  int score{};
};

struct Teacher{
  string teacher_name;
  Student studentArray[5];
};

void allocatorSpace(Teacher teacherArray[],int length);
void print(Teacher teacherArray[],int length);













