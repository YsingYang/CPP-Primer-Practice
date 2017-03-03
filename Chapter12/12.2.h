#include<memory>
#include<iostream>
#include<vector>
#include<stdio.h>
#include <stdexcept>
#include<string>
#include<initializer_list>

using std::string;
using std::vector;

class strBlobPtr;
class StrBlob{
friend class strBlobPtr;


public:
    strBlobPtr  begin();
    strBlobPtr end();

    typedef std::vector<std::string>::size_type size_type;

    StrBlob():data(std::make_shared<std::vector<std::string>>()){}//注意初始化的小括号
    //StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
    StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)) { }

    size_type size() const {
        return data->size();
    }

    bool empty()const {
        return data->empty();
    }

    void push_back(const std::string &s){
        data->push_back(s);
    }

    void pop_back();

    std::string &front () const;
    std::string &back ()  const;

private:
    //std::shared_ptr<std::vector<std::string>> data;
    std::shared_ptr<vector<string>> data;
    void check(size_type i,const std::string &msg) const;
};

void StrBlob::check(size_type i,const std::string &msg) const{
    if(i>=data->size()){
        throw std::out_of_range(msg);
    }
}


std::string & StrBlob::front() const {
    check(0,"front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() const{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}


class strBlobPtr{
public:
    bool operator!=(const strBlobPtr& p) { return p.curr != curr; }//操作定义
    strBlobPtr():curr(0){}
    strBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}
    string & deref() const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    strBlobPtr& incr(){
        check(curr,"curr in the end");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<vector<string>> check(std::size_t index ,const std::string &msg) const{
        auto ret = wptr.lock();
        if(!ret){
            throw std::runtime_error("out of bound");
        }
        if(index>=ret->size()){
            throw std::out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    std::size_t curr;
};


    strBlobPtr StrBlob::begin(){
        return strBlobPtr(*this);
    }
    strBlobPtr StrBlob::end()
    {
        return strBlobPtr(*this, data->size());
    }

