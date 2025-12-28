#include <stdio.h>
#include <stdbool.h>
bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;
    while (n % 3 == 0)
        n /= 3;
    if (n == 1)
        return true;
    else
        return false;
}
int main(void){
    int x;
    printf("Input an integer: ");
    if(scanf("%d",&x)==1){
        printf("%d %s a power of three.\n",x,isPowerOfThree(x)?"is":"is NOT");
    }
    return 0;
}