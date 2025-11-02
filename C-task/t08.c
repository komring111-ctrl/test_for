//输入实型数据a,b，然后输出a、b的值。
#include<stdio.h>
int main(void){
    double number1,number2;
    printf("please input two numbers:");
    scanf("%lf,%lf",&number1,&number2);
    printf("Output:\n");
    printf("a=%f,b=%f\n",number1,number2);
    return 0;
}