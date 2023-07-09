// This file is part of Cpp_Primer_Studying project.
// This program is called:window_mgr.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_WINDOW_MGR_HPP
#define CPP_PRIMER_STUDYING_WINDOW_MGR_HPP

/**
 * @title
 * 窗口管理器
 */

#include <vector>

#include "screen.hpp"

class Window_manager {
 private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif  // CPP_PRIMER_STUDYING_WINDOW_MGR_HPP
