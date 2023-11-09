// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:10_4.
// If there are no special instructions, this file is used as an exercise and test file.

#include "10_4.hpp"

void Exercise_10_4::meaninglessFunction_1() {}

void Exercise_10_4::exercise_10_27() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 6, 1, 10, 2};
    std::list<int>   list;

    std::sort(data.begin(), data.end());
    std::unique_copy(data.cbegin(), data.cend(), std::back_inserter(list));
    std::for_each(list.cbegin(), list.cend(), [](int const& c) { std::cout << c << " "; });
}

void Exercise_10_4::exercise_10_28() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>   test_1, test_2, test_3;

    // 1,2,3,4,5,6,7,8,9
    std::copy(data.cbegin(), data.cend(), std::inserter(test_1, test_1.begin()));

    // 1,2,3,4,5,6,7,8,9
    std::copy(data.cbegin(), data.cend(), std::back_inserter(test_2));

    // 9,8,7,6,5,4,3,2,1
    std::copy(data.cbegin(), data.cend(), std::front_inserter(test_3));

    // test_1
    std::cout << "test_1 is:\n";
    std::for_each(test_1.cbegin(), test_1.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
    // test_2
    std::cout << "test_2 is:\n";
    std::for_each(test_2.cbegin(), test_2.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
    // test_3
    std::cout << "test_3 is:\n";
    std::for_each(test_3.cbegin(), test_3.cend(), [](int const& c) { std::cout << c << " "; });
    std::cout << "\n";
}

void Exercise_10_4::exercise_10_29() {
    std::string filename;
    /* The file is located in the bin directory
     * so,you can enter ../assert/test_file/test.txt
     * */
    std::cout << "input file name:";
    std::cin >> filename;
    std::ifstream in(filename);

    if (!in.is_open()) {
        std::cerr << "Can't open file: " << filename << "\n";
        return;
    }

    std::istream_iterator<std::string> in_iter(in), eof;
    std::vector<std::string>           data(in_iter, eof);
    for (auto const& val : data) {
        std::cout << val << " ";
    }
}

void Exercise_10_4::exercise_10_30() {
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int>           data(in_iter, eof);
    std::sort(data.begin(), data.end(), [](const int& a, const int& b) -> int { return a > b; });
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(data.begin(), data.end(), out_iter);
}

void Exercise_10_4::exercise_10_31() {
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int>           data(in_iter, eof);
    std::sort(data.begin(), data.end(), [](const int& a, const int& b) -> int { return a > b; });
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::unique_copy(data.begin(), data.end(), out_iter);
}


void Exercise_10_4::exercise_10_32() {
    /*std::istream_iterator<Sales_item_10> in_iter(std::cin), eof;
    std::vector<Sales_item_10>           trans(in_iter, eof);
    if (trans.empty()) {
        std::cerr << "No data!\n";
        return;
    }
    std::sort(trans.begin(), trans.end(), [](const Sales_item_10& a, const Sales_item_10& b) -> bool {
        return a.isbn() < b.isbn();
    });
    std::ostream_iterator<Sales_item_10> out_iter(std::cout, "\n");
    for (auto begin = trans.begin(), end = begin; begin != trans.end(); begin = end) {
        end
          = std::find_if_not(begin, trans.end(), [begin](const Sales_item_10& a) { return a.isbn() == begin->isbn(); });
        out_iter = std::accumulate(begin, end, Sales_item_10(begin->isbn()));
    }*/
}

void Exercise_10_4::exercise_10_33() {
    std::cout << "input file name:";
    std::string filename;
    std::cin >> filename;
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Can't open file: " << filename << "\n";
        return;
    }
    std::ofstream out_odd("../assert/test_file/odd_number.txt"), out_even("../assert/test_file/even_number.txt");
    std::istream_iterator<int> in_iter(in), eof;
    std::ostream_iterator<int> out_odd_iter(out_odd, " "), out_even_iter(out_even, " ");
    std::for_each(in_iter, eof, [&](int i) { i % 2 ? out_odd_iter = i : out_even_iter = i; });
}

void Exercise_10_4::exercise_10_34() {
    std::vector<int>           data{1, 2, 3, 4, 5, 6, 7, 8};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(data.crbegin(), data.crend(), out_iter);
}

void Exercise_10_4::exercise_10_35() {
    std::vector<int>           data{1, 2, 3, 4, 5, 6, 7, 8};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    for (auto begin = data.end() - 1; begin != data.begin() - 1; --begin)
        *out_iter++ = *begin;
}

void Exercise_10_4::exercise_10_36() {
    std::list<int>             data{0, 1, 2, 0, 3, 4, 5, 6, 7, 0, 8, 0, 10};
    auto                       last_zero = std::find(data.crbegin(), data.crend(), 0);
    std::ostream_iterator<int> out_iter(std::cout, " ");
    int                        index = -1;
    for (auto begin = data.begin(); begin != last_zero.base(); ++begin, ++index)
        *out_iter++ = *begin;
    std::cout << "\nThe index of the last element with a value of 0 is: " << index;
}

void Exercise_10_4::exercise_10_37() {
    std::vector<int>           data_1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::list<int>             data_2(data_1.rbegin() + 3, data_1.rend() - 2);
    std::copy(data_2.cbegin(), data_2.cend(), out_iter);
}
