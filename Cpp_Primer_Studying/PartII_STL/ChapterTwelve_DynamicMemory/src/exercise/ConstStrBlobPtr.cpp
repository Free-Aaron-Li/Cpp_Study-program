// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'ConstStrBlobPtr'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "ConstStrBlobPtr.hpp"
#include "StrBlob.hpp"
ConstStrBlobPtr::ConstStrBlobPtr() : weak_ptr(), current_num(0) {}
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob& strBlob, size_type pos) : weak_ptr(strBlob.data), current_num(pos) {}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(ConstStrBlobPtr::size_type pos, const std::string& message) const {
    auto ret = weak_ptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (pos >= ret->size())
        throw std::out_of_range(message);
    return ret;
}
const std::string&
ConstStrBlobPtr::deref() const {
    return (*check(current_num, "dereference past end"))[current_num];
}
ConstStrBlobPtr&
ConstStrBlobPtr::inc() {
    check(current_num, "increment past end of StrBlobPtr");
    ++current_num;
    return *this;
}
