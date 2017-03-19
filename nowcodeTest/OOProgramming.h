#include<stdio.h>
#include<iostream>
#include<unordered_map>

using namespace std;
class manager ;

class checkBook{
friend manager;
public:
    checkBook(){};
    checkBook(int length){
        book.reserve(length);
    }

    void setBook(int id,string time){
        book[id] = time;
    }
private://这个应该声明又私有类型，仅又管理员才能查看
    unordered_map<int,string>& getBook(){
        return book;
    }
private:
    unordered_map<int,string> book;
};
class checkBook;
class person{
public:
    person():id(0){}
    person(int id_):id(id_){}
    person(const person &) = default;

    virtual void setbook(checkBook &book){
        string time = "1234";
        book.setBook(id,time);
    }
    person &operator=(const person &p)  = default;
    virtual ~person() = default;

private:
    int id;
};

class manager : public person{
public:
    manager() = default;
    manager(int id_):person(id_){};
    ~manager()  = default;
    void check(checkBook & book_){
        unordered_map<int,string> book = book_.getBook();
        for(auto i:book){
            cout<<i.first<<"   "<<i.second<<endl;
        }
    }
};


