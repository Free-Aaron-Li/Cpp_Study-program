// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know: <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Query'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_QUERY_HPP
#define CPP_PRIMER_STUDYING_QUERY_HPP

class QueryResult;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>

class TextQuery {
 public:
    typedef std::vector<std::string>::size_type _line_on_type;

    explicit TextQuery(std::ifstream &in);

    QueryResult query(const std::string &word) const;

 private:
    std::shared_ptr<std::vector<std::string>>                       _text;
    std::map<std::string, std::shared_ptr<std::set<_line_on_type>>> _lines;
};

class QueryResult {
    friend std::ostream &print(std::ostream &os, const QueryResult &queryResult);

 public:
    typedef TextQuery::_line_on_type _line_on_type;

    QueryResult() {}
    explicit QueryResult(const std::string &word) : _word(word), _total(0), _line_numbers(), _line_text() {}
    QueryResult(
      const std::string &word, _line_on_type type, std::shared_ptr<const std::set<_line_on_type>> line_numbers,
      std::shared_ptr<const std::vector<std::string>> line_text)
        : _word(word), _total(type), _line_numbers(line_numbers), _line_text(line_text) {}

 private:
    std::string                                     _word;
    _line_on_type                                   _total;
    std::shared_ptr<const std::set<_line_on_type>>  _line_numbers;
    std::shared_ptr<const std::vector<std::string>> _line_text;
};

std::ostream &
print(std::ostream &os, const QueryResult &queryResult);
#endif  // CPP_PRIMER_STUDYING_QUERY_HPP
