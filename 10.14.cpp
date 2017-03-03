#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int i1 = 3,i2 = 4;
    auto add = [](int &i1,int &i2) {
        return i1+i2;
    };
    return 0;
}
