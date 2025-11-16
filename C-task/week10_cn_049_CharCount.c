#include<stdio.h>
#include<stdlib.h>
int length(char *s);
int main()
{
    char str[100];
    printf("请输入字符串:\n");
    scanf("%s",str);
    int len=length(str);
    printf("字符串有%d个字符。\n",len);
    return EXTI_SUCCESS;
}
int length(char *s){
    int i=0;
    while(*s != '\0'){
        i++;
        s++;
    }
    return i;
}