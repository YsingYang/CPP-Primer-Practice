#include<stdio.h>
#include<iostream>
#include <functional>
#include<algorithm>

using namespace std;
using namespace placeholders;

auto check(string const &str,int sz){
    return sz>str.size();
}

int main(){
    vector<int> vc= {1,2,3,4,5,6,7};
    string str = "12354";
    auto g = find_if(vc.begin(),vc.end(),bind(check,str,_1));//_1,_2为相应的需要的谓词数量
    if(g!=vc.end()){
        cout<<*g<<endl;
    }
    return 0;
}
