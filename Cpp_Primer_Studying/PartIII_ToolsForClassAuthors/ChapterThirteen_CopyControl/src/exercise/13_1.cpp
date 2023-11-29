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
void
Exercise_13_1::meaninglessFunction_5() {}
void
Exercise_13_1::meaninglessFunction_6() {}
void
Exercise_13_1::meaninglessFunction_7() {}
void
Exercise_13_1::meaninglessFunction_8() {}
void
Exercise_13_1::meaninglessFunction_9() {}

class HasPtr {
 public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) {}
    ~HasPtr();

    HasPtr &operator=(const HasPtr &obj);

    const std::string &get() const { return *ps; }
    void               set(const std::string &s) { *ps = s; }

 private:
    std::string *ps;
    int          i;
};

HasPtr &
HasPtr::operator=(const HasPtr &obj) {
    delete ps;
    ps = new std::string(*obj.ps);
    i  = obj.i;
    return *this;
}
HasPtr::~HasPtr() { delete ps; }

void
Exercise_13_1::exercise_13_5() {
    HasPtr hasPtr_1 = std::string("world");
    HasPtr hasPtr_2 = hasPtr_1;
    hasPtr_1.set("hello");
    std::cout << hasPtr_1.get() << " " << hasPtr_2.get() << "\n";
}

void
Exercise_13_1::exercise_13_8() {
    HasPtr hasPtr_1 = std::string("world");
    HasPtr hasPtr_2 = hasPtr_1;
    hasPtr_1.set("hello");
    std::cout << hasPtr_1.get() << " " << hasPtr_2.get() << "\n";
}
void
Exercise_13_1::exercise_13_11() {
    HasPtr hasPtr_1 = std::string("world");
    HasPtr hasPtr_2 = hasPtr_1;
    hasPtr_1.set("hello");
    std::cout << hasPtr_1.get() << " " << hasPtr_2.get() << "\n";
}

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &obj) { std::cout << "operator=(const X &obj)" << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void
function_v1(X x) {}
void
function_v2(X &x) {}
void
Exercise_13_1::exercise_13_13() {
    std::cout << "Local variable: \n";
    X x;
    std::cout << "\nNon-referential parameter passing: \n";
    function_v1(x);
    std::cout << "\nreferential parameter passing: \n";
    function_v2(x);
    std::cout << "\nDynamic allocation: \n";
    X *px = new X;
    std::cout << "\nAdd to container: \n";
    std::vector<X> vec;
    vec.push_back(x);
    std::cout << "\nReleases the dynamically allocated object: \n";
    delete px;
    std::cout << "\nIndirect initialization and assignment: \n";
    X n = x;
    n   = x;
}
