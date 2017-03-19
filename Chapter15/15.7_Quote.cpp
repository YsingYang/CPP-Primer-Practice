#include<stdio.h>
#include<iostream>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter15/15.３_Quote.h>
#include<vector>
using std::cin;
using std::cout;using std::endl;

int main(){
    //Bulk_quote*bq = new Quote("ISNO-10",10.0);
    std::vector<shared_ptr<Quote>> basket;
    Quote *qt = new Bulk_quote("ISNO-8",10,5,10,0.5);//这样子是可以构造的
    cout<<qt->net_price(20)<<endl;
    delete(qt);


    Quote qt2 =Bulk_quote("ISNO-8",10,5,10,0.5);
    cout<<qt2.net_price(20)<<endl;
}

