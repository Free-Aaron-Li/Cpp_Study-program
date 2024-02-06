// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'StrBlob'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_STRBLOB_HPP
#define CPP_PRIMER_STUDYING_STRBLOB_HPP

class StrBlobPtr;
class ConstStrBlobPtr;
#include <iostream>
#include <vector>
#include <memory>

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

 public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> initializerList);

    size_type size() const { return data->size(); }
    bool      empty() const { return data->empty(); }

    void push_back(const std::string &string);
    void pop_back();

    std::string       &front();
    const std::string &front() const;
    std::string       &back();
    const std::string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

 private:
    std::shared_ptr<std::vector<std::string>> data;
    void                                      check(size_type position, const std::string &message) const;
};

#endif  // CPP_PRIMER_STUDYING_STRBLOB_HPP
