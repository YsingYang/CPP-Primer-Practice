#include<stdio.h>
#include<iostream>
#include<string>
#include"/home/ysing/codeblock Projects/CPP_prime/Chapter7/Screen.h"

using std::string;using std::cin;using std::cout;using std::endl;

int main(){
    Window_mgr wm = Window_mgr();

    wm.Screens[0].set('#').display(std::cout);
    wm.clear(0);
    wm.Screens[0].display(std::cout);
    return 0;
}
