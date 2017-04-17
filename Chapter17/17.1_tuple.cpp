#include<stdio.h>
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

int main(){

        tuple<int,int,int> tp(10,20,30);

        typedef decltype(tp) trans;

        tuple<string ,vector<string>,pair<string,int>> tp2;

        cout<<tuple_size<decltype(tp)>::value<<endl;///需要用decltype获取到tuple类型


        ///tuple_element<1,decltype(tp)>::type  用于获取某个参数的类型
        cout<<get<1>(tp)<<endl;

        return 0;

}
