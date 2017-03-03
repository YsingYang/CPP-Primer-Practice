#include<stdio.h>
#include<iostream>

class Y;
class X {
public:
    Y* point;
    X():point(nullptr) {};
};

class Y {
public:
    X x;
    Y() {
        x = X();
    }
};


