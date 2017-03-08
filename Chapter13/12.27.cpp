#include"/home/ysing/codeblock Projects/CPP_prime/Chapter13/13.27_Has_Ptr.h"

using namespace std;

int main(){
       HasPtr  *hp = new HasPtr();
    HasPtr *hp2 = new HasPtr(*hp);
    cout<<*hp2->use<<endl;
    HasPtr hp3 = *hp;
    cout<<*hp2->use<<endl;
    hp3 = *hp;//这种情况下才会调用=号操作
    //cout<<hp3->use<<endl;
    cout<<*hp2->use<<endl;
    //hp = &hp3;
//    cout<<hp3->use<<endl;
    delete(hp2);
    cout<<*hp2->use<<endl;
    delete(hp);
    cout<<*hp2->use<<endl;
    //函数外释放hp3;
    //delete(hp3);
    return 0;
}

