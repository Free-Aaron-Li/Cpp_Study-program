// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "13_1.hpp"

void
Exercise_13_1::meaninglessFunction_1() {}
void
Exercise_13_1::meaninglessFunction_2() {}
void
Exercise_13_1::meaninglessFunction_3() {}
void
Exercise_13_1::meaninglessFunction_4() {}

class HasPtr {
 public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) {}

    const std::string &get() const { return *ps; }
    void               set(const std::string &s) { *ps = s; }

 private:
    std::string *ps;
    int          i;
};

void
Exercise_13_1::exercise_13_5() {
    HasPtr hasPtr_1 = std::string("world");
    HasPtr hasPtr_2 = hasPtr_1;
    hasPtr_1.set("hello");
    std::cout << hasPtr_1.get() << " " << hasPtr_2.get() << "\n";
}
