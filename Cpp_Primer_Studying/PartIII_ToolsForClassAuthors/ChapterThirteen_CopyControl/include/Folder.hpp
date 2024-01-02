// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Folder'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef CPP_PRIMER_STUDYING_FOLDER_HPP
#define CPP_PRIMER_STUDYING_FOLDER_HPP

#include "Message.hpp"

class Folder {
    friend class Message;

 public:
    Folder() = default;
    Folder(const Folder& obj);
    Folder& operator=(const Folder& obj);
    ~Folder();

    void add_Message(Message& message);
    void remove_Message(Message& message);

 private:
    std::set<Message*> _messages;
    void               add_to_Message(const Folder& folder);
    void               remove_from_Message();
};
#endif  // CPP_PRIMER_STUDYING_FOLDER_HPP