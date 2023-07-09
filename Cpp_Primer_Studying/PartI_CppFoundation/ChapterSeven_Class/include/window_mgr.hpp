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
 public:
    typedef std::vector<Screen>::size_type screen_index; /* 窗口中每个屏幕的编号 */

 public:
    void Clear(screen_index); /* 将指定屏幕内容清除 */

 private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_manager::Clear(Window_manager::screen_index index) {
    Screen &screen   = Window_manager::screens[index];
    screen._contents = std::string(screen._height * screen._width, ' ');
}

#endif  // CPP_PRIMER_STUDYING_WINDOW_MGR_HPP
