#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>

using namespace std;

int main(){
    ifstream ifs("/home/ysing/codeblock Projects/CPP_prime/Chapter10/data");
    ofstream of1("/home/ysing/codeblock Projects/CPP_prime/Chapter10/of1"),of2("/home/ysing/codeblock Projects/CPP_prime/Chapter10/of2");

    istream_iterator<int> in(ifs),eof;
    ostream_iterator<int> ofit(of1," "),ofit2(of2,"\n");
    for_each(in,eof,[&ofit,&ofit2](const int i){
       *( (i&1)==0? ofit:ofit2) ++ = i;
    });
}
