#include<stdio.h>
#include<iostream>
#include<memory>

using namespace std;

struct connection{
    string ip;
    int port;
    connection(string ip_,int port_):ip(ip_),port(port_){}
};

struct destination{
    string ip;
    int port;
    destination(string ip_,int port_):ip(ip_),port(port_){}
};

connection connect(destination *dst){
    shared_ptr<connection> spconn(new connection(dst->ip,dst->port));
    cout<<"createing connection   "<<spconn.use_count()<<endl;
    return *spconn;
}//返回一个解引用的对象

void disconnect(connection pConn){
    cout<<"  connection close "<<pConn.ip<<endl;
}

void end_connection(connection *pConn){
    disconnect(*pConn);
}

void f(destination &d){//传的引用
    connection conn =  connect(&d);//返回一个connect对象，但他并不是返回指针，只能只能内嵌在连接过程中
    shared_ptr<connection> p(&conn,[](connection *pConn){
                                cout<<"  connection close "<<pConn->ip<<endl;
                             });//指向conn，调用end_connection delete//这个只能指针好像离开了这个f函数就会自动--count 然后销毁对象
    cout<<"connecting now   "<<p.use_count()<<endl;
}

int main(){
    destination dest("202.118.176.67", 3316);
    f(dest);
}


