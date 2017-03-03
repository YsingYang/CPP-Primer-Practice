#include<stdio.h>
#include<iostream>

using namespace std;

template<typename T> T compare(const T &a1,const T &a2){
    return a1>a2?1.0:-1.0;
}

int main(){
    int  a1 = 2,a2=3;
    double a3 = compare(a1,a2);//返回的应该是一个int类型;
    cout<<a3<<endl;
    return 0;


}
