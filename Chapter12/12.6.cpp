#include<iostream>
#include<stdio.h>
#include<vector>

using std::vector;using std::cout;using std::endl;using std::cin;

void output(vector<int> *);//尾置const  隐藏 this

auto input(vector<int> &vc){//这里的指针就和引用不一样了
    int i=0;
    while(i<10){
        (vc).push_back(i);
        ++i;
    }
    return vc;
}

int main(){
    vector<int> *vc = new vector<int>();
    input(*vc);
    output(vc);
    delete(vc);
}


void output( vector<int> *vc){
    int i = 0;
    while(i<vc->size()){
        cout<<(*vc)[i]<<"  ";
        ++i;
    }
    cout<<endl;
}
