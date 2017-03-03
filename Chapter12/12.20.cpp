#include<stdio.h>
#include<iostream>
#include<memory>
#include<vector>
#include<fstream>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter12/12.2.h>
using namespace std;

int main(){
    ifstream of("/home/ysing/codeblock Projects/CPP_prime/Chapter12/StrBlobTest",ofstream::in);
    vector<string> str;
    string temp;
    StrBlob *sb = new StrBlob();
    while(getline(of,temp)){
        sb->push_back(temp);
    }
    for (strBlobPtr pbeg(sb->begin()), pend(sb->end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;

    delete(sb);
    return 0;
}
