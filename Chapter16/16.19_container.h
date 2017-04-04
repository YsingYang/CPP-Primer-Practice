#include<stdio.h>
#include<iostream>

template<typename T>
std::ostream& print(T const &container,std::ostream &os){
    for(typename T::size_type i =0;i!=container.size();++i){///需要用typename 标记类型名
        os<<container[i]<<"   ";
    }
    return os;
}

template<typename T>
std::ostream& print2(T const &container,std::ostream &os){
    for(auto curr=container.begin();curr!=container.end();++curr){
        std::cout<<*curr<<"   ";
    }
    return os;
}


