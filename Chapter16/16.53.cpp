#include<stdio.h>
#include<iostream>
#include<ostream>

using namespace std;

template<typename T>
ostream &print(ostream &os,const T&t){
    return os<<t;
}

template<typename T,typename ...Args>
ostream &print(ostream &os,const T&t,const Args &...args){
    os<<t<<" ,";
    return print(os,args...);
}

int main(){
    int i=1;
    string s = "123";
    print(cout,i,s,42)<<endl;
    return 0;
}
