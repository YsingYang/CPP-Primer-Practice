#include<stdio.h>
#include<iostream>
#include<memory>
#include<utility>
#include<algorithm>
class StrVec{
public:
    /***
    构造函数
    */
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec &s){//copy constructor
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;//注意这里first_free = cap的
    }
    StrVec(std::initializer_list<std::string> l1){
        auto newdata = alloc_n_copy(l1.begin(), l1.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }
    /**
        析构函数
    */
    ~StrVec(){
        free();
    }
    /**
        拷贝操作
    */

    StrVec &operator=(const StrVec &s){
        auto data = alloc_n_copy(s.begin(),s.end());
        free();//注意这里先free掉
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    /**
        成员函数
    */
    void push_back(const std::string & s){
        std::cout<<"执行"<<std::endl;
        chk_n_alloc();
        alloc.construct(first_free++,s);
    }
    size_t size()const {
        return first_free - elements;
    }
    size_t capacity() const{
        return cap - elements;
    }
    std::string *begin() const{
        return elements;
    }

    std::string *end() const{
        return first_free;//这就是为什么 end指向最后一个元素后面的位置
    }



private:
    std::allocator<std::string> alloc;//分配元素

    void chk_n_alloc(){ //检查是否还有可用位置
        if(size()==capacity())
                reallocate();
    }

    std::pair<std::string *,std::string *> alloc_n_copy(const std::string *begin ,const std::string *end){
        auto data = alloc.allocate(end-begin);//传入的是两个指针
        return {data,uninitialized_copy(begin,end,data)};//拷贝到data中，
    }

    void free(){//逆序销毁元素
        if(elements){
            /*for(auto p = first_free;p!=elements;)
                alloc.destroy(--p);                                       //这里出了个bug....--p 写成了p--*/
                std::for_each(elements,first_free,[this](std::string &s){
                         alloc.destroy(&s);
                });
            alloc.deallocate(elements,cap-elements);//元素被删除完之后，释放内存空间
        }
    }



    void reallocate(){//重新分配更多内存
        auto newcapacity = size()? 2*size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;//指向新数组中下一个空闲位置
        auto elem = elements;//指向旧数组中下一个元素
        for(size_t i=0;i!=size();++i){
            alloc.construct(dest++,std::move(*elem++));
        }
        free();//move完，释放就空间
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;

    }

    std::string *elements;//第一个元素
    std::string * first_free;//第一个可用位置
    std::string *cap;//指向分配的内存最后位置
};


