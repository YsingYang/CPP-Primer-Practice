#include</home/ysing/codeblock Projects/CPP_prime/Chapter16/16.62_namespace.h>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<Sales_data,hash<Sales_data>> mp;
    mp.insert(Sales_data("123"));
    mp.insert(Sales_data("123"));
    for(auto i:mp){
        print(cout,i)<<endl;
    }
    return 0;
}
