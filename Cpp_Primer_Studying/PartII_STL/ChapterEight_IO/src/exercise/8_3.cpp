// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_3.
// If there are no special instructions, this file is used as an exercise and test file.

#include "8_3.hpp"

void Exercise_8_3::meaninglessFunction_1() {}
void Exercise_8_3::meaninglessFunction_2() {}

std::istream& exercise_9_sub(std::istream& is) {
    std::string str;
    while (is >> str)
        std::cout << str << "\n";
    is.clear();
    return is;
}

void Exercise_8_3::exercise_8_9() {
    std::istringstream is("hello world");
    exercise_9_sub(is);
}

void Exercise_8_3::exercise_8_10() {
    std::string filename;
    std::cout << "please input filename:";
    std::cin >> filename;
    std::string              file(filename);
    std::ifstream            input(file);
    std::vector<std::string> vector;

    if (!input) {
        std::cerr << "couldn't open: " + file;
        return;
    }

    std::string str;
    while (getline(input, str))
        vector.push_back(str);

    std::string world;
    for (const auto& string : vector) {
        std::istringstream is(string);
        while (is >> world)
            std::cout << world << " ";
        std::cout << "\n";
    }
}

struct PersonInfo {
    std::string              name;
    std::vector<std::string> phones;
};

void Exercise_8_3::exercise_8_11() {
    std::string             file("../asset/phone_number.txt");
    std::ifstream           input(file);
    std::string             line, word;
    std::vector<PersonInfo> people;

    if (!input) {
        std::cerr << "couldn't open: " + file;
        return;
    }

    std::istringstream record;
    while (getline(input, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }

    for (const auto& s : people) {
        std::cout << s.name << " \t";
        for (const auto& w : s.phones)
            std::cout << w << "\t";
        std::cout << "\n";
    }
}

bool valid(const std::string& str) {
    if (str.size() != 10)
        return false;
    for (const auto& c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

std::string format(const std::string& str) {
    int         index  = 0;
    std::string result = "86-";
    for (const auto& c : str) {
        ++index;
        result += c;
        if (index == 2)
            result += "-";
    }
    return result;
}

void Exercise_8_3::exercise_8_13() {
    std::string             file("../asset/phone_number.txt");
    std::ifstream           input(file);
    std::vector<PersonInfo> people;
    std::string             line, word;

    if (!input) {
        std::cerr << "couldn't open: " + file;
        return;
    }

    std::istringstream record;
    while (getline(input, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }

    for (const auto& p : people) {
        std::ostringstream formatted, bad_numbers;
        for (const auto& nums : p.phones) {
            if (!valid(nums))
                bad_numbers << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if (bad_numbers.str().empty())
            std::cout << p.name << " \t" << formatted.str() << "\n";
        else
            std::cerr << "input error: " << p.name << " \t"
                      << "invalid number(s)" << bad_numbers.str() << "\n";
    }
}
