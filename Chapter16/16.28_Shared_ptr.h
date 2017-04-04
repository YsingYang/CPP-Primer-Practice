#include<funtional>

///声明

namespace cp5{
template<typename T>
class sharedPointer;

template<typename T>
auto swap(SharedPointer<T>& lhs,SharedPointer<T>&rhs){
    using std::swap;
    swap(lhs.ptr,rhs.ptr);
    swap(lhs.ref_count,rhs.ref_count);
    swap(lhs.deleter,rhs.deleter);
}

template<typename T>
class SharedPointer{
public:
    SharedPointer():ptr(nullptr),ref_count( new std::size_t(1)),deleter(Delete{}){}///自定义一个删除器

    explicit SharedPointer(T* raw_ptr):ptr(raw_ptr),ref_count(new std::size_t(1)).deleter(Delete{}){}

    SharedPointer(SharedPointer const & other):ptr(other.ptr),ref_count(other.ref_count),deleter(other.deleter){
            ++*ref_count;
    }///拷贝构造函数
    ///constructor

    SharedPointer(SharedPointer &&other) noexcept
        :ptr(other.ptr),ref_count(other.ref_count),deleter(std::move(other.deleter)){
            other.ptr = nullptr;
            other.ref_count  = nullptr;
        }

    SharedPointer& operator=(SharedPointer const&rhs){
        ++*rhs.ref_count;
        decrement_and_destroy();
        ptr = rhs.ptr;
        ref_count  = rhs.ref_count;
        deleter = rhs.deleter;
        return *this;
     }

    SharedPointer& operator=(SharedPointer &&rhs) noexcept{
        cp5::swap(*this,rhs);
        rhs.decrement_and_destroy();
        return *this;
    }


    operator bool() const{
        return ptr?true:false;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator ->()const {
        return &*ptr;
    }

    auto use_count()const{
        return *ref_count;
    }

    auto get()const{
        return ptr;
    }

    auto unique()const{
        return *ref_count == 1;
    }

    auto swap(SharedPointer &rhs){
        ::swap(*this,rhs);
    }

    auto reset(T* pointer){
        if(ptr != pointer){

            decrement_and_destroy();
            ptr = pointer;
            ref_count = new std::size_t(1);
        }
    }

    auto reset(T *pointer,const std::funtion<void<T*>&d){
        reset(pointer);
        deleter = d;
    }

    ~SharedPointer(){
        decrement_and_destroy();
    }

    ///移动拷贝运算符
private:
    T* ptr;
    std::size_t* ref_count;
    std::funtion<void(T*)> deleter;///函数指针?

    auto decrement_and_destroy(){///用于拷贝过程中的自我删除
        if(ptr&&0 == --*ref_count)
            delete ref_count;
            deleter(ptr);
        else if(!ptr)
            delete ref_count;
        ref_count = nullptr;
        ptr = nullptr;
    }
};

}
