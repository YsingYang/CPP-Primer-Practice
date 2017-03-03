#include<stdio.h>
#include<iostream>
#include<memory>
#include<vector>

using namespace std;

//shared_ptr<vector<int>> factory();
void input(shared_ptr<vector<int>> sp);

shared_ptr<vector<int>> factory(){
    return make_shared<vector<int>> ();
}

void output(shared_ptr<vector<int>> sp){
    for(int i=0;i<10;++i){
        cout<<(*sp)[i]<<"   ";
    }
    cout<<endl;
}

int main(){
    shared_ptr<vector<int>> sp = factory();
    input(sp);//不能使用引用传值了？
    output(sp);
    return 0;
}

void input(shared_ptr<vector<int>> sp){//这个不用传引用也可以改变其值，可能主要是它本身就是一个指针的缘故
    for(int i=0;i<10;++i){
        (*sp).push_back(i);
    }
}
