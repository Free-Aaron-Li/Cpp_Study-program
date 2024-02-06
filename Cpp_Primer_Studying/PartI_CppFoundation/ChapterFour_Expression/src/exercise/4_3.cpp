// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "4_3.hpp"

void Exercise_4_3::meaninglessFunction_1() {}
void Exercise_4_3::meaninglessFunction_2() {}

void Exercise_4_3::exercise_4_9() {
  const char *cp = "Hello World";
  if (cp && *cp) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
}

void Exercise_4_3::exercise_4_10() {
  std::cout << "请输入整数：";
  int number;
  while (std::cin >> number && number != 42) {
    std::cout << number << " ";
  }
}
void Exercise_4_3::exercise_4_12() {
  std::cout << "请输入三个整数：";
  int i, j, k;
  std::cin >> i >> j >> k;
  if (i != j < k)
    std::cout << "true";
  else
    std::cout << "false";
}
