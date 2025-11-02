#include<stdio.h>
void palin(int n);
int main(void){ 
    printf("请输入5个字符 : ");
    palin(5);
    printf("\n");
    return 0;
}
void palin(int n)
{
    char next;
    if(n<=1){
        next=getchar();
        printf("相反顺序输出结果 : ");
        putchar(next);
    }else{
        next=getchar();
        palin(n-1);
        putchar(next);
    }
}