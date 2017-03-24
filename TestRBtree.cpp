#include<stdio.h>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int a=2;
     int *const b = &a;//*在const左侧，指针内容不可遍 const 右侧 指针不可遍
     cout<<a<<endl;
     *b = 3;
    cout<<*b<<endl;
    /*set<int>  st= {1,2,3,4,5,7,8,9};
    for(auto it = st.begin();;++it){
        cout<<*it<<"  ";
    }*/
    return 0;
}
