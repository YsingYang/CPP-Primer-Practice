#include<iostream>
#include<stdio.h>
#include<vector>


struct X{
    X() {
        std::cout<< " X() "<< std::endl;
        }
    X(const X&){
        std::cout<<" X(const &x)"<<std::endl;
    }

    X& operator=(const X&x){
        val = x.val;
        std::cout<< "==" <<std::endl;
        return *this;
    }

    ~X(){
        std::cout<<"  ~X() "<<std::endl;
    }

int val;
};



void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
    std::cout<<"vec"<<std::endl
}
