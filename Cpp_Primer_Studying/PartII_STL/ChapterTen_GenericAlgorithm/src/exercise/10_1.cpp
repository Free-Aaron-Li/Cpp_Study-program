// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:10_1.
// If there are no special instructions, this file is used as an exercise and test file.

#include "10_1.hpp"

void Exercise_10_1::exercise_10_1() {
    std::cout << "enter the vector numbers:\n";
    int              value;
    std::vector<int> vector;
    while (std::cin >> value) {
        vector.push_back(value);
        if (std::cin.get() == '\n')
            break;
    }
    std::cout << "enter the number for you want find:";
    std::cin >> value;
    auto result = std::count(vector.cbegin(), vector.cend(), value);
    std::cout << "There are " << result << " entries in this vector that are equal to " << value << "\n";
}

void Exercise_10_1::exercise_10_2() {
    std::cout << "enter the list numbers:\n";
    std::string            value;
    std::list<std::string> list;
    while (std::cin >> value) {
        list.push_back(value);
        if (std::cin.get() == '\n')
            break;
    }
    std::cout << "enter the string for you want find:";
    std::cin >> value;
    auto result = std::count(list.cbegin(), list.cend(), value);
    std::cout << "There are " << result << " entries in this vector that are equal to " << value << "\n";
}
