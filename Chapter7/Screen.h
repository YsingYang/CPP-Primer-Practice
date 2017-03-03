#include<stdio.h>
#include<iostream>
#include<vector>

class Window_mgr;

class Screen {
friend Window_mgr;
public:
    typedef std::string::size_type pos;//or the statement below  this statement;
    //using pos = std::string:;size_type;
    Screen() = default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c) {};

    char get() const {
        return contents[cursor];
    }

    inline char get(pos ht,pos wd) const;
    Screen &move (pos row,pos col);//这个引用的意义是?,否则返回的是对象的拷贝

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    Screen &set(char c);

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0,width = 0;
    std::string contents;

    void do_display(std::ostream &os) const {
        os<<contents;
    }
};

inline Screen &Screen::move(pos row,pos col) {
    pos r = row * width;
    cursor = r + col;
    return *this;//返回了自己，如果没有引用 ，重新拷贝一个对象吗？
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

char Screen::get(pos r,pos c) const {
    pos row = r *width;
    return contents[row+c];
}

class Window_mgr {
public:
    using ScreenIndex  = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    std::vector<Screen> Screens{Screen(24,80,' ')};
};


void Window_mgr::clear(ScreenIndex i){
    Screen &s = Screens[i];
    s.contents = std::string(s.height*s.width,' ');
}
