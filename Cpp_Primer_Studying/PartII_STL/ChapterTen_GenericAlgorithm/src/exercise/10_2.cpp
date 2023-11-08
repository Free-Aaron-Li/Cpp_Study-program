// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:10_2.
// If there are no special instructions, this file is used as an exercise and test file.

#include "10_2.hpp"

void Exercise_10_2::meaninglessFunction_1() {}

void Exercise_10_2::exercise_10_3() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7, 8};
    int              sum = std::accumulate(vector.cbegin(), vector.cend(), 0);
    std::cout << "the sum for this vector is " << sum << "\n";
}

void Exercise_10_2::exercise_10_4() {
    std::vector<double> vector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.3};
    int                 sum = std::accumulate(vector.cbegin(), vector.cend(), 0);
    std::cout << "the sum for this vector is " << sum << "\n";
}

using std::list;
using std::cout;
void Exercise_10_2::exercise_10_5() {
    /* --------------------------test 1-------------------------*/
    list<const char *> lc(12, "bca");
    list<const char *> lc2(12, "bc");
    cout << equal(lc.cbegin(), lc.cend(), lc2.cbegin()) << "\n";  // #1 output:0

    list<const char *> lc3(12, "bca");
    list<const char *> lc4(12, "bca");
    cout << equal(lc3.cbegin(), lc3.cend(), lc4.cbegin()) << "\n";  // #2 output:1

    cout << typeid(*lc3.begin()).name() << "\n";  // #3 char const *

    /* For detailed reference:https://ask.csdn.net/questions/252777 */
    cout << (*lc3.begin() == *lc4.begin()) << "\n";  // #4 output:1

    /* --------------------------test 2-------------------------*/
    char *p_1[] = {"hello", "world!"};
    char *p_2[] = {"hello", "world!"};
    char *p_3[] = {p_1[0], p_1[1]};

    // Two C-style strings, compare the pointer (addresses of the two strings) (use pointer)
    std::cout << "The two sequences are " << (std::equal(std::begin(p_1), std::end(p_1), std::begin(p_2)) ? "equal." : "not equal.")
              << std::endl;  // equal

    std::cout << "The two sequences are " << (std::equal(std::begin(p_1), std::end(p_1), std::begin(p_3)) ? "equal." : "not equal.")
              << std::endl;  // equal

    bool result = std::equal(std::begin(p_1), std::end(p_1), p_2);
    std::cout << std::begin(p_1) << "\n" << std::begin(p_2) << "\n" << result;  // non-equal address, equal value,return true

    /* --------------------------test 3-------------------------*/
    std::vector<const char *> roster_1{"abc", "def", "ghi"};
    std::vector<const char *> roster_2{"abc", "def", "ghi"};

    // Two C-style strings, compare the value (use iterator)
    std::cout << "The two sequences are " << (std::equal(roster_1.cbegin(), roster_1.cend(), roster_2.cbegin()) ? "equal." : "not equal.")
              << std::endl;  // equal

    // Two library strings, compare the value
    std::vector<std::string> roster3{"abc", "def", "ghi"};
    std::list<std::string>   roster4{"abc", "def", "ghi"};
    std::cout << "The two sequences are " << (std::equal(roster3.cbegin(), roster3.cend(), roster4.cbegin()) ? "equal." : "not equal.")
              << std::endl;  // equal

    // One library string and one C-style string, compare the value
    std::cout << "The two sequences are " << (std::equal(roster_1.cbegin(), roster_1.cend(), roster4.cbegin()) ? "equal." : "not equal.")
              << std::endl;  // equal
}

void Exercise_10_2::exercise_10_6() {
    std::vector<int> vector{1, 2, 3, 4, 5, 6, 7};
    std::fill_n(vector.begin(), vector.size(), 0);
    for (auto const &c : vector)
        std::cout << c << " ";
}

void Exercise_10_2::exercise_10_9() {
    std::vector<std::string> vector{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    std::sort(vector.begin(),vector.end());
    auto end_unique=std::unique(vector.begin(),vector.end());
    vector.erase(end_unique,vector.end());
    for (auto const& c :vector) {
        cout<<c<<" ";
    }
}
