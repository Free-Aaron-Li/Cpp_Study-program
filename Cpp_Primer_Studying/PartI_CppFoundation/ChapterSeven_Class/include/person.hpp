// This file is part of Cpp_Primer_Studying project.
// This program is called:person.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_PERSON_HPP
#define CPP_PRIMER_STUDYING_PERSON_HPP

#include <iostream>
#include <string>

/**
 * @title
 * Person
 * @description
 * 用于表示人员的姓名和住址。
 */

class Person {
 public:
    std::string _user_name;
    std::string _user_address;

 public:
    std::string get_name() const { return _user_name; }
    std::string get_address() const { return _user_address; }
};

inline std::istream &read(std::istream &istream, Person &item) {
    istream >> item._user_name >> item._user_address;
    return istream;
}

inline std::ostream &print(std::ostream &ostream, const Person &item) {
    ostream << item.get_name() << "\t" << item.get_address();
    return ostream;
}

#endif  // CPP_PRIMER_STUDYING_PERSON_HPP
