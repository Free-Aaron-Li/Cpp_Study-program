// This file is part of Cpp_Primer_Studying project.
// This program is called:main.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "8_1.hpp"
#include "8_2.hpp"
#include "8_3.hpp"

void test_8_1() {
    /* redirect std::cin,so enter linux command:
     * $ ./Primer_ChapterEight < ../asset/test.txt
     * */
    Exercise_8_1::exercise_8_1();
}

void test_8_2(const std::string& str_1, const std::string& str_2) {
    // Exercise_8_2::exercise_8_4();
    // Exercise_8_2::exercise_8_5();
    // Exercise_8_2::exercise_8_6(str_1);
    // Exercise_8_2::exercise_8_7(str_1, str_2);
    Exercise_8_2::exercise_8_8(str_1, str_2);
}

void test_8_3() {
    // Exercise_8_3::exercise_8_9();
    // Exercise_8_3::exercise_8_10();
    // Exercise_8_3::exercise_8_11();
    Exercise_8_3::exercise_8_13();
}

/* if you use CLion and want the main program is capable of handling command-line options
 * you could:
 * Run -> Edit Configuration -> Program arguments
 * for example:
 * my program arguments is : ../asset/sales.txt ../asset/output.txt
 * */
int main(int argc, char* argv[]) {
    // test_8_1();
    // test_8_2(argv[1], argv[2]);
    test_8_3();
    return 0;
}