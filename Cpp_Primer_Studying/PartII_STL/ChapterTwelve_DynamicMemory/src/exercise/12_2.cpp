// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "12_2.hpp"

void
Exercise_12_2::meaninglessFunction_1() {}

//------------------------------------------------------------------------------------------------
//
void
join_v1(const char* str_1, const char* str_2) {
    char* data(new char[std::strlen(str_1) + std::strlen(str_2)]);
    std::strcpy(data, str_1);
    std::strcat(data, str_2);
    std::cout << data << "\n";
    delete[] data;
}

void
join_v2(const std::string str_1, const std::string str_2) {
    std::string data = str_1 + str_2;
    std::cout << data << "\n";
}

void
Exercise_12_2::exercise_12_23() {
    const char* char_string_1 = "hello ";
    const char* char_string_2 = "world";
    join_v1(char_string_1, char_string_2);

    std::string string_1 = "welcome ";
    std::string string_2 = "thanks";
    join_v2(string_1, string_2);
}
//
//------------------------------------------------------------------------------------------------

void
Exercise_12_2::exercise_12_24() {
    std::cout << "Please enter string: ";
    char                    character;
    std::size_t             length = 10, i = 0;
    std::unique_ptr<char[]> data(new char[length]);
    while (std::cin.get(character)) {
        if (isspace(character))
            break;
        data[i++] = character;
        if (i == length) {
            std::cerr << "The upper limit of array size was reached\n";
            return;
        }
    }

    for (std::size_t j = 0; j < i; ++j)
        std::cout << data[j];
}

void
Exercise_12_2::exercise_12_26() {
    std::allocator<std::string> alloc;
    std::size_t                 n = 10;
    std::string                 string;
    auto const                  p = alloc.allocate(n);
    auto                        q = p;
    while (std::cin >> string && q != p + n) {
        if (std::cin.get() == '\n')
            break;
        alloc.construct(q++, string);
    }

    const std::size_t size = q - p;
    for (auto pos = p; pos != q; ++pos)
        std::cout << *pos << "\n";
    std::cout << "size is: " << size << "\n";
    while (q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
}
