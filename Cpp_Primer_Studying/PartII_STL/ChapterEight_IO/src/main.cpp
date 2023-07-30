// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "8_1.hpp"
#include "8_2.hpp"

void test_8_1() {
    /* redirect std::cin,so enter linux command:
     * $ ./Primer_ChapterEight < ../assert/test.txt
     * */
    Exercise_8_1::exercise_8_1();
}

void test_8_2() {
    // Exercise_8_2::exercise_8_4();
    // Exercise_8_2::exercise_8_5();
    Exercise_8_2::exercise_8_6();
}

int main() {
    // test_8_1();
    test_8_2();
    return 0;
}