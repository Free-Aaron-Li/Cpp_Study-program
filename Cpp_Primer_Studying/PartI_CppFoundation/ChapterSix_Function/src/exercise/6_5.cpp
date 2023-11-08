// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:6_5.
// If there are no special instructions, this file is used as an exercise and test file.

#include "6_5.hpp"

void Exercise_6_5::meaninglessFunction_1() {}
void Exercise_6_5::meaninglessFunction_2() {}
void Exercise_6_5::meaninglessFunction_3() {}
void Exercise_6_5::meaninglessFunction_4() {}
void Exercise_6_5::meaninglessFunction_5() {}

inline std::string exercise_42_sub(size_t ctr, const std::string &word, const std::string &ending = "s") {
    return ((ctr > 1) ? word + ending : word);
}
void Exercise_6_5::exercise_6_42() {
    std::cout << exercise_42_sub(2, "success", "es") << "\n";
    std::cout << exercise_42_sub(2, "failure") << "\n";
}

inline bool exercise_44_sub(const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); }

void Exercise_6_5::exercise_6_44() {
    std::string s1 = "hello";
    std::string s2 = "hello !";
    std::cout << exercise_44_sub(s1, s2);
}

void exercise_47_sub(std::vector<int>::const_iterator iterator_begin, std::vector<int>::const_iterator iterator_end) {
    /* 如果没有定义DEBUG，那么将会执行#ifndef和#endif中语句 */
#ifndef NDEBUG
    std::cerr << iterator_end - iterator_begin << " function: " << __func__ << " file: " << __FILE__ << " on "
              << __DATE__ << " at " << __TIME__ << "\n";
#endif
    if (iterator_begin != iterator_end) {
        std::cout << *iterator_begin << " ";
        return exercise_47_sub(++iterator_begin, iterator_end);
    } else {
        std::cout << "\n";
        return;
    }
}

void Exercise_6_5::exercise_6_47() {
    std::vector<int> vector{1, 2, 3, 4, 5};
    exercise_47_sub(vector.begin(), vector.end());
}
