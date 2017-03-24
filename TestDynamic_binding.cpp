#include<stdio.h>
#include<iostream>

using namespace std;


///基类
class B{
public:
    int i1,i2;
    virtual void fun1(){
        cout<<" 我是基类"<<endl;
    }
};

///派生类
class A:public B{
public:
    int j1,j2;
    /*void fun1()override{
        cout<<" 我是子类"<<endl;
    }*/
};

int main(){
    //A *a;
    //B *b =new  B();
    //a = static_cast<A*>(b);//statcic 与dynamic cast可以从基类转子类
    //a->fun1();
   //A *a = new A();
  //  B &b = static_cast<B&>(a);

    B *b = new B();
    A *a = dynamic_cast<A*>(b);///可以强制转换基类为子类
    //A *a =
    if(a==nullptr)
        cout<<"123123"<<endl;//会变成空指针
    a->fun1();//对于重载后的函数，dynamic_cast显然会更安全，因为如果转成空指针会位nullptr*/
    //a->i1;
    //else
        //a->fun1();
    //delete(b);
    //b.fun1();
    //b.j1;
    //delete(b);
    return 0;

}
