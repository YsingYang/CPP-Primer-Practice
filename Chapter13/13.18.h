
#include<stdio.h>
#include<iostream>

class Employee{
public:
    Employee(){
        No = number++;
    }
    Employee(std::string &name){
        this->name  = name;
        No = number++;
    }

    Employee(const Employee &epe)= delete;
     /*   name = epe.name;
        No = number++;*/

    ~Employee() = default;

    std::string name;
    int No;
    static int number ;
};

int Employee::number = 0;
