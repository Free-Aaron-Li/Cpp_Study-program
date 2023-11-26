// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "12_3.hpp"

void
runQueries(std::ifstream &infile) {
    TextQuery textQuery(infile);
    while (true) {
        std::cout << "Enter word to look for, or 'q' to exit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, textQuery.query(s)) << std::endl;
    }
}

void
Exercise_12_3::exercise_12_27() {
    std::cout << "Enter the file name to look up: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(TEST_PATH + filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return;
    }
    runQueries(in);
    return;
}
