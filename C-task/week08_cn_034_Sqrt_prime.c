#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    int limit=(int)sqrt((double)n);
    for(int i=3;i<=limit;i+=2)
       if(n%i==0) return 0;
    return 1;
}
int main(void)
{
    int n;
    printf("Input n: ");
    scanf("%d is %s\n",n,isPrime(n) ? "prime":"not prime");
    return 0;
}