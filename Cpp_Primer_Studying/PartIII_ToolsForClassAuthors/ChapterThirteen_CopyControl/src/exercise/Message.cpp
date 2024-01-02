// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'Message'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "Message.hpp"

void
Message::save(Folder& folder) {
    _folders.insert(&folder);
    folder.add_Message();
}

void
Message::remove(Folder& folder) {
    _folders.erase(&folder);
    folder.remove_Message();
}
