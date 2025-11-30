#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length(char *s);
int main(void)
{
    char str[100];
    printf("请输入字符串（可含空格）:\n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int len = length(str);
    printf("字符串有%d个字符。\n",len);
    return EXIT_SUCCESS;
}
int length(char *s)
{
    int i=0;
    while(*s++) 
    i++;
    return i;
}