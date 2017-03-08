#include<stdio.h>
#include<iostream>


class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)),i(0),use(new std::size_t(1)){}

        HasPtr(const HasPtr &p){
            use = &(++(*p.use));
            ps = p.ps;
            i = p.i;
        }

        HasPtr& operator=(const HasPtr&);

        ~HasPtr(){
        if(--*use==0){
            delete ps;
            delete use;
    }}
        std::string *ps;
        int i;
        std::size_t *use;
};


 HasPtr& HasPtr::operator=(const HasPtr& p)
{
            std::cout<<*p.use<<" == "<<std::endl;
            ++(*p.use);
            std::cout<<*p.use<<std::endl;
            if(--*use==0){
                delete ps;
                delete use;
            }
            ps = p.ps;
            use = p.use;
            i= p.i;
            return *this;
        }
