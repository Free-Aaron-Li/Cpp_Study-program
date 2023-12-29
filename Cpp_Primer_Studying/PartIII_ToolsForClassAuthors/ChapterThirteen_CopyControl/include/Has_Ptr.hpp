// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Has_Ptr'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_HAS_PTR_HPP
#define CPP_PRIMER_STUDYING_HAS_PTR_HPP

#include <iostream>
#include <string>

class Has_Ptr {
 public:
    explicit Has_Ptr(const std::string &str = std::string()) : _ps(new std::string(str)), _i(0) {}
    Has_Ptr(const Has_Ptr &obj) : _ps(new std::string(*obj._ps)), _i(obj._i) {}  // copy constructor
    ~Has_Ptr();

    Has_Ptr &operator=(const Has_Ptr &obj);

    const std::string &get_str() const { return *_ps; }
    const int         &get_int() const { return _i; }
    void               set(const std::string &str, const int i) {
        *_ps = str;
        _i   = i;
    }

 private:
    std::string *_ps;
    int          _i;
};

class Like_value_HasPtr {
 public:
    explicit Like_value_HasPtr(const std::string &str = std::string()) : _ps(new std::string(str)), _i(0) {}
    Like_value_HasPtr(const Like_value_HasPtr &obj) : _ps(new std::string(*obj._ps)), _i(obj._i) {}

    Like_value_HasPtr &operator=(const Like_value_HasPtr &);
    ~Like_value_HasPtr() { delete _ps; }

 private:
    std::string *_ps;
    int          _i{};
};

#endif  // CPP_PRIMER_STUDYING_HAS_PTR_HPP
