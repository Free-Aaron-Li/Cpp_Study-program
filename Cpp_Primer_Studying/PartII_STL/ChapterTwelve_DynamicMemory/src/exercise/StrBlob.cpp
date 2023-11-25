// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'StrBlob'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> initializerList)
    : data(std::make_shared<std::vector<std::string>>(initializerList)) {}

void
StrBlob::check(std::size_t position, const std::string &message) const {
    if (position >= data->size())
        throw std::out_of_range(message);
}

void
StrBlob::push_back(const std::string &string) {
    data->push_back(string);
}

void
StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob!");
    data->pop_back();
}

std::string &
StrBlob::front() {
    check(0, "front on empty StrBlob!");
    data->front();
}

const std::string &
StrBlob::front() const {
    check(0, "front on empty StrBlob!");
    data->front();
}

std::string &
StrBlob::back() {
    check(0, "back on empty StrBlob!");
    data->back();
}

const std::string &
StrBlob::back() const {
    check(0, "back on empty StrBlob!");
    data->back();
}

StrBlobPtr
StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr
StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}
