#include<stdio.h>
#include<vector>
#include<iostream>
#include<set>

using namespace std;

template<typename T>
constexpr unsigned ReturnSize(T &arr){
    return arr.size();
}

int main(){
    set<int> tmp = {1,2,3,4,5};
    cout<<ReturnSize(tmp)<<endl;
    return 0;

}
