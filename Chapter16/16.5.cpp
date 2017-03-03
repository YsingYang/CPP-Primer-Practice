#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>

using namespace std;
template<typename T>
void print(T &arr){
    for(auto &i:arr){
        cout<<i<<"   ";
        i = 0;
    }
}

int main(){
    vector<int>  a1= {1,2,3,4,5,6,7};
    print(a1);
    print(a1);
    return 0;
}
