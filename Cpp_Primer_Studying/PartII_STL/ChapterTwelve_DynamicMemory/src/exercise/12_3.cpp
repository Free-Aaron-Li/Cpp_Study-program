// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "12_3.hpp"

void
Exercise_12_3::meaninglessFunction_1() {}
void
Exercise_12_3::meaninglessFunction_2() {}
void
Exercise_12_3::meaninglessFunction_3() {}
void
Exercise_12_3::meaninglessFunction_4() {}

void
runQueries(std::ifstream& infile) {
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
}

//------------------------------------------------------------------------------------------------
//
typedef std::vector<std::string>::size_type size_type;

std::string
make_plural_v2(std::vector<std::string>::size_type num, const std::string& str, const std::string& postfix = "s") {
    return num > 1 ? str + postfix : str;
}

void
init_text(std::ifstream& infile, std::vector<std::string>& text, std::map<std::string, std::set<size_type>>& lines) {
    size_type   ln_num = 0;
    std::string line, word;
    for (; std::getline(infile, line); text.push_back(line), ++ln_num) {
        std::istringstream iss(line);
        for (; iss >> word; lines[word].insert(ln_num)) {}
    }
}

void
runQueries_v2(std::ifstream& infile) {
    std::vector<std::string>                   text;
    std::map<std::string, std::set<size_type>> lines;

    init_text(infile, text, lines);
    while (true) {
        std::cout << "Enter word to look for, or 'q' to exit: ";
        std::string target_word;
        if (!(std::cin >> target_word) || target_word == "q")
            break;
        auto iter = lines.find(target_word);
        if (iter == lines.end()) {
            std::cerr << "Cannot find word: " << target_word << "\n";
            continue;
        }
        size_type   total = 0;
        std::string word;
        for (const auto& val : iter->second) {
            std::istringstream iss(text[val]);
            for (; iss >> word;)
                if (word == target_word)
                    ++total;
        }
        std::cout << "\"" << target_word << "\" occurs " << total << " " << make_plural_v2(total, "time") << ":\n";
        for (const auto& val : iter->second)
            std::cout << "(line " << val + 1 << ")" << text[val] << "\n";
        std::cout << "\n";
    }
}

void
Exercise_12_3::exercise_12_28() {
    std::cout << "Enter the file name to look up: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(TEST_PATH + filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return;
    }
    runQueries_v2(in);
}
//
//------------------------------------------------------------------------------------------------

void
runQueries_v3(std::ifstream& infile) {
    TextQuery textQuery(infile);
    do {
        std::cout << "Enter word to look for, or 'q' to exit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, textQuery.query(s)) << std::endl;
    } while (true);
}
void
Exercise_12_3::exercise_12_29() {
    std::cout << "Enter the file name to look up: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(TEST_PATH + filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return;
    }
    runQueries_v3(in);
}
