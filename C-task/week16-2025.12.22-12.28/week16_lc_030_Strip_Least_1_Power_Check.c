#include <stdio.h>
#include <stdbool.h>
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    int after = n & (n - 1);
    if (after == 0)
        return true;
    else
        return false;
}
int main(){
    int n;
    printf("请输入一个整数: ");
    if(scanf("%d",&n)==1){
        printf("%d是2的幂吗?  %s\n",n,isPowerOfTwo(n)?"true":"false");
    }else{
        printf("输入格式错误!\n");
    }
    return 0;
}