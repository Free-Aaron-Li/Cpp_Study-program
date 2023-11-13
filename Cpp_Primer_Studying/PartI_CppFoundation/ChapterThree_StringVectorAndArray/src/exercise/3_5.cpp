// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.
*@author AaronLi *@data 2023 - 06 - 02 - 下午2 : 10 * @license GPL
  - 3.0 * /

#include "3_5.hpp"

#include <cstring>

      void Exercise_3_5::meaninglessFunction_1() {
}

void Exercise_3_5::meaninglessFunction_2() {}

void Exercise_3_5::meaninglessFunction_3() {}

void Exercise_3_5::meaninglessFunction_4() {}

void Exercise_3_5::meaninglessFunction_5() {}

void Exercise_3_5::meaninglessFunction_6() {}

void Exercise_3_5::meaninglessFunction_7() {}

void Exercise_3_5::meaninglessFunction_8() {}

void Exercise_3_5::exercise_3_31() {
    int array[10] = {};
    int i         = 0;
    for (auto &c : array) {
        c = i++;
    }
    for (auto c : array) {
        std::cout << c << " ";
    }
}

void Exercise_3_5::exercise_3_32() {
    int array[10] = {};
    int i         = 0;
    for (auto &c : array) {
        c = i++;
    }

    int array_1[i];
    for (int j = 0; j < i; ++j) {
        array_1[j] = array[j];
    }

    std::cout << "vector重写后：\n";

    std::vector<int> vector_1(i);
    std::vector<int> vector_2;

    i = 0;
    for (auto &c : vector_1) {
        c = i++;
    }
    vector_2.reserve(vector_1.size());
    for (auto j : vector_1) {
        vector_2.push_back(j);
    }
    for (int j = 0; j < vector_2.size(); ++j) {
        std::cout << vector_2[j] << " ";
    }
}

void Exercise_3_5::exercise_3_35() {
    std::cout << "数组原本内容为：";
    int array[] = {1, 2, 3, 4, 5};
    for (auto c : array) {
        std::cout << c << " ";
    }

    for (auto i = array; i != std::end(array); ++i) {
        *i = 0;
    }

    std::cout << "\n数组元素被置为0后：";
    for (auto c : array) {
        std::cout << c << " ";
    }
}

void Exercise_3_5::exercise_3_36() {
    int array_1[] = {1, 2, 3, 4, 5};
    int array_2[] = {1, 2, 3, 4, 6};

    auto iter_2 = std::begin(array_2);
    int  flag   = 0;
    if ((std::end(array_1) - std::begin(array_1) != (std::end(array_2) - std::begin(array_2)))) {
        std::cout << "二者数组不相同";
        flag = -1;
    } else {
        for (auto iter = std::begin(array_1); iter != std::end(array_1); ++iter) {
            if (*iter != *iter_2)
                flag = 1;
            ++iter_2;
        }
    }
    if (flag == 0)
        std::cout << "二者数组相同";
    else if (flag == 1)
        std::cout << "二者数组不相同";

    std::cout << "\nvector实现：\n";

    std::vector<int> vector_1{1, 2, 3, 4, 5};
    std::vector<int> vector_2{1, 2, 3, 4, 6};

    auto iter_3 = vector_2.begin();
    flag        = 0;
    if (vector_1.size() != vector_2.size()) {
        std::cout << "二者vector不相同";
        flag = -1;
    } else {
        for (int &iter : vector_1) {
            if (iter != *iter_3)
                flag = 1;
            ++iter_3;
        }
    }
    if (flag == 0)
        std::cout << "二者数组相同";
    else if (flag == 1)
        std::cout << "二者数组不相同";
}

void Exercise_3_5::exercise_3_39() {
    std::string str_1 = "this is good time!";
    std::string str_2 = "this is good time!";

    if (str_1 == str_2)
        std::cout << "两个字符串相同！";
    else
        std::cout << "两个字符串不相同！";

    std::cout << "\n使用C风格字符串：\n";

    const char str_3[] = "this is good time!";
    const char str_4[] = "this is good time!";

    if (strcmp(str_3, str_4) == 0)
        std::cout << "两个字符串相同";
    else
        std::cout << "两个字符串不相同";
}

void Exercise_3_5::exercise_3_40() {
    const char str_1[] = "this is";
    const char str_2[] = " good time!";
    char       str_3[strlen(str_1) + strlen(str_2) + 1];
    strcpy(str_3, str_1);
    strcat(str_3, str_2);
    for (auto c : str_3) {
        std::cout << c;
    }
}

void Exercise_3_5::exercise_3_41() {
    int              array[] = {1, 2, 3};
    std::vector<int> vector(std::begin(array), std::end(array));
    for (auto c : vector) {
        std::cout << c << " ";
    }
}

void Exercise_3_5::exercise_3_42() {
    std::vector<int> vector{1, 2, 3};
    int              array[vector.size()];
    int              i = 0;
    for (auto c : vector) {
        array[i++] = c;
    }
    for (auto c : vector) {
        std::cout << c << " ";
    }
}
