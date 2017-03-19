#include<stdio.h>
#include<iostream>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter13/13.27_Has_Ptr.h>
#include<algorithm>
#include<vector>

using std::vector;

int main(){
  /*  HasPtr *h1 = new HasPtr(1);
    HasPtr *h2 = new HasPtr(2);
    *h1<<std::cout<<std::endl;//注意重载了<<操作后，输出的形式有点奇怪
    *h2<<std::cout<<std::endl;


    swap(*h1,*h2);
    *h1<<std::cout<<std::endl;
    *h2<<std::cout<<std::endl;
    delete h1;
    delete h2;*/

    vector<HasPtr> vc;
    for(int i=0;i<10;++i){
        vc.push_back(HasPtr(10-i));
    }
    sort(vc.begin(),vc.end());
    for(int i=0;i<10;++i){
        vc[i]<<std::cout<<"   ";
    }

    return 0;
}
