// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'12_1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "12_1.hpp"

void
Exercise_12_1::meaninglessFunction_1() {}
void
Exercise_12_1::meaninglessFunction_2() {}
void
Exercise_12_1::meaninglessFunction_3() {}
void
Exercise_12_1::meaninglessFunction_4() {}
void
Exercise_12_1::meaninglessFunction_5() {}
void
Exercise_12_1::meaninglessFunction_6() {}
void
Exercise_12_1::meaninglessFunction_7() {}
void
Exercise_12_1::meaninglessFunction_8() {}
void
Exercise_12_1::meaninglessFunction_9() {}

//------------------------------------------------------------------------------------------------

void
testStrBlob(StrBlob& strBlob) {
    try {
        strBlob.push_back("abc");
        strBlob.push_back("def");
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
        strBlob.pop_back();
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
        strBlob.pop_back();
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
testStrBlob(const StrBlob& strBlob) {
    try {
        std::cout << "front is: " << strBlob.front() << ", and back is: " << strBlob.back() << "\n";
    } catch (std::out_of_range error) {
        std::cerr << error.what() << ", the type is out_of_range\n";
    } catch (std::exception error) { std::cerr << error.what() << "\n"; }
}

void
Exercise_12_1::exercise_12_2() {
    StrBlob       strBlob_1;
    StrBlob       strBlob_2{"hello", "world"};
    StrBlob       strBlob_3 = {"wuhu", "best", "ok"};
    const StrBlob const_strBlob_1;
    const StrBlob const_strBlob_2{"yes", "you", "right"};
    StrBlob       strBlob_4({"ni", "hao"});

    std::cout << "strBlob_1 is:\n";
    testStrBlob(strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_2 is:\n";
    testStrBlob(strBlob_2);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_3 is:\n";
    testStrBlob(strBlob_3);
    std::cout << "\n-----------------------------------\n";

    std::cout << "const_strBlob_1 is:\n";
    testStrBlob(const_strBlob_1);
    std::cout << "\n-----------------------------------\n";

    std::cout << "const_strBlob_2 is:\n";
    testStrBlob(const_strBlob_2);
    std::cout << "\n-----------------------------------\n";

    std::cout << "strBlob_4 is:\n";
    testStrBlob(strBlob_4);
    std::cout << "\n-----------------------------------\n";
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------

std::vector<int>*
factory() {
    return new std::vector<int>;
}

void
set_vector(std::vector<int>* data) {
    int i;
    while (std::cin >> i) {
        data->push_back(i);
        if (std::cin.get() == '\n')
            break;
    }
}

void
print_vector(std::vector<int>* data) {
    for (const auto& val : *data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void
Exercise_12_1::exercise_12_6() {
    auto* data = factory();
    set_vector(data);
    print_vector(data);
    delete data;
    data = nullptr;
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------

typedef std::shared_ptr<std::vector<int>> shared_ptr;

shared_ptr
factory_v2() {
    return std::make_shared<std::vector<int>>();
}

void
set_vector(shared_ptr data) {
    int i;
    while (std::cin >> i) {
        data->push_back(i);
        if (std::cin.get() == '\n')
            break;
    }
}

void
print_vector(shared_ptr data) {
    for (const auto& val : *data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void
Exercise_12_1::exercise_12_7() {
    auto data = factory_v2();
    set_vector(data);
    print_vector(data);
}

//------------------------------------------------------------------------------------------------

void
process(std::shared_ptr<int> ptr) {
    *ptr += 1;
}

void
Exercise_12_1::exercise_12_12() {
    auto p  = new int();
    auto sp = std::make_shared<int>();

    // (a) OK. Initialize a shared pointer `ptr` inside function `process` as a
    // copy of `sp`, increase the reference count. After the function is
    // executed, destory `ptr` and decrease the reference count.
    process(sp);

    // (b) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
    // process(new int());

    // (c) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
    // process(p);

    // (d) Error. Initialize a shared pointer `ptr` inside function `process`
    // using ordinary pointer `p`, increase the reference count to 1. After the
    // function is executed, destory `ptr` and decrease the reference count to 0,
    // thus freed the memory pointed by `ptr`. However, the original ordianry
    // pointer `p` still points to that memory.
    process(std::shared_ptr<int>(p));

    std::cout << "p is: " << *p << ", sp is: " << *sp << "\n";
}
