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
