#include<stdio.h>
#include<iostream>

using namespace std;

class base{
public:
    base(){}
    virtual ~base(){
        cout<<"base:"<<endl;
    }
};

class derive1 :public base{
public:
    derive1(){}

    ~derive1() override{
        cout<<"derive"<<endl;
    }
};

class derive2 : public derive1{
public:
    derive2(){}

    ~derive2()  override{//基类为基函数，派生类不用声明是虚汗数也会是虚函数
        cout<<"derive2"<<endl;
    }
};

int main(){
    base *b1 = new base();
    base *d1 = new derive1();
    base *d2 = new derive2();
    delete b1;
    delete d1;
    delete(d2);


}
