// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "13_2.hpp"

void
Exercise_13_2::meaninglessFunction_1() {}
void
Exercise_13_2::meaninglessFunction_2() {}

void
Exercise_13_2::exercise_13_22() {
    Has_Ptr v1;
    Has_Ptr v2("hello");
    std::cout << "v2, str: \"" << v2.get_str() << "\" int: " << v2.get_int() << "\n";
    v1 = v2;
    std::cout << "v1, str: \"" << v1.get_str() << "\" int: " << v1.get_int() << "\n";
    v2.set("hello world", 1);
    std::cout << "v2, str: \"" << v1.get_str() << "\" int: " << v1.get_int() << "\n";  // one value
    std::cout << "v1, str: \"" << v2.get_str() << "\" int: " << v2.get_int() << "\n";  // two value
}
