//从键盘输入一个值给变量a，计算进行如下赋值表达式计算之后a的值：
//a-=2 
#include<stdio.h>
int main(){
    int a;
    printf("Input:");
    scanf("%d",&a);
    printf("Output:\n");
    a-=2;
    printf("%d\n",a);
    return 0;
}