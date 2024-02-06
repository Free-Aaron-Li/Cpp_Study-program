// Copyright (c) 2023-2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Message'.
// If there are no special instructions, this file is used as an exercise and
// test file.
#include "Message.hpp"

Message::Message(const Message &obj)
    : _contents(obj._contents), _folders(obj._folders) {
  add_to_Folders(obj);
}

void Message::save(Folder &folder) {
  _folders.insert(&folder); // &folder, get Folder address
  folder.add_Message(this);
}

void Message::remove(Folder &folder) {
  _folders.erase(&folder);
  folder.remove_Message(this);
}

void Message::add_to_Folders(const Message &message) {
  for (auto val : message._folders)
    val->add_Message(this);
}

Message::~Message() { remove_from_Folders(); }

void Message::remove_from_Folders() {
  for (auto val : _folders) {
    val->remove_Message(this);
  }
}

Message &Message::operator=(const Message &obj) {
  remove_from_Folders();
  _contents = obj._contents;
  _folders = obj._folders;
  add_to_Folders(obj);
  return *this;
}

void Message::swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto val : lhs._folders)
    val->remove_Message(&lhs);
  for (auto val : rhs._folders)
    val->remove_Message(&rhs);
  swap(lhs._folders, rhs._folders);
  swap(lhs._contents, rhs._contents);
  for (auto val : lhs._folders)
    val->add_Message(&lhs);
  for (auto val : rhs._folders)
    val->add_Message(&rhs);
}

void Message::add_Folder(Folder &folder) { _folders.insert(&folder); }

void Message::remove_Folder(Folder &folder) { _folders.erase(&folder); }
