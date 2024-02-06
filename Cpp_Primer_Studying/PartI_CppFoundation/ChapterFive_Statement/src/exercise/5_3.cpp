// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:5_3.
// If there are no special instructions, this file is used as an exercise and
// test file.

#include "5_3.hpp"

void Exercise_5_3::meaninglessFunction_1() {}
void Exercise_5_3::meaninglessFunction_2() {}
void Exercise_5_3::meaninglessFunction_3() {}

void Exercise_5_3::exercise_5_5() {
  /**
   * 规定：<br>
   * 成绩实行百分制，小于60分成绩为F，每10分为一档，90~100为A，80~90位B，70~80位C，60~70位D。<br>
   * 100分为A++，分数的余数为7~9为优，加上“+”；分数的余数为1~3为差，加上“-”。
   */
  std::cout << "请输入一个分数（100以内的正整数）：";
  unsigned int achievement; /* 定义成绩 */
  std::string result;       /* 成绩等级 */
  std::vector<std::string> grades{"F", "D", "C",
                                  "B", "A", "A++"}; /* 定义等级 */
  auto iter = grades.begin();                       /* 定义迭代器 */
Start:
  std::cin >> achievement;

  if (achievement > 100) {
    std::cout << "你输入的成绩有误！请重新输入：";
    goto Start;
  } else if (achievement == 100)
    result = *(iter + 5);
  else if (achievement < 60)
    result = *iter;
  else {
    decltype(achievement) number = (achievement - 50) / 10;
    if (achievement % 10 >= 7)
      result = *(iter + number) + "+";
    else if (achievement % 10 <= 3)
      result = *(iter + number) + "-";
    else
      result = *(iter + number);
  }

  std::cout << "你的成绩等级为：" << result << "\n";
}

void Exercise_5_3::exercise_5_6() {
  std::cout << "请输入一个分数（100以内的正整数）：";
  unsigned int achievement; /* 定义成绩 */
  std::string result;       /* 成绩等级 */
  std::vector<std::string> grades{"F", "D", "C",
                                  "B", "A", "A++"}; /* 定义等级 */
  auto iter = grades.begin();                       /* 定义迭代器 */
Start:
  std::cin >> achievement;

  if (achievement > 100) {
    std::cout << "你输入的成绩有误！请重新输入：";
    goto Start;
  }

  decltype(achievement) number = (achievement - 50) / 10;
  (achievement >= 100)
      ? (result = *(iter + 5))
      : ((achievement > 60) ? (result = *(iter + number)) : (result = *iter));

  (achievement >= 60)
      ? ((achievement % 10 >= 7)
             ? (result += "+")
             : ((achievement % 10 <= 3) ? (result += "-") : result))
      : result;
  std::cout << "你的成绩等级为：" << result << "\n";
}

void Exercise_5_3::exercise_5_9() {
  std::string line;
  int sum = 0;
  std::cout << "请输入一串字母：";
  getline(std::cin, line);

  for (auto character : line) {
    switch (character) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      sum++;
      break;
    default:
      break;
    }
  }
  std::cout << "输入的元音字母有" << sum << "个\n";
}

void Exercise_5_3::exercise_5_10() {
  std::string line;
  int sum = 0;
  std::cout << "请输入一串字母：";
  getline(std::cin, line);

  for (auto character : line) {
    switch (character) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      sum++;
      break;
    default:
      break;
    }
  }
  std::cout << "输入的元音字母有" << sum << "个\n";
}

void Exercise_5_3::exercise_5_11() {
  int sum = 0;
  char character;
  std::cout << "请输入一串字母：";
  /* 操作符noskipws会令输入运算符读取空白符，而不是跳过它们。为了恢复默认行为，可以使用skipws操作符。*/
  while (std::cin >> std::noskipws >> character) {
    switch (character) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case '\t':
    case ' ':
    case '\n':
      sum++;
      break;
    default:
      break;
    }
  }
  std::cout << "\n输入的元音字母有" << sum << "个\n";
}

void Exercise_5_3::exercise_5_12() {
  std::string line;
  char element;
  auto iter_begin = line.begin();
  int sum = 1;
  std::cout << "请输入一段字符串：";
  getline(std::cin, line);
  while (iter_begin != line.end()) {
    switch (*iter_begin) {
    case 'f': {
      switch (*(iter_begin + 1)) {
      case 'f':
      case 'l':
      case 'i':
        sum++;
        break;
      default:;
        break;
      }
    }
    default:;
      break;
    }
    iter_begin += 2;
  }
  std::cout << "\n输入的包含ff、fl和fi的个数有" << sum << "个\n";
}
