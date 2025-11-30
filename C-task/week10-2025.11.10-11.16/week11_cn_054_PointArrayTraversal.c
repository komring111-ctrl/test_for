#include<stdio.h>
#include<stdlib.h>
int main(){
    const char *s[]={"man","woman","girl","boy","sister"};
    //这是“指针数组”——元素都是指针。
    //每个元素指向一个“字符串常量”，常量位于只读段，因此用 const 修饰，防止意外改写。
    //初始化列表让编译器自动把 5 个字符串首地址填进 s[0]~s[4]。
    const char **q;
    //q 保存的是“char * 变量的地址”，也就是“字符串地址的地址”。
    int k;
    for(k=0;k<5;k++){
        q=&s[k];
        printf("%s\n",*q);
    }
    return 0;
}