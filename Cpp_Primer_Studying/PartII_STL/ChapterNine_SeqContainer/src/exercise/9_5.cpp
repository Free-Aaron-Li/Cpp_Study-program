// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of Cpp_Primer_Studying project.
// This program is called:9_5. If there are no special instructions, this file is used as an exercise and test file.

#include "9_5.hpp"

void Exercise_9_5::exercise_9_41() {
    std::vector<char> vector{'h', 'e', 'l', 'l', 'o'};
    std::string       str;
    /* first method */
    str.insert(str.begin(), vector.begin(), vector.end());
    /* second method */
    std::string str_1(vector.data(), vector.size());
    std::cout << str << "\n" << str_1;
}

void Exercise_9_5::exercise_9_42() {
    std::string str;
    str.reserve(100); /* Pre-allocate resources to prevent storage space adjustment */
                      /* if no this expression,memory space needs to be created eight times 2^0->2^7 */
    char character;
    while (std::cin >> character) {
        str.push_back(character);
        if (std::cin.get() == '\n')
            break;
    }
}

void exercise_43_sub(std::string& s, const std::string& oldVal, const std::string& newVal) {
    auto s_index = s.begin();
    while (s_index != s.end()) {
        if ((s.end() - s_index) < oldVal.size()) {
            return;
        } else if (oldVal == std::string(s_index, s_index + oldVal.size())) {
            s_index = s.erase(s_index, s_index + oldVal.size());
            s_index = s.insert(s_index, newVal.begin(), newVal.end());
            s_index += newVal.size();
        } else
            ++s_index;
    }
}

void Exercise_9_5::exercise_9_43() {
    std::string s{"tho thru"};
    exercise_43_sub(s, "tho", "though");
    std::cout << s << "\n";
    exercise_43_sub(s, "thru", "though");
    std::cout << s << "\n";
}

void exercise_44_sub(std::string& s, const std::string& oldVal, const std::string& newVal) {
    if (!oldVal.empty())
        return;

    std::string::size_type s_index = 0;
    while (s_index != s.size()) {
        if (oldVal == std::string(s, s_index, oldVal.size()))
            s.replace(s_index, oldVal.size(), newVal);
        ++s_index;
    }
}

void Exercise_9_5::exercise_9_44() {
    std::string s{"tho thru"};
    exercise_43_sub(s, "tho", "though");
    std::cout << s << "\n";
    exercise_43_sub(s, "thru", "though");
    std::cout << s << "\n";
}

std::string exercise_45_sub(const std::string& str, const std::string& prefix, const std::string& suffix) {
    std::string s(str);
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    s.append(" ");
    s.append(suffix.cbegin(), suffix.cend());
    return s;
}

void Exercise_9_5::exercise_9_45() {
    std::string str("Tom");
    std::cout << exercise_45_sub(str, "Mr.", "Jr.") << "\n";
    std::cout << exercise_45_sub("Ashley", "Ms.", "III") << "\n";
}

std::string exercise_46_sub(const std::string& str, const std::string& prefix, const std::string& suffix) {
    std::string s(str);
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    s.insert(s.size(), " ");
    s.insert(s.size(), suffix);
    return s;
}

void Exercise_9_5::exercise_9_46() {
    std::string str("Tom");
    std::cout << exercise_45_sub(str, "Mr.", "Jr.") << "\n";
    std::cout << exercise_45_sub("Ashley", "Ms.", "III") << "\n";
}

void exercise_47_sub_first_version(const std::string& str, const std::string& matching_entry) {
    std::string::size_type position = 0;
    while ((position = str.find_first_of(matching_entry, position)) != std::string::npos) {
        std::cout << str[position] << " ";
        ++position;
    }
}

void exercise_47_sub_second_version(const std::string& str, const std::string& matching_entry) {
    std::string::size_type position        = 0;
    std::string::size_type before_position = 0;
    while ((position = str.find_first_not_of(matching_entry, position)) != std::string::npos) {
        for (auto i = before_position; i != position; ++i) {
            std::cout << str[i] << " ";
        }
        before_position = ++position;
    }
    for (auto i = before_position; i != str.size(); ++i) {
        std::cout << str[before_position] << " ";
    }
}

void searchCharacter(const std::string& str) {
    const std::string numbers("0123456789");
    const std::string alphabets{
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    std::cout << "The First version:\n";
    std::cout << "numbers:";
    exercise_47_sub_first_version(str, numbers);
    std::cout << "\nsingle word:";
    exercise_47_sub_first_version(str, alphabets);
    std::cout << "\nThe Second version:\n";
    std::cout << "numbers:";
    exercise_47_sub_second_version(str, numbers);
    std::cout << "\nsingle word:";
    exercise_47_sub_second_version(str, alphabets);
}

void Exercise_9_5::exercise_9_47() {
    const std::string title("ab2c3d7R4E6");
    searchCharacter(title);
}

void Exercise_9_5::exercise_9_48() {
    const std::string name("r2d2");
    const std::string numbers("0123456789");
    auto              index = numbers.find(name);
    if (index == std::string::npos)
        std::cout << "the character is npos";
    else
        std::cout << numbers[index];
}

bool exercise_49_sub_containAscenderOrDescender(const std::string& str) {
    const std::string matching_entry("bdfghijklpqty");
    return str.find_first_of(matching_entry) != std::string::npos;
}

void Exercise_9_5::exercise_9_49() {
    std::string filename;
    std::cout << "please input the file name: ";
    std::cin >> filename;
    std::ifstream in(filename);
    if (in.is_open()) {
        std::string longest_word, word;
        while (in >> word)
            if (!exercise_49_sub_containAscenderOrDescender(word) && word.size() > longest_word.size())
                longest_word = word;
        if (longest_word.empty())
            std::cout << "This file is called " << filename << ",no word in this file exclude ascender or descender!"
                      << "\n";

        else
            std::cout << "This file is called " << filename << ",the longest word in this file exclude ascender or descender is "
                      << "\"" << longest_word << "\"\n";
    } else {
        std::cerr << "can't open file: " << filename << "\n";
    }
}

void Exercise_9_5::exercise_9_50() {
    std::vector<int> integers{23, 24, 231, 1235, 13, 134, 131, 512, 1341, 1341, 13};
    int              sum = 0;
    for (auto const& c : integers) {
        sum += c;
    }
    std::cout << std::to_string(sum);
}

void Exercise_9_5::exercise_9_51() {}
