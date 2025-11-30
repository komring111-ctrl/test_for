#include<stdio.h>
int main()
{
    int a,i,aa[4],t;
    printf("请输入四位数字: ");
    scanf("%d",&a);
    aa[0]=a%10;//个
    aa[1]=a%100/10;//十
    aa[2]=a%1000/100;//百
    aa[3]=a/1000;//千
    for(i=0;i<=3;i++)
    {
        aa[i]+=5;
        aa[i]%=10;
    }
    for(i=0;i<=3;i++)
    {
        t=aa[i];
        aa[i]=aa[3-i];
        aa[3-i]=t;
    }
    prinntf("加密后的数字是: ");
    for(i=3;i>=0;i--)
    {
        printf("%d",aa[i]);
    }
    printf("\n");
    return 0;
}