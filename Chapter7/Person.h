#include<stdio.h>
#include<iostream>

class Person {
    std::string Person_name;
    std::string address;
    friend std::istream &read(std::istream &is,Person &ps);
    friend std::ostream &print(std::ostream &os,const Person &ps);
public:
    Person() = default;

    Person(const std::string name,const std::string add):Person_name(name),address(add) {};

    std::string const get_name() const {
        return Person_name;
    }
    std::string const get_address() const {
        return address;
    }

    void const set_name(std::string &name) {
        this->Person_name = name;
    }

    void const set_address(std::string &address) {
        this->address = address;
    }
};
std::ostream &print(std::ostream &os,const Person &ps);//declaration
std::ostream &print(std::ostream &os,const Person &ps);

std::istream &read(std::istream &is,Person &ps) {
    is>>ps.Person_name>>ps.address;
    return is;
}

std::ostream &print(std::ostream &os,const Person &ps) {
    os<<ps.get_name()<<ps.address;
    return os;
}

