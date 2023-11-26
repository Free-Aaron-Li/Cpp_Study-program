// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Query'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "Query.hpp"

TextQuery::TextQuery(std::ifstream& in) : _text(std::make_shared<std::vector<std::string>>()), _lines() {
    _line_on_type ln = 0;
    for (std::string line; std::getline(in, line); _text->push_back(line), ++ln) {
        std::istringstream iss(line);
        for (std::string word; iss >> word;) {
            if (_lines.find(word) == _lines.end())
                _lines.insert({word, std::make_shared<std::set<_line_on_type>>()});
            _lines.at(word)->insert(ln);
        }
    }
}

QueryResult
TextQuery::query(const std::string& word) const {
    auto iter = _lines.find(word);
    if (iter == _lines.end())
        return QueryResult(word);
    _line_on_type total = 0;
    for (const auto& val : *(iter->second)) {
        std::istringstream iss((*_text)[val]);
        for (std::string total_word; iss >> total_word;)
            if (word == total_word)
                ++total;
    }
    return QueryResult(word, total, iter->second, _text);
}

std::string
make_plural(int num, const std::string& str, const std::string& postfix = "s") {
    return num > 1 ? str + postfix : str;
}

std::ostream&
print(std::ostream& os, const QueryResult& queryResult) {
    std::cout << "\"" << queryResult._word << "\" occurs " << queryResult._total << " "
              << make_plural(queryResult._total, "time") << ":\n";
    if (queryResult._total > 0)
        for (const auto& val : *queryResult._line_numbers) {
            std::cout << "(line " << val + 1 << ") " << (*queryResult._line_text)[val] << "\n";
        }
    return os;
}
