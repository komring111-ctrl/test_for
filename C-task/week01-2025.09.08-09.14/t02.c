//从键盘上输入一个四位整数，计算各个位上的数字之和。
// 编程可用素材：printf("Input a number with 4-digit: ")...、printf("Output:\nsum=...\n"...。
#include<stdio.h>
int main(void){
    int number;
    printf("Input a number with 4-digit: ");
    scanf("%d",number);
    printf("Output:\n");
    printf("sum=%d\n",sum=number/1000+number/100%10+number/10%10+number%10);
    return 0;
}