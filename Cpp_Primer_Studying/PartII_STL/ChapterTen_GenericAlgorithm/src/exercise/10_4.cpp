// This file is part of Cpp_Primer_Studying project.
// This program is called:10_4.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "10_4.hpp"

void Exercise_10_4::meaninglessFunction_1() {}

void Exercise_10_4::exercise_10_27() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 6, 1, 10, 2};
    std::list<int>   list;

    std::sort(data.begin(), data.end());
    std::unique_copy(data.cbegin(), data.cend(), std::back_inserter(list));
    std::for_each(list.cbegin(), list.cend(), [](int const& c) { std::cout << c << " "; });
}

void Exercise_10_4::exercise_10_28() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>   test_1, test_2, test_3;

    // 1,2,3,4,5,6,7,8,9
    std::copy(data.cbegin(), data.cend(), std::inserter(test_1, test_1.begin()));

    // 1,2,3,4,5,6,7,8,9
    std::copy(data.cbegin(), data.cend(), std::back_inserter(test_2));

    // 9,8,7,6,5,4,3,2,1
    std::copy(data.cbegin(), data.cend(), std::front_inserter(test_3));

    // test_1
    std::cout << "test_1 is:\n";
    std::for_each(test_1.cbegin(), test_1.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
    // test_2
    std::cout << "test_2 is:\n";
    std::for_each(test_2.cbegin(), test_2.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
    // test_3
    std::cout << "test_3 is:\n";
    std::for_each(test_3.cbegin(), test_3.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
}
