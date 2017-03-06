#include<stdio.h>
#include<iostream>
#include<string>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter13/13.8.h>
using std::string;using std::cout;
using std::endl;




int main(){
    HasPtr   *hp1 = new HasPtr();
    HasPtr   *hp2 = new HasPtr(*hp1);
    hp2 = hp1;
    cout<<"finish";
    return 0;

}
