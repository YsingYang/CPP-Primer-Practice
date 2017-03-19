#include <iostream>
#include <string>

#include</home/ysing/codeblock Projects/CPP_prime/Chapter15/15.３_Quote.h>

using namespace std;
int main()
{
    Bulk_quote bulk_quote("bulk_quote_1", 10.10, 4, 20,0.5);

    // The pointer is of static type Quote, but it's dynamic type is Bulk Quote
    // Because of polymorphism the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote *quote_pointer = &bulk_quote;//动态类型
    cout<<quote_pointer->net_price(5)<<endl;;

    // The reference is of static type Quote, but it's dynamic type is Bulk Quote
    // Like with the pointer, the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote &quote_reference = bulk_quote;//动态类型
    cout<<quote_reference.net_price(5)<<endl;;

    // The static type of this variable is Quote. Here the Bulk Quote object
    // gets upcasted. The Quote part of bulk_quote gets copied into quote, but
    // the rest is not handled. Because of the cast the Quote implementation of
    // the net_price() method gets called.
    Quote quote = bulk_quote;//静态类型
    cout<<quote.net_price(5)<<endl;

    return 0;
}


