// This file is part of Cpp_Primer_Studying project.
// This program is called:9_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "9_2.hpp"

void Exercise_9_2::meaninglessFunction_1() {}
void Exercise_9_2::meaninglessFunction_2() {}
void Exercise_9_2::meaninglessFunction_3() {}
void Exercise_9_2::meaninglessFunction_4() {}

void Exercise_9_2::exercise_9_2() { std::list<std::deque<int>> list; }

bool exercise_4_sub(std::vector<int>& vector, int target) {
    auto begin = vector.begin();
    auto end   = vector.cend();
    while (begin != end) {
        if (*begin == target)
            return true;
        else
            ++begin;
    }
    return false;
}

void Exercise_9_2::exercise_9_4() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << exercise_4_sub(vector, 9);
}

int exercise_5_sub(std::vector<int>& vector, int target) {
    auto begin = vector.begin();
    auto end   = vector.cend();
    while (begin != end) {
        if (*begin == target)
            return *begin;
        else
            ++begin;
    }
    return -1;
}

void Exercise_9_2::exercise_9_5() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int              result = exercise_5_sub(vector, 1);
    if (result == -1)
        std::cout << "no number in this vector!";
    else
        std::cout << result;
}

void Exercise_9_2::exercise_9_7() {
    std::vector<int>           vector{1, 2, 3, 4, 5};
    std::vector<int>::iterator i;
    for (i = vector.begin(); i != vector.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    std::cout << typeid(i).name() << "\n";
}

void Exercise_9_2::exercise_9_11() {
    std::vector<int> v1; /* v1 is empty */
    std::vector<int> v2(v1); /* v2 is empty */
    std::vector<int> v3=v1; /* v3 is empty */
    std::vector<int> v4{1,2,3}; /* v4 has three elements,they are 1,2,3 */
    std::vector<int> v5(3,2); /* v5 has three elements,they are 3,3,3 */
    std::vector<int> v6(v5.cbegin(),v5.cend()); /* v6 has three elements,they are 3,3,3 */
}
