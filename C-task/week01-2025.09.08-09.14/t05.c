//从键盘输入a,b,x,y的值，计算以下算术表达式的值：
//(double)(a+b)/2+(int)x%(int)y 
#include<stdio.h>
int main(){
    int a,b;
    double x,y,ans;
    printf("Input: ");
    scanf("%d%d%lf%lf",&a,&b,&x,&y);
    printf("Output:\n");
    ans=(double)(a+b)/2+(int)x%(int)y;
    printf("The ans is %f\n",ans);
    return 0;
}