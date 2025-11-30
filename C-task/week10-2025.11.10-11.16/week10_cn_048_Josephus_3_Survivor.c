#include<stdio.h>
void main()
{
    int num[50],n,*p,j,loop,i,m,k;
    printf("请输入这一圈人的数量:\n");
    scanf("%d",&n);
    p=num;
    for(j=0;j<n;j++)
    {
        *(p+j)=j+1;
    }
    i=0;
    m=0;
    k=0;
    while(m<n-1)
    {
        if(*(p+i)!=0)
        {
            k++;
        }
        if(k==3)
        {
            k=0;
            *(p+i)=0;
            m++;
        }
        i++;
        if(i=n)
        {i=0;}
    }
    printf("现在剩下的人是:");
    for(loop=0;loop<n;loop++)
    {
        if(num[loop]!=0)
        {
            printf("%2d号\n",num[loop]);
        }
    }
}
// 1 2 3 4 5 
// 1 2 0 4 5
// 0 2 0 4 5
// 0 2 0 4 0
// 0 0 0 4 0