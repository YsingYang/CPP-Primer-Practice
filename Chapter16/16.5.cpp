#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>

using namespace std;
/*template<typename T>
void print(T &arr){
    for(auto &i:arr){
        cout<<i<<"   ";
        i = 0;
    }
}*/

template<typename T,unsigned N>
void printf(T  (&a)[N]){
    for(int i=0;i<N;++i){
        cout<<a[i]<<endl;
    }
}
int main(){
    float a[10] = {1,2,3,4,5,6,7,8,9,10};
    printf(a);
    return 0;
}
