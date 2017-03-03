#include<stdio.h>
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int,int> match_map;
    match_map.insert({1,0});
    match_map.insert({1,1});
    cout<<match_map[1];
    return 1;
}
