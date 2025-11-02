//从键盘读入一个任意字符，输出该字符ASCII的十六进制值（小写）。
#include<stdio.h>
int main(void){
    char ch;
    printf("Input a character:");
    ch=getchar();
    printf("Output:%x\n",ch);
    return 0;
}