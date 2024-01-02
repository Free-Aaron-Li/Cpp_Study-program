// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Folder'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "Folder.hpp"

Folder::Folder(const Folder& obj) : _messages(obj._messages) {
    add_to_Message(obj);
}

Folder&
Folder::operator=(const Folder& obj) {
    remove_from_Message();
    _messages = obj._messages;
    add_to_Message(obj);
    return *this;
}

Folder::~Folder() {
    remove_from_Message();
}

void
Folder::add_Message(Message& message) {
    _messages.insert(&message);
}

void
Folder::remove_Message(Message& message) {
    _messages.erase(&message);
}

void
Folder::add_to_Message(const Folder& folder) {
    for (auto val : folder._messages)
        val->add_Folder(*this);
}

void
Folder::remove_from_Message() {
    while (!_messages.empty())
        (*_messages.begin())->remove(*this);
}
