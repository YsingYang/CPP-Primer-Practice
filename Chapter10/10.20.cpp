#include <stdio.h>
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

/*void testFunc(string const & s){
    s = "1234";//好像是因为传入的是一个常量指针还是传入指针指向的值是常量不可改变的区别
}*/


int main(){
    std::vector<string> vs{"1234asddas", "1234", "1234", "Hi", "alan", "wang"};
    int size = 6;
    int res = count_if(vs.begin(),vs.end(),[&](string const &s){
            return s.size()>6;
        });
    cout<<res<<endl;
    //string s = "1234124";
    //testFunc(s);
    return 0;
}


