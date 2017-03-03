#include<stdio.h>
#include<iostream>
#include<memory>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter12/TextQuery.h>
using namespace std;
#define N 5

int main(){
    allocator<string> alloc;
    auto const  p = alloc.allocate(5);
    auto q = p;
    string s;
    int count=0;
    while(q!=p+N){
        alloc.construct(q++,"as");
        count++;
    }
    while(q!=p){//注意q是指向尾指针的.
        cout<<*(--q)<<endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p,N);
    return 0;
}

