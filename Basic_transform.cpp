#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;


int main(){
    char *p="abc";
    char *q="abc123";
    *p = 'b';///对字符常量赋值会报错
    /****
        char s1[] = "aaaaaaaaaaaaaaa";
        char *s2 = "bbbbbbbbbbbbbbbbb";
        aaaaaaaaaaa是在运行时刻赋值的；
        而bbbbbbbbbbb是在编译时就确定的；

    */
    printf("%s",p);
}
