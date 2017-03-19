#include<stdio.h>
#include<iostream>
#include"/home/ysing/codeblock Projects/CPP_prime/nowcodeTest/OOProgramming.h"

int main(){
    checkBook cb = checkBook();
    manager mg = manager(123);
    mg.setbook(cb);
    mg.check(cb);
    return 0;
}
