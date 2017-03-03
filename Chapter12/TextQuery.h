#include<stdio.h>
#include<memory>
#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>
#include <sstream>
#include<fstream>
#include<istream>
#include<ostream>
#include<algorithm>
using std::ifstream;
using std::cin;using std::cout;using std::endl;
using std::string;using std::unordered_set;
using std::vector;using std::shared_ptr;

class QueryResult;

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &is):file(new vector<string>){
        string text;
        while(getline(is,text)){
            file->push_back(text);
            int n = file->size()-1;
            std::istringstream line(text);
            string word;
            while(line>>word){
                     cout<<word<<endl;
                auto &lines  = mp[word];
                if(!lines){
                    lines .reset(new unordered_set<line_no>);
                }
                lines->insert(n);
                /*if(mp.find(word)==mp.end()){
                    mp[word] = shared_ptr<unordered_set<line_no>>();
                }
                mp[word].insert(n);为什么这里会报错，自动释放？*/
            }
        }
    }
    std::ostream &print(std::ostream &os,const QueryResult &qr);

    QueryResult query(const string &sought) const;

private:
    std::map<string,shared_ptr<unordered_set<line_no>>> mp;
    shared_ptr<vector<string>> file;
};


class QueryResult{
    friend::std::ostream& print(std::ostream &os,const QueryResult&);
    using line_no = vector<string>::size_type;
public:
    QueryResult(string s,shared_ptr<unordered_set<line_no>> p,shared_ptr<vector<string>> f):sought(s),lines(p),file(f){}

private:
    std::string sought;//查询单词
    std::shared_ptr<std::unordered_set<line_no>> lines;
    std::shared_ptr<vector<string>>file;//文本
};


void runQuery(ifstream &is){
    TextQuery tq(is);
    while(true){
        cout<<"enter word to look for,or q to quit";
        string s;
        if(!(cin>>s)||s=="q")
            break;
        print(cout,tq.query(s))<<endl;
    }
}

string make_plural(size_t ctr,const string &words,string ending){
    return (ctr>1)?words + ending:words;
}
//定义
QueryResult TextQuery::query(const string &sought) const {
        static shared_ptr<unordered_set<line_no>> nodata(new unordered_set<line_no>);
        if(mp.find(sought)==mp.end())
            return QueryResult(sought,nodata,file);
        else
            return QueryResult(sought,mp.find(sought)->second,file);//为什么mp用下表在这里会出错
    }

std::ostream &print(std::ostream &os,const QueryResult &qr){
        os<<qr.sought<<" occur "<<qr.lines->size()<<"  "<<make_plural(qr.lines->size(),"time","s")<<endl;
        for(auto num:*qr.lines){
            os<<"\t(line"<< num+1<<" )"<<*(qr.file->begin()+num)<<endl;
        }
        return os;
    }
