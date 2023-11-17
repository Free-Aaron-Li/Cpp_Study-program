// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug,please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_3'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_3.hpp"

void
Exercise_11_3::meaninglessFunction_1() {}
void
Exercise_11_3::meaninglessFunction_2() {}
void
Exercise_11_3::meaninglessFunction_3() {}
void
Exercise_11_3::meaninglessFunction_4() {}
void
Exercise_11_3::meaninglessFunction_5() {}
void
Exercise_11_3::meaninglessFunction_6() {}
void
Exercise_11_3::meaninglessFunction_7() {}
void
Exercise_11_3::meaninglessFunction_8() {}
void
Exercise_11_3::meaninglessFunction_9() {}
void
Exercise_11_3::meaninglessFunction_10() {}
void
Exercise_11_3::meaninglessFunction_11() {}
void
Exercise_11_3::meaninglessFunction_12() {}

void
Exercise_11_3::exercise_11_16() {
    std::map<std::string, int> val{{"hello", 0}};
    auto                       map_iter = val.begin();
    map_iter->second                    = 1;
    std::cout << map_iter->first << " " << map_iter->second << "\n";
}

void
Exercise_11_3::exercise_11_20(const std::vector<std::string>& data) {
    std::map<std::string, std::size_t> word_count;
    std::string                        word;
    for (const auto& val : data) {
        auto result = word_count.insert({val, 1});
        if (!result.second)
            ++result.first->second;
    }
    for (const auto& val : word_count) {
        if (!val.first.empty())
            std::cout << "The \"" << val.first << "\" have " << val.second << ((val.second > 1) ? " time" : " times")
                      << "\n";
    }
}

//------------------------------------------------------------------------------------------------

std::multimap<std::string, std::string>&
separation_name_v2(std::multimap<std::string, std::string>& name_list, const std::vector<std::string> data) {
    std::string first_name, last_name;
    for (auto& val : data) {
        first_name = val.substr(0, 3);
        last_name  = val.substr(3);
        name_list.insert({first_name, last_name});
    }
    return name_list;
}

typedef std::multimap<std::string, std::vector<std::string>> family_type;
void
add_family_v2(family_type& families, const std::string& name) {
    families.insert({name, std::vector<std::string>()});
}

void
add_member_v2(family_type& families, const std::string& family_name, const std::string& member_name) {
    auto iter = families.find(family_name);
    if (iter != families.end())
        iter->second.push_back(member_name);
    else
        std::cerr << "Error: No family <" << family_name << "> for member <" << member_name << ">\n";
}

void
Exercise_11_3::exercise_11_23(const std::vector<std::string>& data) {
    std::multimap<std::string, std::string> separation_names{};
    separation_name_v2(separation_names, data);

    family_type families;
    for (const auto& val : separation_names) {
        add_family_v2(families, val.first);
        add_member_v2(families, val.first, val.second);
    }

    for (const auto& family : families) {
        std::cout << "The members of " << family.first << " family have: \n";
        for (const auto& family_member : family.second) {
            if (family_member.empty()) {
                std::cout << "null";
                continue;
            }
            std::cout << family.first << family_member << " ";
        }
        std::cout << "\n";
    }
}

//------------------------------------------------------------------------------------------------

void
Exercise_11_3::exercise_11_26() {
    std::map<std::string, std::size_t> word_count{};
    std::string                        val{"hello"};              // string
    auto                               result = word_count[val];  // size_t
}


void
Exercise_11_3::exercise_11_28() {
    std::map<std::string, std::vector<int>> data{{"a", {1, 2}}};
    auto                                    result = data.find("a");
    std::cout << "first: " << result->first << " ,second: " << result->second.front() << " " << result->second.back();
}

//------------------------------------------------------------------------------------------------

typedef std::multimap<std::string, std::string> book_type;
book_type&
separation_name_v3(book_type& name_list, const std::vector<std::string> data) {
    std::string author_name, book_name;
    for (auto& val : data) {
        auto index  = val.find("《");
        author_name = val.substr(0, index);
        book_name   = val.substr(index);
        name_list.insert({author_name, book_name});
    }
    return name_list;
}

void
print(book_type& data) {
    std::cout << " All the book are: \n";
    for (const auto& val : data) {
        std::cout << "Author: " << val.first << "\t,Book: " << val.second << "\n";
    }
}

void
Exercise_11_3::exercise_11_31(const std::vector<std::string>& data) {
    book_type name_list{};
    separation_name_v3(name_list, data);

    std::cout << "Please enter value for you want: ";
    std::string target_author{};
    std::cin >> target_author;

    auto remove_range = name_list.equal_range(target_author);
    name_list.erase(remove_range.first, remove_range.second);
    print(name_list);
}

//------------------------------------------------------------------------------------------------

const std::string&
transform(const std::string& word, const std::map<std::string, std::string>& rule_list) {
    auto map_iter = rule_list.find(word);
    if (map_iter != rule_list.end())
        return map_iter->second;
    else
        return word;
}

std::map<std::string, std::string>
build_map(std::ifstream& rule_dictionary) {
    std::map<std::string, std::string> rule_map;
    std::string                        key, value;
    while (rule_dictionary >> key && getline(rule_dictionary, value))
        if (value.size() > 1)
            rule_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    return rule_map;
}

void
Exercise_11_3::exercise_11_33(std::ifstream& rule_dictionary, std::ifstream& input_file) {
    auto        rule_map = build_map(rule_dictionary);
    std::string text, word;
    while (getline(input_file, text)) {
        std::istringstream stream(text);
        bool               has_no_space = true;
        while (stream >> word) {
            if (has_no_space)
                has_no_space = false;
            else
                std::cout << " ";
            std::cout << transform(word, rule_map);
        }
        std::cout << "\n";
    }
}

//------------------------------------------------------------------------------------------------
