#include<stdio.h>
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename it>
const std::ostream &println(it const &first,it const &ed){
    for(auto i = first;i!=ed;++i){
            cout<<*i<<"   ";
    }
    cout<<endl;
    return cout;
}

bool largeThan5(string const &s){
    return s.size()<5;
}

int main(){
    vector<string> vs = {"123asd4", "123asd4", "123xcv4", "Hi", "alan", "wang"};
    auto it = partition(vs.begin(),vs.end(),largeThan5);
    println(it,vs.end());
    return 0;
}
