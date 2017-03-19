#include<stdio.h>
#include<iostream>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter15/15.３_Quote.h>
#include<vector>
#include<memory>
using std::cin;
using std::cout;using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

int main(){
    //Bulk_quote*bq = new Quote("ISNO-10",10.0);
    vector<shared_ptr<Quote>> basket;
    //Quote *qt = new Bulk_quote("ISNO-8",10,5,10,0.5);//这样子是可以构造的
    basket.push_back(make_shared<Bulk_quote>(Bulk_quote("ISNO-8",10,5,40,0.5)));
    basket.push_back(make_shared<Quote>(Quote("ISNB-8",10)));
    //cout<<qt->net_price(20)<<endl;
    //delete(qt);
    while(!basket.empty()){
        cout<<basket.back()->net_price(20)<<endl;
        basket.pop_back();
    }
    return 0;

    //Quote qt2 =Bulk_quote("ISNO-8",10,5,10,0.5);
    //cout<<qt2.net_price(20)<<endl;
}


