// This file is part of Cpp_Primer_Studying project.
// This program is called:8_2.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "8_2.hpp"

#include "sales_data_public.hpp"

void Exercise_8_2::exercise_8_4() {
    std::string              file("../assert/test.txt");
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
    std::string       file("../assert/test.txt");
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

void Exercise_8_2::exercise_8_6() {
    std::string   input_file("../assert/sales.txt");
    std::string   output_file("../assert/output.txt");
    std::ifstream input(input_file);
    std::ofstream output(output_file);

    if (!input) std::cerr << "couldn't open: " + input_file;

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
