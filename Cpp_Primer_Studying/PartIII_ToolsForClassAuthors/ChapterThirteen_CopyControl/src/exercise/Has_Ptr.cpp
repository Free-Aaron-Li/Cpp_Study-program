// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Has_Ptr'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "Has_Ptr.hpp"

Has_Ptr::~Has_Ptr() { delete _ps; }

Has_Ptr &
Has_Ptr::operator=(const Has_Ptr &obj) {
    delete _ps;
    _ps = new std::string(*obj._ps);
    _i  = obj._i;
    return *this;
}

Like_value_HasPtr &
Like_value_HasPtr::operator=(const Like_value_HasPtr &hasPtr) {
    /* it must be executed in a normal order, even if it copies itself */
    auto new_ps = new std::string(*hasPtr._ps);  // 1. copying underlying string
    delete _ps;                                  // 2. free memory
    _ps = new_ps;                                // 3. copy data from the right operator object to this object
    _i  = hasPtr._i;
    return *this;  // 4. return this object
}
