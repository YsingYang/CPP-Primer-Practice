#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;

template<typename Sequence>
inline std::ostream& println(Sequence const&seq){
    for(auto const &elem:seq){
        cout<<elem<<"  ";
    }
    cout<<endl;
    return cout;
}

inline bool isshorter(string const &s1,string const &s2){
    return s1.size()<s2.size();
}

void elistring(std::vector<string> &vs){
    std::sort(vs.begin(),vs.end());
    auto endIt = std::unique(vs.begin(),vs.end());
    vs.erase(endIt,vs.end());
}


int main(){
    std::vector<string> vs{"1234", "1234", "1234", "Hi", "alan", "wang"};
    elistring(vs);
    std::stable_sort(vs.begin(),vs.end(),isshorter);
    println(vs);
    return 0;
}
