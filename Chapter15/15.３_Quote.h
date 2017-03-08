#include<stdio.h>
#include<iostream>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}

    std::string isbn() const{
        return bookNo;
    }

    virtual double net_price(std::size_t n) const{  //返回相应的折扣
        return n*price;
    }
    virtual ~Quote() = default;//析构函数一般需要定义成虚函数

private:
    std::string bookNo;//返回书编号

protected:
    double price = 0.0;
};


class Bulk_quote:public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book,double sales_price,std::size_t qty,std::size_t uty,double dc):Quote(book,sales_price),min_qty(qty),max_qty(uty),discount(dc){}

    double net_price(std::size_t ) const override;

private:
    std::size_t min_qty = 0;//最小折扣数量
    std::size_t max_qty =0;
    double discount = 0;//折扣数量

};


double Bulk_quote::net_price(size_t cnt) const{
    if(cnt>=min_qty&&cnt<=max_qty){
        return cnt * (1-discount)*price;
    }
    else
        return cnt *price;
}
