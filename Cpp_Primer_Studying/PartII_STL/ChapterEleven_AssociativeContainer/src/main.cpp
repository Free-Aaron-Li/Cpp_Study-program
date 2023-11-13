// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'main'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_1.hpp"

void test_11_1() {
    std::string filename;
    std::cout << "Please enter filename: ";
    // you can enter : ../asset/test/hello.txt
    std::cin >> filename;
    std::ifstream in(filename);
    if (!in.is_open())
        std::cerr << "Can't open file: " << filename << "\n";
    std::istream_iterator<std::string> in_iter(in), eof;
    std::vector<std::string>           words{in_iter, eof};

    // Exercise_11::exercise_11_3(words);
    Exercise_11::exercise_11_4(words);
};

int main() {
    test_11_1();
    return 0;
}