#include<stdio.h>
#include<iostream>
#include<list>
#include<algorithm>
#include<ostream>

using namespace std;

int main(){
    list<int>  ls = {1,1,3,4,5,1,2,3,4};
    ls.unique();//只删除连续相同的数字;
    ostream &os = cout;//注意ostream的初始化写法
    for_each(ls.begin(),ls.end(),[&os](const int &i){
        os<<to_string(i)<<"   ";
    });
    return 0;
}
