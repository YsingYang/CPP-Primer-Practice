#ifndef CP5_ex13_08_h
#define CP5_ex13_08_h
#include<string>

using std::string;

class HasPtr{
public:
    HasPtr(const std::string &s = string()):ps(new string(s)),i(0) {}//constructor

    HasPtr(HasPtr &hp){
        ps = new string(*hp.ps);
        i = hp.i;
    }//copy constructor

    HasPtr& operator=(const HasPtr& hp){
        if(this != &hp){
            string *tmp = new string(*hp.ps);
            delete(ps);
            ps = tmp;
            i = hp.i;
        }
        return *this;
    }//define = operation

    ~HasPtr(){
        delete(ps);
    }

private:
    string *ps;
    int i;
};





#endif // 13
