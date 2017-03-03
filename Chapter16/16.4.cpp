#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>

using namespace std;

template<typename T,typename N>
T MyFind(T bg,T ed,const N &val) {
        for(;bg!=ed;++bg){
            if(*bg==val){
                return bg;//
            }
        }
        return bg;//所以标准库返回的是迭代器
}


int main(){
    vector<int> v1= {1,2,3,4,5};
    list<string> l1 = {"asb","asd","bsda"};
    cout<<*MyFind(v1.begin(),v1.end(),6);
    cout<<*MyFind(l1.begin(),l1.end(),"asb");
    return 0;
}
