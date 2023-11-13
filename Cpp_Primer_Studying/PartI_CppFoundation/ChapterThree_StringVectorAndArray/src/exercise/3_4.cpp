// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.
*@author AaronLi *@data 2023 - 05 - 30 - 下午7 : 59 * @license GPL
  - 3.0 * /

#include "3_4.hpp"

      void Exercise_3_4::outputVector() {
    std::vector<int>         v1;
    std::vector<int>         v2(10);
    std::vector<int>         v3(10, 42);
    std::vector<int>         v4{10};
    std::vector<int>         v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    for (auto iter = v1.cbegin(); iter != v1.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v2.cbegin(); iter != v2.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v3.cbegin(); iter != v3.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v4.cbegin(); iter != v4.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v5.cbegin(); iter != v5.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v6.cbegin(); iter != v6.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << "\n";

    for (auto iter = v7.cbegin(); iter != v7.cend(); ++iter) {
        std::cout << *iter << "  ";
    }
}

void Exercise_3_4::outputText() {
    std::vector<std::string> text{"this", "", "is", "", "good", "", "time!"};

    std::cout << "the old text is:\n";
    for (const auto &c : text) {
        std::cout << c << " ";
    }

    std::cout << "\nthe new text is:\n";
    for (auto iter = text.begin(); iter != text.end() && !iter->empty(); ++iter) {
        for (auto &c : *iter) {
            c = toupper(c);
        }
    }

    for (auto iter = text.cbegin(); iter != text.cend(); ++iter) {
        std::cout << *iter << " ";
    }
}

void Exercise_3_4::iterateVector() {
    std::vector<int> vector_1(10, 11);
    for (auto iter = vector_1.begin(); iter != vector_1.end(); ++iter) {
        *iter *= *iter;
    }
    for (auto c : vector_1) {
        std::cout << c << " ";
    }
}

void Exercise_3_4::outputVector2() {
    std::vector<int> number_vector;
    int              number;

    std::cout << "请输入一组整数：";
    while (std::cin >> number) {
        number_vector.push_back(number);
        if (std::cin.get() == '\n')
            break;
    }

    std::cout << "输入的整数集合为：";
    for (auto c : number_vector) {
        std::cout << c << " ";
    }

    std::cout << "\n每对相邻整数和的集合为：";
    decltype(number_vector)::iterator iter_end;
    if (number_vector.size() % 2 == 0) {
        iter_end = number_vector.end();
    } else {
        iter_end = number_vector.end() + 1;
    }
    for (auto iter = number_vector.begin(); iter != iter_end; iter += 2) {
        std::cout << *(iter) + *(iter + 1) << " ";
    }

    std::cout << "\n每对对称整数和的集合为：";
    auto iter_2   = number_vector.end() - 1;
    auto mid_iter = number_vector.begin() + (number_vector.size() / 2);
    for (auto iter_1 = number_vector.begin(); iter_1 != mid_iter, iter_2 != mid_iter; iter_1 += 1) {
        std::cout << *(iter_1) + *(iter_2) << " ";
        iter_2 -= 1;
    }
    std::cout << *(mid_iter);
}


void Exercise_3_4::exercise_3_25() {
    std::cout << "请输入分数集合：";
    std::vector<int> score_vector;
    int              score;
    while (std::cin >> score) {
        score_vector.push_back(score);
        if (std::cin.get() == '\n')
            break;
    }

    std::vector<int> fraction_segment(11);
    auto             fraction_iter = fraction_segment.begin();

    for (auto iter = score_vector.begin(); iter != score_vector.end(); iter += 1) {
        int index = *iter / 10;
        *(fraction_iter + index) += 1;
    }

    std::cout << "分数段为：";
    for (auto c : fraction_segment) {
        std::cout << c << " ";
    }
}
