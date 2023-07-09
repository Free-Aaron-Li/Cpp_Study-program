// This file is part of Cpp_Primer_Studying project.
// This program is called:Screen.
// If there are no special instructions, this file is used as an exercise and test file.

// Copyright (C) 2023 Aaron
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#ifndef CPP_PRIMER_STUDYING_SCREEN_HPP
#define CPP_PRIMER_STUDYING_SCREEN_HPP

/**
 * @title
 * 显示器一个窗口
 */

#include <string>

class Screen {
 public:
    typedef std::string::size_type pos;

 public:
    Screen() = default;
    Screen(pos height, pos width) : _height(height), _width(width) {}
    Screen(pos height, pos width, char c) : _height(height), _width(width), _contents(height * width, c) {}

 public:
    char    get() const { return _contents[_cursor]; } /* 读取光标处的字符 */
    char    get(pos height, pos width) const;
    Screen& move(pos height, pos width);               /* 移动光标 */
    void    some_member() const;

 private:
    pos            _cursor = 0;     /* 光标位置 */
    pos            _height = 0, _width = 0;
    std::string    _contents;       /* 保存Screen内容 */
    mutable size_t _access_times{}; /* Screen的成员函数被调用次数 */
};

inline Screen& Screen::move(Screen::pos height, Screen::pos width) {
    pos row = height * _width;
    _cursor = row + width;
    return *this;
}

inline char Screen::get(Screen::pos height, Screen::pos width) const {
    Screen::pos row = height * _width;
    return _contents[row + width];
}

/* 记录成员函数被调用次数 */
inline void Screen::some_member() const { ++_access_times; }

#endif  // CPP_PRIMER_STUDYING_SCREEN_HPP
