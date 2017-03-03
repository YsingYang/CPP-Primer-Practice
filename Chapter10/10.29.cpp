#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>


using namespace std;

int main(){
    ifstream is("/home/ysing/codeblock Projects/CPP_prime/Chapter10/data");
    istream_iterator<int> it(is),eof;
    vector<int> res;
    while(it!=eof){
        res.push_back(*it++);
    }
    //cout<<res.size();
    sort(res.begin(),res.end());
    //copy(it,eof,res);
    ostream_iterator<int> outIt(cout," ");//必须是字符串
    copy(res.begin(),res.end(),outIt);
    cout<<endl;
    return 0;
}
