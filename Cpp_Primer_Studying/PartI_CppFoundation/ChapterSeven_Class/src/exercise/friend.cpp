// 可以通过命令 "g++ -o main -g friend.cpp”运行程序

// Copyright (c) 2023. aaron.
// This program is under the GPL-3.0 license,if you have not received it or the program has a bug,
// please let me know: <fly_aaron.li@outlook.com>.
#include <iostream>
#include <vector>
#include <string>

class Screen;

class Window_manager {
 public:
    typedef std::vector<Screen>::size_type screen_index; /* 窗口中每个屏幕的编号 */

 public:
    void Clear(screen_index); /* 将指定屏幕内容清除 */

 private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_manager::Clear(screen_index);

 public:
    typedef std::string::size_type pos;

 public:
    Screen() = default;
    Screen(pos height, pos width) : _height(height), _width(width) {}
    Screen(pos height, pos width, char character) :
        _height(height), _width(width), _contents(height * width, character) {}

 public:
    char          get() const { return _contents[_cursor]; } /* 读取光标处的字符 */
    char          get(pos height, pos width) const;
    Screen&       set(char character);
    Screen&       set(pos height, pos width, char character);
    Screen&       move(pos height, pos width); /* 移动光标 */
    void          some_member() const;
    Screen&       display(std::ostream& ostream);
    const Screen& display(std::ostream& ostream) const;

 private:
    void do_display(std::ostream& ostream) const { ostream << _contents; }

 private:
    pos            _cursor = 0;     /* 光标位置 */
    pos            _height = 0, _width = 0;
    std::string    _contents;       /* 保存Screen内容 */
    mutable size_t _access_times{}; /* Screen的成员函数被调用次数 */
};

inline char Screen::get(Screen::pos height, Screen::pos width) const {
    Screen::pos row = height * _width;
    return _contents[row + width];
}

inline Screen& Screen::set(char character) {
    _contents[_cursor] = character;
    return *this;
}

inline Screen& Screen::set(Screen::pos height, Screen::pos width, char character) {
    _contents[height * _width + width] = character;
    return *this;
}

inline Screen& Screen::move(Screen::pos height, Screen::pos width) {
    pos row = height * _width;
    _cursor = row + width;
    return *this;
}

/* 记录成员函数被调用次数 */
inline void Screen::some_member() const { ++_access_times; };

inline Screen& Screen::display(std::ostream& ostream) {
    do_display(ostream);
    return *this;
}

inline const Screen& Screen::display(std::ostream& ostream) const {
    do_display(ostream);
    return *this;
}

void Window_manager::Clear(Window_manager::screen_index index) {
    Screen &screen   = Window_manager::screens[index];
    screen._contents = std::string(screen._height * screen._width, ' ');
}

int main() {
    Screen my(5,5,'X');
    my.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    my.display(std::cout);
    std::cout << "\n";
    Window_manager test;
    test.Clear(0);
    my.display(std::cout);
}
