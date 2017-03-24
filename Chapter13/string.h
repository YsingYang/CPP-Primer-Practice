#include<memory>
#include<iostream>
#include<algorithm>

class String{
    friend std::ostream &operator<<(std::ostream &os,const String &s);
public:
    /**
        拷贝操作与复制运算
    */
    String():String(""){}
    String(const char* s){
        //强制转换
        char *sl = const_cast<char *>(s);
        while(*sl){
            ++sl;
        }
        range_initializer(s,sl);
    }


    String(const String &s){
        range_initializer(s.element,s.first_free);
        std::cout<<"copy constructor"<<std::endl;
    }
    String & operator=(const String& s){
        auto newstr = alloc_n_copy(s.element,s.first_free);
        free();//记得释放掉旧空间
        element = newstr.first;
        first_free = newstr.second;
        std::cout<<"copy - assignment "<<std::endl;
        return *this;
    }
    const char *c_str() const{
        return element;
    }
    size_t size() const{
        return first_free - element;
    }

    size_t length() const{
        return first_free - element -1;
    }
    /**
        析构函数
    */
    virtual ~String(){
        //std::cout<<"zhixing"<<std::endl;
        free();
    }

private:
    std::pair<char*,char*> alloc_n_copy(const char *b ,const char *e){
        auto str = alloc.allocate(e-b);
        return {str,std::uninitialized_copy(b,e,str)};//copy到目标内存
    }

    void range_initializer(const char* b,const char* e){
        auto newstr = alloc_n_copy(b,e);//返回pair类型
        element = newstr.first;
        first_free = newstr.second;
    }

    void free(){
        if(element){
            std::for_each(element,first_free,[this](char &c){
                          alloc.destroy(&c);//记得是c的引用
            });
            alloc.deallocate(element,first_free-element);
        }
    }

private:
    char *element;
    char *first_free;
    std::allocator<char> alloc;
};


std::ostream &operator<<(std::ostream &os,const String &s){
    char *tmp = s.element;
    while(tmp!=s.first_free){
        os<<*tmp++;
    }
    return os;
}
