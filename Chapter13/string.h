#include<memory>

class String{
public:
    /**
        拷贝操作与复制运算
    */
    String():String(""){}
    String(const char*);
    String(const string &);
    String & operator=(const String&);
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
    ~String();

private:
    std::pair<char*,char*> alloc_n_copy(const char*,const char *);
    void range_initializer(const char*,const char*);
    void free();

private:
    char *element;
    char *first_free;
    std::allocator<char> alloc;
};
