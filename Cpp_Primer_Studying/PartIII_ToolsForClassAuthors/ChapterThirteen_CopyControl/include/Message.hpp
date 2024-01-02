// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Message'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_MESSAGE_HPP
#define CPP_PRIMER_STUDYING_MESSAGE_HPP

#include "Folder.hpp"
#include <iostream>
#include <set>
#include <utility>

class Message {
    friend class Folder;

 public:
    explicit Message(std::string str = "") : _contents(std::move(str)) {}

    Message(const Message& obj);
    Message& operator=(const Message& obj);
    ~Message();

    void save(Folder& folder);
    void remove(Folder& folder);
    void swap(Message& lhs, Message& rhs);
    void add_Folder(Folder& folder);
    void remove_Folder(Folder& folder);

 private:
    std::string       _contents;  // message text
    std::set<Folder*> _folders;   // folders containing this message
    /* Tools */
    void              add_to_Folders(const Message& message);  // adding assignment message to folder
    void              remove_from_Folders();                   // delete message from each folder in folders
};
#endif  // CPP_PRIMER_STUDYING_MESSAGE_HPP
