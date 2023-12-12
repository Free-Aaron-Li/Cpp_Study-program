// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:10_3.
// If there are no special instructions, this file is used as an exercise and test file.

#include "10_3.hpp"
class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
    friend Sales_data    add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

 public:
    Sales_data() : Sales_data("", 0, 0.0) {}
    explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
    Sales_data(const std::string &no, unsigned us, double price) : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

 private:
    double      avg_price() const;
    std::string bookNo;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;  // Use default copy constructor
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

inline double Sales_data::avg_price() const { return units_sold ? revenue / units_sold : 0; }

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); }
void Exercise_10_3::meaninglessFunction_1() {}

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    /** Returns an iterator to the first position after the unrepeated region */
    auto end_unique = std::unique(words.begin(), words.end());
    /** delete repeated element */
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string &str_1, const std::string &str_2) { return str_1.size() < str_2.size(); }

void Exercise_10_3::exercise_10_11() {
    std::vector<std::string> vector{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vector);
    std::stable_sort(vector.begin(), vector.end(), isShorter);
    for (const auto &c : vector) {
        std::cout << c << " ";
    }
}

bool compareIsbn_v1(const Sales_data &data_1, const Sales_data &data_2) { return data_1.isbn() < data_2.isbn(); }

void Exercise_10_3::exercise_10_12() {
    std::vector<Sales_data> vector;
    vector.emplace_back("01", 12, 12.0);
    vector.emplace_back("01000000", 12, 12.0);
    vector.emplace_back("0100", 12, 12.0);
    vector.emplace_back("01000", 12, 12.0);
    vector.emplace_back("010000", 12, 12.0);
    std::stable_sort(vector.begin(), vector.end(), compareIsbn_v1);
    for (const auto &c : vector) {
        print(std::cout, c) << "\n";
    }
}

bool string_greater_than_four(const std::string &str) { return str.size() >= 5; }

void Exercise_10_3::exercise_10_13() {
    std::vector<std::string> vector{"hello", "is", "good", "word", "is", "right", "?"};
    auto end_target_sequence = std::partition(vector.begin(), vector.end(), string_greater_than_four);
    vector.erase(end_target_sequence, vector.end());
    for (const auto &c : vector) {
        std::cout << c << " ";
    }
}

void Exercise_10_3::exercise_10_14() {
    int  a = 10, b = 20;
    auto c = [](const int &a, const int &b) -> int { return a + b; };
    std::cout << "a + b = " << c(a, b) << "\n";
}

void Exercise_10_3::exercise_10_15() {
    int  a = 10, b = 20;
    auto c = [a, b](const int &c) -> int { return a + b + c; };
    std::cout << "a + b + c = " << c(30) << "\n";
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    std::stable_sort(
      words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
    /** Gets the iterator pointed to by the first element that satisfies size()>=sz */
    auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a) { return a.size() >= sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_16() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies(words, 4);
}

void Exercise_10_3::exercise_10_17() {
    std::vector<Sales_data> data;
    data.emplace_back("01", 12, 12.0);
    data.emplace_back("01000000", 12, 12.0);
    data.emplace_back("0100", 12, 12.0);
    data.emplace_back("01000", 12, 12.0);
    data.emplace_back("010000", 12, 12.0);
    std::stable_sort(data.begin(), data.end(), [](const Sales_data &data_1, const Sales_data &data_2) -> bool {
        return data_1.isbn() < data_2.isbn();
    });
    std::for_each(data.begin(), data.end(), [](const Sales_data &data) { print(std::cout, data) << "\n"; });
}

void biggies_2(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    std::stable_sort(
      words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
    /** Gets the iterator pointed to by the first element that satisfies size()>=sz */
    auto wc = std::partition(words.begin(), words.end(), [sz](const std::string &s) -> bool { return s.size() < sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_18() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies_2(words, 4);
}

void biggies_3(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    /** Sort word by dictionary and remove duplicate words */
    elimDups(words);
    /** Gets an iterator where words of the same length maintain lexicographic order */
    auto wc
      = std::stable_partition(words.begin(), words.end(), [sz](const std::string &s) -> bool { return s.size() < sz; });
    /** print */
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

void Exercise_10_3::exercise_10_19() {
    std::vector<std::string> words{"hello", "worlds", "this", "is", "new", "life"};
    biggies_3(words, 4);
}

void Exercise_10_3::exercise_10_20() {
    std::vector<std::string> data{"hello,is", "good", "word", "is,right", "?"};
    auto count = std::count_if(data.begin(), data.end(), [](const std::string &s) -> bool { return s.size() > 6; });
    std::cout << count << "\n";
}

void Exercise_10_3::exercise_10_21() {
    int  i         = 10;
    auto i_is_zero = [i]() mutable -> bool {
        while (i != 0)
            --i;
        if (i == 0)
            return true;
        else
            return false;
    };

    std::cout << "i is zero? " << (i_is_zero() ? "yes" : "no") << "\n";
}

bool isShorter_2(const std::string &s, const size_t &c) { return s.size() > c; }

void Exercise_10_3::exercise_10_22() {
    std::vector<std::string> data{"hello,is", "good", "word", "is,right", "?"};
    auto count = std::count_if(data.begin(), data.end(), std::bind(isShorter_2, std::placeholders::_1, 6));
    std::cout << "The number of words with length greater than 6 in data are: " << count << "\n";
}

bool check_size(const int &string_size, const int &i) { return i > 0 && i > string_size; }

void Exercise_10_3::exercise_10_24() {
    std::string      str("hello,world!");
    std::vector<int> data{2, 4, 6, 8, 10, 12, 24};
    auto result = std::find_if(data.begin(), data.end(), std::bind(check_size, str.size(), std::placeholders::_1));
    std::cout << *result << "\n";
}

bool          check_size_v2(const std::string &s, const int &i) { return i > 0 && i > s.size(); }
std::ostream &print_v2(std::ostream &os, const std::string &s, char c) { return os << s << c; }

void Exercise_10_3::exercise_10_25() {
    std::vector<std::string> data{"hello,is", "good", "word", "is,right", "?"};
    elimDups(data);
    std::stable_sort(data.begin(), data.end(), std::bind(isShorter, std::placeholders::_1, std::placeholders::_2));
    auto result = std::partition(data.begin(), data.end(), std::bind(check_size_v2, std::placeholders::_1, 6));
    std::for_each(result, data.end(), std::bind(print_v2, std::ref(std::cout), std::placeholders::_1, '\n'));
}
