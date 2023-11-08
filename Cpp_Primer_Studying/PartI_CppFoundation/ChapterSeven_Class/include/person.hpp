// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:person.
// If there are no special instructions, this file is used as an exercise and test file.

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
    friend std::istream &read(std::istream &, Person &);
    friend std::ostream &print(std::ostream &, const Person &);

 public:
    Person() = default;
    Person(std::string &name, std::string &address) : _user_name(std::move(name)), _user_address(std::move(address)){};
    explicit Person(std::istream &is) { read(is, *this); }

 public:
    std::string get_name() const { return _user_name; }
    std::string get_address() const { return _user_address; }

 private:
    std::string _user_name;
    std::string _user_address;
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
