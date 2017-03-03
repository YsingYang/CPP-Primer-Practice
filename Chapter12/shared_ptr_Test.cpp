#include<memory>
#include<stdio.h>
#include<iostream>

using namespace std;

template<typename T>
shared_ptr<T> factory(T);


int main(){
    shared_ptr<int> p = factory(42);//如果p指向q之后 就释放了？那么也就不存在了？
    shared_ptr<int> q = factory(24);
    p = q;
    cout<<*p<<endl;
    return 0;
}

template<typename T>
shared_ptr<T> factory(T s){
    return make_shared<T>(s);
}
