// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'10_6'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "10_6.hpp"

void Exercise_10_6::exercise_10_42() {
    std::list<std::string> data{"!", "nice", "nice", "well"};
    data.sort([](const std::string& a, const std::string& b) -> bool { a.size() > b.size(); });
    data.unique();
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::copy(data.cbegin(), data.cend(), out_iter);
}
