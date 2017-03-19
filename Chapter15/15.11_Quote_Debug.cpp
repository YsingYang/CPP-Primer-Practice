#include<stdio.h>
#include<iostream>
#include"/home/ysing/codeblock Projects/CPP_prime/Chapter15/15.３_Quote.h"

using namespace std;

int main(){

    class Quote *qt =new  Bulk_quote("12345",10.0,10,20,0.5);//动态绑定
    Quote *q = new Quote("1234",20.0);
    Disc_quote ds = Disc_quote();
    q->deBug(cout)<<endl;
    qt->deBug(cout)<<endl;
    delete(q);
    delete(qt);
}
