#include<stdio.h>
#include<iostream>

using namespace std;

template<typename ... Args>
void g(Args ... args){
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(args)<<endl;
}

int main(){
/*    int i =1;
    string  s = "123";
    double d = 1.1;
    g(i,s,d,42);
    return 0;*/

    int a = 3,b=2,c = 1;
    while(a!=b&&b!=c){
        int &maxval = move(max(a,max(b,c)));
        //maxval = move(max(a,max(b,c)));
        maxval /=2;
    }
}
