// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'ConstStrBlobPtr'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_CONSTSTRBLOBPTR_HPP
#define CPP_PRIMER_STUDYING_CONSTSTRBLOBPTR_HPP

class StrBlob;
#include <iostream>
#include <vector>
#include <memory>

class ConstStrBlobPtr {
 public:
    typedef std::vector<std::string>::size_type size_type;

    ConstStrBlobPtr();
    explicit ConstStrBlobPtr(const StrBlob& strBlob, size_type pos = 0);

    const std::string& deref() const;
    ConstStrBlobPtr&   inc();

 private:
    std::weak_ptr<std::vector<std::string>>   weak_ptr;
    size_type                                 current_num;
    std::shared_ptr<std::vector<std::string>> check(size_type pos, const std::string& message) const;
};
#endif  // CPP_PRIMER_STUDYING_CONSTSTRBLOBPTR_HPP
