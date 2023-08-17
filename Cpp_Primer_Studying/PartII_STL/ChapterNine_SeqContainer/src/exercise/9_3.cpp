// This file is part of Cpp_Primer_Studying project.
// This program is called:9_3.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include "9_3.hpp"

void Exercise_9_3::meaninglessFunction_1() {}
void Exercise_9_3::meaninglessFunction_2() {}

void Exercise_9_3::exercise_9_18() {
    std::deque<std::string> deque;
    std::string             str;
    auto                    iter_begin = deque.begin();
    while (std::cin >> str) {
        deque.emplace_back(str);
        if (std::cin.get() == '\n') break;
    }
    for (auto const& c : deque) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_19() {
    std::list<std::string> list;
    std::string            str;
    auto                   iter_begin = list.begin();
    while (std::cin >> str) {
        list.emplace_back(str);
        if (std::cin.get() == '\n') break;
    }
    for (auto const& c : list) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_20() {
    std::list<int>  list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> deque_even;
    std::deque<int> deque_odd;

    for (auto const& c : list) {
        if (c % 2 == 0)
            deque_even.emplace_back(c);
        else
            deque_odd.emplace_back(c);
    }
    std::cout << "the even number is :\n";
    for (auto const& c : deque_even) {
        std::cout << c << " ";
    }

    std::cout << "\nthe odd number is :\n";
    for (auto const& c : deque_odd) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_21() {
    std::vector<std::string> vector;
    std::string              str;
    auto                     iter = vector.begin();

    while (std::cin >> str) {
        iter = vector.emplace(iter, str);
        if (std::cin.get() == '\n') break;
    }

    for (auto const& c : vector) {
        std::cout << c << " ";
    }
}

void exercise_22_sub(std::vector<int>& iv, int some_val) {
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;

    while (iter != mid) {
        if (*(++iter) == some_val) iv.insert(iter, 2 * some_val);
    }
}


void Exercise_9_3::exercise_9_22() {
    std::vector<int> iv{1, 2, 3, 4, 5, 6, 7};
    exercise_22_sub(iv, 2);
    for (auto const& c : iv) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_23() {
    std::vector<int> vector{1};
    std::cout << vector.size() << "\n";
    if (!vector.empty()) {
        auto val = *vector.begin(), val2 = vector.front();
        auto last = vector.end();
        auto val3 = *(--last);
        auto val4 = vector.back();
        std::cout << "val is: " << val << "\n"
                  << "val2 is: " << val2 << "\n"
                  << "val3 is: " << val3 << "\n"
                  << "val4 is: " << val4 << "\n";
    }
}

void Exercise_9_3::exercise_9_24() {
    std::vector<int> vector{};

    std::cout << vector.at(0) << "\n";    /* the exception is out_of_range */
    std::cout << vector[0] << "\n";       /* error number is :139 (interrupted by signal 11: SIGSEGV) */
    std::cout << vector.front() << "\n";  /* error number is :139 (interrupted by signal 11: SIGSEGV) */
    std::cout << *vector.begin() << "\n"; /* error number is :139 (interrupted by signal 11: SIGSEGV) */
}

void Exercise_9_3::exercise_9_25() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto elem1 = vector.begin();
    auto elem2 = vector.begin();

    elem1 = vector.erase(elem1, elem2);
    std::cout << *elem1 << "\n";
    for (auto const& c : vector) {
        std::cout << c << " ";
    }

    elem1 = vector.end();
    elem2 = vector.end();
    elem1 = vector.erase(elem1, elem2);
    std::cout << "\n" << *elem1 << "\n";
    for (auto const& c : vector) {
        std::cout << c << " ";
    }

    elem1 = vector.begin();
    elem2 = vector.end();
    elem1 = vector.erase(elem1, elem2);
    std::cout << "\n" << *elem1 << "\n";
    for (auto const& c : vector) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_26() {
    int              ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> vector;
    std::list<int>   list;

    for (auto const& c : ia) {
        vector.emplace_back(c);
        list.emplace_back(c);
    }

    auto iter_vector_begin = vector.begin();
    auto iter_list_begin   = list.begin();

    /* delete even number */
    while (iter_vector_begin != vector.end())
        if (!(*iter_vector_begin % 2))
            iter_vector_begin = vector.erase(iter_vector_begin);
        else
            ++iter_vector_begin;

    /* delete odd number */
    while (iter_list_begin != list.end())
        if (*iter_list_begin % 2)
            iter_list_begin = list.erase(iter_list_begin);
        else
            ++iter_list_begin;

    std::cout << "the vector is:(no even number)\n";
    for (auto const& c : vector) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    std::cout << "the list is:(no odd number)\n";
    for (auto const& c : list) {
        std::cout << c << " ";
    }
}

void Exercise_9_3::exercise_9_27() {
    std::forward_list<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto                   previous_node = list.before_begin();
    auto                   current_node  = list.begin();

    while (current_node != list.end())
        if (*current_node % 2)
            current_node = list.erase_after(previous_node);
        else {
            previous_node = current_node;
            ++current_node;
        }
    for (auto const& c : list) {
        std::cout << c << " ";
    }
}

std::forward_list<std::string>& exercise_28_sub(std::forward_list<std::string>& list, std::string str_1, std::string str_2) {
    auto previous_node = list.before_begin();
    auto current_node  = list.begin();
    while (current_node != list.end()) {
        if (*current_node == str_1) {
            list.insert_after(current_node, str_2);
            return list;
        }
        previous_node = current_node;
        ++current_node;
    }
    list.insert_after(previous_node, str_2);
    return list;
}


void Exercise_9_3::exercise_9_28() {
    std::forward_list<std::string> list{"hello", "world"};
    exercise_28_sub(list, "hello", "!");
    for (auto const& c : list) {
        std::cout << c << " ";
    }
}
