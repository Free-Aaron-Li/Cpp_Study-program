// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:9_4.
// If there are no special instructions, this file is used as an exercise and test file.

#include "9_4.hpp"

void Exercise_9_4::meaninglessFunction_1() {}
void Exercise_9_4::meaninglessFunction_2() {}
void Exercise_9_4::meaninglessFunction_3() {}
void Exercise_9_4::meaninglessFunction_4() {}
void Exercise_9_4::meaninglessFunction_5() {}

void Exercise_9_4::exercise_9_38() {
    std::vector<int> vector; /* start phase */

    std::cout << "first,size:" << vector.size() << ", capacity:" << vector.capacity() << "\n";

    for (std::vector<int>::size_type i = 0; i < 10; ++i) { /* Initialization phase */
        vector.push_back(0);
    }
    std::cout << "first,size:" << vector.size() << ", capacity:" << vector.capacity() << "\n";

    while (vector.size()!=vector.capacity())
        vector.push_back(0);
    vector.push_back(0); /* Current space overflow phase */
    std::cout << "first,size:" << vector.size() << ", capacity:" << vector.capacity() << "\n";
}
