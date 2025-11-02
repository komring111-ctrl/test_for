#include<stdio.h>
int isPrimeNaive(int n)
{
    if(n<=1) return 0;
    for(int i=2;i<n;i++)
       if(n%i==0) return 0;
    return 1;
}
int main(void)
{
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    printf("%d is %s\n",n,isPrimeNaive(n)?"prime":"not prime");
    return 0;
}