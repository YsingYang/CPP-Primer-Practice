#include<stdio.h>
#include<memory>
#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>
#include <sstream>
#include<fstream>
#include<set>
#include<istream>
#include<ostream>
#include<algorithm>
using std::ifstream;
using std::cin;using std::cout;using std::endl;
using std::string;using std::unordered_set;
using std::vector;using std::shared_ptr;
using std::map;using std::ostream;
using std::set;

std::ostream &  Searchresult(const string&s,ostream &,map<string,shared_ptr<std::set<unsigned int>>> &mp, shared_ptr<vector<string>> file);

int main(){
    ifstream is("/home/ysing/codeblock Projects/CPP_prime/Chapter12/data",std::ios::in);
   std::map<string,shared_ptr<std::set<unsigned int>>> mp;
 shared_ptr<vector<string>> file(new vector<string> ());
    //file  = std::make_shared<vector<string>>();
    string line;
    int line_size =0;
    while(getline(is,line)){
            file->push_back(line);
            line_size = file->size()-1;
            std::istringstream iss(line);
            string word;
            while(iss>>word){
                auto &point = mp[word];//因为是只能指针，不一定有域存在里面
                if(!point)
                    point.reset(new set<unsigned int>);
                  point->insert(line_size);
            }
    }

    while(true){
        cout<<"Please Input which word you want to search , if you want to quit input 'p'";
        string s;
        if(cin>>s&&s!="p"){
             if(mp.find(s)==mp.end())
                    cout<<"no data "<<endl;
            else{
                Searchresult(s,cout,mp,file)<<endl;
            }
        }
    }
    return 0;
}


std::ostream &  Searchresult(const string&s,ostream &os,map<string,shared_ptr<std::set<unsigned int>>> &mp, shared_ptr<vector<string>> &file){
    if(mp.find(s)==mp.end())
        os<<"no data "<<endl;
    else{
        for(auto it : *mp[s]){
            os<<(*file)[it]<<"   in line  "<<it<<endl;
        }
    }
    return os;
}

