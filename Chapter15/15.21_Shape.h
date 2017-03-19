
#include<iostream>
#include<stdio.h>

class shape{//基类
public:
    typedef std::pair<double,double> coordinate;

    shape() = default;
    shape(std::string name_):name(name_){}

    virtual double area() const = 0;//计算面积函数 ,纯虚函数是函数后面标记 = 0

    virtual double perimeter() const  =0;//计算周长函数

    virtual ~shape() = default;

private:
    std::string name;

};


class Rectangle: public shape{
public:
        Rectangle() =  default;
        Rectangle(const std::string &name_,coordinate &c1,coordinate &c2,coordinate &c3,coordinate &c4):shape(name_),cd1(c1),cd2(c2),cd3(c3),cd4(c4)  {}
        /***
            注意shape(name_)这个构造函数，因为string  name对于Rectangle是不可见的，需要调用shape的构造函数
        ***/

        double area() const override{
                //返回面积,计算过程略
                return 0.0;
        }

        double perimeter() const override{
            return 0.0;
        }

        ~Rectangle()  = default;

private:
    coordinate cd1,cd2,cd3,cd4;
};

class Square    : public Rectangle{
public:

        /*
            constructor
        */
        Square() = default;
        Square(const std::string &name_,coordinate &c1,coordinate &c2,coordinate &c3,coordinate &c4):
            Rectangle(name_,c1,c2,c3,c4) {}

        double area() const override{
            return 1.0;
        }

        double perimeter() const override{
            return 1.0;
        }

        ~Square() = default;




};
