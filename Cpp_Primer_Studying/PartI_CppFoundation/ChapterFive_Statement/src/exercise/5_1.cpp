// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:5_1.
// If there are no special instructions, this file is used as an exercise and
// test file.

#include "5_1.hpp"

void Exercise_5_1::meaninglessFunction_1() {}
void Exercise_5_1::meaninglessFunction_2() {}

void Exercise_5_1::exercise_5_3() {
  int sum = 0, val = 0;
  while (val++, val <= 10)
    sum += val;
  std::cout << "Sum of 1 to 10 inclusive is " << sum << "'\n";
}
