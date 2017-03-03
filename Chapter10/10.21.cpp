#include <stdio.h>
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    int i = 10;
    auto f = [&](){
        --i;
    };
    auto g = [&](){
        return i>0;
    };

    while(g()){
        f();
    }
    cout<<i;
    return 0;

}
