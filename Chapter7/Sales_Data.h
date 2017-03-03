#include <iostream>
#include <string>
#include<fstream>

class Sales_data {
    friend std::istream &read(std::istream &is,Sales_data &item);
    friend std::ostream &print(std::ostream &os,const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);


public:
    Sales_data(std::string bn,unsigned us,double rv):bookNo(bn),units_sold(us),revenue(rv){};
    Sales_data(std::string No):bookNo(No) {};
    Sales_data(std::istream &is);
    //以下为委托构造函数
    Sales_data():Sales_data("",0,0){
        std::cout<<"执行委托构造函数"<<std::endl;
    };
    Sales_data(std::string bn,unsigned us):Sales_data(bn,us,0){
       std::cout<<"执行委托构造函数"<<std::endl;
    }


    std::string isbn() const {
        return bookNo;
    }

    Sales_data* combination(const Sales_data &);//如果该构造函数定义在外部，需要预先声明;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

std::istream &read(std::istream &is,Sales_data &item);
std::ostream &print(std::ostream &os,const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

Sales_data::Sales_data(std::istream &is) {
    std::istream &read(std::istream &is,Sales_data &item);
    read(is,*this);
}

std::istream &read(std::istream &is,Sales_data &item) {
    double price =0;
    is >> item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item) {
    os<<item.isbn()<<"  "<<item.units_sold<<" "<<item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combination(rhs);
    return sum;
}
