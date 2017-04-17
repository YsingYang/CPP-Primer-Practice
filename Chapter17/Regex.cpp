#include<regex>
#include<stdio.h>
#include<boost/regex.hpp>
#include<boost/regex.h>

using namespace std;
using namespace boost;
int main(){
    string pattern("[^c]ei");
    pattern= "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    boost::regex r(pattern);
   // cout<<pattern<<endl;
    boost::smatch result;///一个迭代器？
    string testStr = "receipt freind theif receive";
    if(boost::regex_match(testStr,result,r)){
        cout<<"123"<<endl;
        cout<<result.str()<<endl;
    }
    return 0;
}
