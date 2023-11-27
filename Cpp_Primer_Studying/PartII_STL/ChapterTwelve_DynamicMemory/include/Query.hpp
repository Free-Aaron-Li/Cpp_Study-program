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
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>

/// Save input file and Inquire
class TextQuery {
 public:
    typedef std::vector<std::string>::size_type _line_on_type;

    TextQuery() = default;
    explicit TextQuery(std::ifstream &in);

    QueryResult query(const std::string &target_word) const;

 private:
    /// input file text
    std::shared_ptr<std::vector<std::string>>                       _text;
    /// Associate each word to the set of line numbers on which that word appears
    std::map<std::string, std::shared_ptr<std::set<_line_on_type>>> _lines;
};

///  Save Inquire result
class QueryResult {
    friend std::ostream &print(std::ostream &os, const QueryResult &queryResult);

 public:
    typedef TextQuery::_line_on_type _line_on_type;

    QueryResult() = default;
    explicit QueryResult(std::string word) : _word(std::move(word)), _total(0), _line_numbers(), _line_text() {}
    QueryResult(
      std::string word, _line_on_type total, std::shared_ptr<const std::set<_line_on_type>> line_numbers,
      std::shared_ptr<const std::vector<std::string>> line_text)
        : _word(std::move(word)),
          _total(total),
          _line_numbers(std::move(line_numbers)),
          _line_text(std::move(line_text)) {}

 private:
    /// Query target word
    std::string                                     _word;
    /// The number of words in which the target word appears
    _line_on_type                                   _total{};
    /// lines number
    std::shared_ptr<const std::set<_line_on_type>>  _line_numbers;
    /// Line text that contains the target word
    std::shared_ptr<const std::vector<std::string>> _line_text;
};

std::ostream &
print(std::ostream &os, const QueryResult &queryResult);

#endif  // CPP_PRIMER_STUDYING_QUERY_HPP
