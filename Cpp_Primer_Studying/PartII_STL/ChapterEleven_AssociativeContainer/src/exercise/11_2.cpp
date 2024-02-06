// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'11_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "11_2.hpp"

void
Exercise_11_2::meaninglessFunction_1() {}
void
Exercise_11_2::meaninglessFunction_2() {}
void
Exercise_11_2::meaninglessFunction_3() {}
void
Exercise_11_2::meaninglessFunction_4() {}

//------------------------------------------------------------------------------------------------

std::multimap<std::string, std::string>&
separation_name(std::multimap<std::string, std::string>& name_list, const std::vector<std::string> names) {
    std::string first_name, last_name;
    for (auto& val : names) {
        first_name = val.substr(0, 3);
        last_name  = val.substr(3);
        name_list.insert({first_name, last_name});
    }
    return name_list;
}

typedef std::map<std::string, std::vector<std::string>> family_type;
void
add_family(family_type& families, const std::string& name) {
    families.insert({name, std::vector<std::string>()});
}

void
add_member(family_type& families, const std::string& family_name, const std::string& member_name) {
    auto iter = families.find(family_name);
    if (iter != families.end())
        iter->second.push_back(member_name);
    else
        std::cerr << "Error: No family <" << family_name << "> for member <" << member_name << ">\n";
}

void
Exercise_11_2::exercise_11_7(const std::vector<std::string>& names) {
    std::multimap<std::string, std::string> separation_names{};
    separation_name(separation_names, names);

    family_type families;
    for (const auto& val : separation_names) {
        add_family(families, val.first);
        add_member(families, val.first, val.second);
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
Exercise_11_2::exercise_11_8(const std::vector<std::string>& data) {
    std::vector<std::string> words{data.begin(), data.end()};
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    for (const auto& word : words)
        std::cout << word << " ";
}

void
Exercise_11_2::exercise_11_9() {
    std::map<std::string, std::list<int>> words{{"abc", {1, 2}}, {"def", {3, 4}}, {"ghl", {5, 6}}};
    for (const auto& val : words) {
        std::cout << val.first << ":";
        for (const auto& c : val.second)
            std::cout << " " << c;
        std::cout << "\n";
    }
}
void
Exercise_11_2::exercise_11_12() {
    std::vector<std::pair<std::string, int>> sequence;
    std::vector<int>                         numbers{1, 2};
    std::vector<std::string>                 strings{"hello", "world"};

    for (int i = 0; i < 2; ++i)
        sequence.push_back({strings[i], numbers[i]});

    for (const auto& val : sequence)
        std::cout << val.first << " " << val.second << "\n";
}

void
Exercise_11_2::exercise_11_13() {
    std::vector<std::pair<std::string, int>> sequence;
    std::vector<int>                         numbers{1, 2};
    std::vector<std::string>                 strings{"hello", "world"};

    for (int i = 0; i < 2; ++i) {
        // sequence.push_back({strings[i], numbers[i]}); // 1.
        sequence.push_back(std::make_pair(strings[i], numbers[i]));  // 2.
        // sequence.push_back(std::pair<std::string,int>(strings[i],numbers[i])); //3.
    }

    for (const auto& val : sequence)
        std::cout << val.first << " " << val.second << "\n";
}

//------------------------------------------------------------------------------------------------

typedef std::map<std::string, std::vector<std::pair<std::string, std::string>>> family_plus_type;
void
add_family(family_plus_type& families, const std::string& name) {
    families.insert({name, std::vector<std::pair<std::string, std::string>>()});
}

void
add_member(
  family_plus_type& families, const std::string& family_name, const std::string& member_name,
  const std::string birthday) {
    auto iter = families.find(family_name);
    if (iter != families.end())
        iter->second.push_back(std::make_pair(member_name, birthday));
    else
        std::cerr << "Error: No family <" << family_name << "> for member <" << member_name << ">\n";
}

void
Exercise_11_2::exercise_11_14(const std::vector<std::string>& data) {
    std::multimap<std::string, std::string> separation_names{};
    separation_name(separation_names, data);

    family_plus_type families;
    for (const auto& val : separation_names) {
        add_family(families, val.first);
        if (val.second.begin() == val.second.end())
            continue;
        std::string last_name = std::string(val.second.begin(), val.second.end() - 10);
        std::string birthday  = std::string(val.second.end() - 10, val.second.end());
        add_member(families, val.first, last_name, birthday);
    }

    for (const auto& family : families) {
        std::cout << "The members of " << family.first << " family have: \n";
        for (const auto& member : family.second) {
            /* TODO 23-11-15 How do I determine if a pair is empty */
            std::cout << "name is: " << family.first << member.first << ", birthday is: " << member.second << "\n";
        }
        std::cout << "\n";
    }
}

//------------------------------------------------------------------------------------------------
