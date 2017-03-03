
#include<stdio.h>
#include<iostream>
#include <functional>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;

int main(){
    vector<int> vec = {1,1,1,1,1,2,2,2,23,3,3,3,3,34,4,4,4,4,5,5,5,6};
    list<int> res;
    unique_copy(vec.begin(),vec.end(),inserter(res,res.end()));
    for(auto i : res){
        cout<<i<<"    ";

    }
    return 0;
}
