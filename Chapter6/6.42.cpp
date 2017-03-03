#include<stdio.h>
#include<iostream>

using namespace std;

string ending = "s";
string make_plural(size_t ctr,const string &words,string =ending){
    return (ctr>1)?words + ending:words;
}

int main(){
        string words = "apple";
        ending = "es";
        cout<<make_plural(2,words);
        return 0;
}
