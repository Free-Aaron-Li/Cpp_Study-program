// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'main'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_1.hpp"
#include "11_2.hpp"

#define TEST_PATH "../asset/test/"
std::vector<std::string> file() {
    std::string filename;
    std::cout << "Please enter filename: ";
    std::cin >> filename;
    std::ifstream in(TEST_PATH + filename);
    if (!in.is_open())
        std::cerr << "Can't open file: " << filename << "\n";
    std::istream_iterator<std::string> in_iter(in), eof;
    std::vector<std::string>           data{in_iter, eof};
    return data;
}

void test_11_1() {
    // Exercise_11_1::exercise_11_3(file());  // hello.txt
    // Exercise_11_1::exercise_11_4(file());  // hello.txt
}

void test_11_2() {
    // Exercise_11_2::exercise_11_7(file());  // names.txt
    // Exercise_11_2::exercise_11_8(file());  // hello.txt
    // Exercise_11_2::exercise_11_9();
    // Exercise_11_2::exercise_11_12();
    Exercise_11_2::exercise_11_14(file());  // names_plus.txt
}

int main() {
    // test_11_1();
    test_11_2();
    return 0;
}