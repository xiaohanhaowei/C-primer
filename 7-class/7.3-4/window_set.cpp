#include "window_set.h"

//定义处指定内联
inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

//内联函数在类的声明里已经显式声明
char Screen::get (pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

char Screen::get() const {
    return contents[cursor * height + width];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width+col] = ch;
    return *this;
}