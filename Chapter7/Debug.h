#include<stdio.h>
#include<iostream>

class Debug{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b) {}//如果b不设置的话会不会出错
    constexpr Debug(bool h,bool i,bool o): hw(h),io(i),other(o){}
    constexpr bool any(){
        return hw||io||other;
    }

    void set_io(bool b){
        io = b;
    }

    void set_hw(bool b){
        hw = b;
    }

    void set_other(bool b){
        other = b;
    }
private:
    bool hw;
    bool io;
    bool other;
};
