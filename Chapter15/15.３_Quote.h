#include<stdio.h>
#include<iostream>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}

    std::string isbn() const{
        return bookNo;
    }

    virtual std::ostream& deBug(std::ostream &os) const {
        os<<"BookNO :"<< bookNo<<std::endl;
        os<<"price "<<price<<std::endl;
    }

    virtual double net_price(std::size_t n) const{  //返回相应的折扣
        return n*price;
    }
    virtual ~Quote() = default;//析构函数一般需要定义成虚函数

protected:
    std::size_t price;

private:
    std::string bookNo;//返回书编号

};


//Disc_quote继承Quote
class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book,double price,std::size_t qty,std::size_t uty_,double disc):
        Quote(book,price),quantity(qty),discount(disc),uty(uty_){}

    double net_price(std::size_t) const = 0;//纯虚函数 不能实例化

    std::ostream &deBug(std::ostream &os) const override{
        os<<Quote::deBug(os);
        os<<"quantity   "<<quantity<<std::endl;
        os<<"discount  "<<discount<<std::endl;
        os<<"uty  "<<uty<<std::endl;
    }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
    std::size_t uty = 0;
};

class Bulk_quote:public Disc_quote{
public:
    /*Bulk_quote() = default;
    Bulk_quote(const std::string &book,double sales_price,std::size_t qty,std::size_t uty,double dc):Disc_quote(book,sales_price,qty,uty,dc){}*/
    using Disc_quote::Disc_quote;
    double net_price(std::size_t ) const override;

    std::ostream &deBug(std::ostream &os) const override{
        os<<Disc_quote::deBug(os);
    }

private:

};


double  Bulk_quote::net_price(size_t cnt) const{
    if(cnt>=quantity&&cnt<=uty){
        return cnt * (1-discount)*price;
    }
    else
        return cnt *price;
}
