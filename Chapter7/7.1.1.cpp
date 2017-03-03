#include <iostream>
#include <string>
#include<fstream>
#include"/home/ysing/codeblock Projects/CPP_prime/Chapter7/Sales_Data.h"

using std::cin; using std::cout; using std::endl; using std::string;

Sales_data* Sales_data::combination(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return this;
}
int main()
{
    Sales_data  trans   = Sales_data("123",0);
    print(cout,trans)<<endl;
    //print(cout,total)<<endl;

    return 0;
}
