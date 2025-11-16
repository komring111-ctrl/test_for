#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 1000000
static bool prime[MAX+1];
void buildSieve(void)
{
    for (int i=0;i<=MAX;i++) prime[i]=true;
    prime[0]=prime[1]=false;
    int limit=(int)sqrt((double)MAX);
    for(int p=2;p<=limit;++p)
       if(prime[p])
          for(int j=p*p;j<=MAX;j+=p)
             prime[j]=false;
}
int main(void)
{
    buildSieve();
    int n;
    printf("Input n(0<=n<=%d): ",MAX);
    scanf("%d",&n);
    printf("%d is %s\n",n,prime[n] ? "prime":"not prime");
    return 0;
}