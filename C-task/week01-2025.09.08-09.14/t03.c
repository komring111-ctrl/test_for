//输入一个华氏温度，输出摄氏温度。
#include<stdio.h>
#include<math.h>
#define Pl 3.14159265358
int main(){
    float c,F;
    printf("Input F: ");
    scanf("%f",&F);
    printf("Output:\n");
    c=5.0/9.0*(F-32);
    printf("%.2f\n",c);
    return 0;
}