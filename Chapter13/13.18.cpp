
#include </home/ysing/codeblock Projects/CPP_prime/Chapter13/13.18.h>
#include<stdio.h>


int main(){
    Employee *epe  = new Employee();
    std::cout<<epe->No;
    Employee *epe2  = new Employee();
    std::cout<<epe2->No;
    delete(epe2);
    delete(epe);
    return 0;
}
