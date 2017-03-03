#include<stdio.h>
#include<iostream>

using namespace std;

template<typename T>
inline const T &shortString(const T & s1,const T &s2){
    return s1.size()<s2.size()?s1:s2;
}

int main(){
    string s1 = "123123423",s2 = "asdqwdzx";
    cout<<shortString(s1,s2);
    return 0 ;
}
