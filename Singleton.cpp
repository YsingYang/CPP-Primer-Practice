#include<stdio.h>
#include<iostream>
#include<semaphore.h>

using namespace std;

sem_t mutex;

class singleton{
private:
    static singleton *instance;
    singleton(){
        cout<<"执行构造函数"<<endl;
    }
public:

    static singleton * getIntance();

    ~singleton(){
        cout<<"调用析构函数\n"<<endl;///果然会不断调用析构函数,所以需要加上一个判断语句
        if(instance==NULL)
            return;
        else{
            singleton *tmp = instance;
            instance = NULL;
            delete tmp;
        }
      //  delete instance;//这里会无限调用用？
    }
};

    singleton* singleton::instance = NULL;

    singleton* singleton::getIntance(){
        cout<<"执行构造"<<endl;
        sem_wait(&mutex);
        if(instance==NULL){
            instance = new singleton();
        }
        sem_post(&mutex);
        return instance;
    }

int main(){
    sem_init(&mutex,0,1);
    singleton *ist = singleton::getIntance();
    delete(ist);
    cout<<"执行"<<endl;
    return 0;
}
