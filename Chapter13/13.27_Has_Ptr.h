#include<stdio.h>
#include<iostream>
#include<fstream>
#include<ostream>


class HasPtr{
    friend void swap(HasPtr &,HasPtr &);
    friend std::ostream& operator<<(HasPtr &,std::ostream &);
    friend bool operator<(const HasPtr&,const HasPtr&);
public:
    /**
        构造函数
    */
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)),i(0),use(new std::size_t(1)){
            std::cout<<"执行没有实参的构造函数"<<std::endl;
        }
    HasPtr(int i_,const std::string &s=std::string()):
        ps(new std::string(s)),i(i_),use(new std::size_t(1)){
             std::cout<<"执行实参的构造函数"<<std::endl;
        }

        HasPtr(const HasPtr &p){
            std::cout<<"调用拷贝构造函数"<<std::endl;
            use = &(++(*p.use));
            ps = p.ps;
            i = p.i;
        }

        /**
            拷贝操作
        */
        HasPtr& operator=(const HasPtr&);

        /**
            定制操作
        */


        /**
            析构函数
        */
        ~HasPtr(){
        if(--*use==0){
            delete ps;
            delete use;
    }}


private:
        std::string *ps;
        int i;
        std::size_t *use;
};


 HasPtr& HasPtr::operator=(const HasPtr& p)
{
            std::cout<<*p.use<<" == "<<std::endl;
            ++(*p.use);
            //std::cout<<*p.use<<std::endl;
            if(--*use==0){
                delete ps;
                delete use;
            }
            ps = p.ps;
            use = p.use;
            i= p.i;
            return *this;
        }

/**
    以下是HasPtr的定制操作
*/
std::ostream & operator<<(HasPtr &h1,std::ostream &os){
    os<<*(h1.ps)<<"   "<<h1.i;
    return os;
}

bool operator<(const HasPtr &h1,const HasPtr &h2){
    return h1.i<h2.i;
}

/**
    自定义swap操作
*/
inline void swap(HasPtr &h1,HasPtr &h2){

    using std::swap;
    std::cout<<"执行swap"<<std::endl;
    swap(h1.ps,h2.ps);
    swap(h1.i,h2.i);
}
