#include<stdio.h>
#include<iostream>
#include<vector>

template<typename  T>
int vectorCount(std::vector<T> &vec,const T s){
    int count = 0;
    for(auto it:vec){
        count += it==s;
    }
    return count;
}

template<>///偏特化实例
int vectorCount(std::vector<const char *>&vec,const char * s){///注意保证参数对象与T一一对应
    std::cout<<"执行偏特化版本模板"<<std::endl;
    int count = 0;
    for(auto it:vec){
        count += it==s;
    }
    return count;
}

