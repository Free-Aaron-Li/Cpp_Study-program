// This file is part of Cpp_Primer_Studying project.
// This program is called:9_5. If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
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
