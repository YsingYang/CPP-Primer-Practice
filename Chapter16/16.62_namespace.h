#include<stdio.h>
#include<iostream>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter7/Sales_Data.h>

namespace std{
    template<>///定义特例化版本
    struct hash<Sales_data>{
        typedef size_t result_type;
        typedef Sales_data argument_type;


        size_t operator()(const Sales_data &s) const{
            return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
        }
    };
}
