#include<iostream>
#include<stdio.h>
#include</home/ysing/codeblock Projects/CPP_prime/Chapter13/13.13.h>
using namespace std;

int main(){
    //X x1 = X();//如果没有new  程序结束会会自动调用析构函数
    //X x2 = x1;//赋值也会在函数结束后调用析构函数


   /* X *x1 =new  X();//这样也算是赋值
    X x2 =*x1;//拷贝构造函数
    x2 = *x1;
    delete(x1);*/

    X *x1 = new X();
    X *x2 = new X();
    //delete x1;
    x1 = x2;
    delete(x1);//只是两个指针指向同一个对象，结束后x2也会自动释放。。但是会删除空悬指针*/


  /*  X *px = new X;
    f(*px, *px);//里面的参数都在函数结束后自动调用析构函数。
    cout<<"vec out"<<endl;
    delete px;*/

    return 0;
}
