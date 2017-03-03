#include<memory>
#include<iostream>
#include<vector>
#include<stdio.h>
#include "/home/ysing/codeblock Projects/CPP_prime/Chapter12/12.2.h"
#include<initializer_list>

using namespace std;
int main(){
    StrBlob *sb = new StrBlob({"1,2,3,4"});
    cout<<sb->front()<<endl;
    sb->pop_back();
    cout<<sb->front()<<endl;
    return 0;
}
