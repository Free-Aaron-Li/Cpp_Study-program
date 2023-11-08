// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:8_2.
// If there are no special instructions, this file is used as an exercise and test file.

#include "8_2.hpp"

#include "sales_data_public.hpp"

void Exercise_8_2::exercise_8_4() {
    std::string filename;
    std::cout << "please input filename:";
    std::cin >> filename;
    std::string              file(filename);
    std::ifstream            input(file);
    std::vector<std::string> vector;
    std::string              data;

    if (input) {
        while (getline(input, data)) {
            vector.push_back(data);
        }
    } else
        std::cerr << "couldn't open: " + file;

    for (const auto &str : vector) {
        std::cout << str << "\n";
    }
}

void Exercise_8_2::exercise_8_5() {
    std::string       file("../asset/test.txt");
    std::ifstream     input(file);
    std::vector<char> vector;
    char              data;

    if (input) {
        while (input >> data) {
            vector.push_back(data);
        }
    } else
        std::cerr << "couldn't open: " + file;

    for (const auto &str : vector) {
        std::cout << str << "\n";
    }
}

void Exercise_8_2::exercise_8_6(const std::string &str) {
    std::ifstream input(str);

    if (!input)
        std::cerr << "couldn't open: " + str;

    SalesData total(input);
    if (total.isbn().empty()) {
        std::cerr << "no data!\n";
    } else {
        SalesData trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total);
                std::cout << "\n";
                total = trans;
            }
        }
        print(std::cout, total);
        std::cout << "\n";
    }
}
void Exercise_8_2::exercise_8_7(const std::string &str_1, const std::string &str_2) {
    std::ifstream input(str_1);
    std::ofstream output(str_2);

    if (!input)
        std::cerr << "couldn't open: " + str_1;

    SalesData total(input);
    if (total.isbn().empty()) {
        std::cerr << "no data!\n";
    } else {
        SalesData trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total);
                output << "\n";
                total = trans;
            }
        }
        print(output, total);
        output << "\n";
    }
}
void Exercise_8_2::exercise_8_8(const std::string &str_1, const std::string &str_2) {
    std::ifstream input(str_1);
    std::ofstream output(str_2, std::ofstream::app);

    if (!input)
        std::cerr << "couldn't open: " + str_1;

    SalesData total(input);
    if (total.isbn().empty()) {
        std::cerr << "no data!\n";
    } else {
        SalesData trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total);
                output << "\n";
                total = trans;
            }
        }
        print(output, total);
        output << "\n";
    }
}
