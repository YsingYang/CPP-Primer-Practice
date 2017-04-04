#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class tp{
public:
    tp(T a_,T b_):a(a_),b(b_){}
    T a;
    T b;
};

int main(){
    tp<int>  tmp = tp<int>(1,3);
    tp<double> tmp2 = tp<double> (1.1,1.3);

}
