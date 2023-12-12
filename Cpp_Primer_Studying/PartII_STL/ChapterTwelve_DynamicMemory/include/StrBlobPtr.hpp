// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'StrBlobPtr'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_STRBLOBPTR_HPP
#define CPP_PRIMER_STUDYING_STRBLOBPTR_HPP

class StrBlob;
#include <iostream>
#include <vector>
#include <memory>

class StrBlobPtr {
 public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlobPtr();
    explicit StrBlobPtr(StrBlob& strBlob, size_type pos = 0);
    /// deference
    std::string& deref() const;
    /// Prefix increment
    StrBlobPtr&  incr();

 private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>>   weak_ptr;
    std::size_t                               current_num;
};

#endif  // CPP_PRIMER_STUDYING_STRBLOBPTR_HPP
