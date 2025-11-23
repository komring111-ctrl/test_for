#include<stdio.h>
#include<stdlb.h>
double evenumber(int n);
double oddnumber(int n);
int main()
{
    int n;
    double r;
    double (*pfunc)(int);//pfunc 是一个指针，指向“参数为 int、返回值为 double”的函数。
    printf("请输入一个数字: ");
    scanf("%d",&n);
    if(n%2==0){
        pfunc=evenumber;
    }
    else {
        pfunc=oddnumber;
    }
    r=(*pfunc)(n);
    printf("%lf\n",r)
    system("pause");
    return 0;
}
double evenumber(int n);
{
    double s=0,a=0;
    int i;
    for(i=2;i<=n;i+=2)
    {
        a=(double)1/i;
        s+=a;
    }
    return s;
}
double oddnumber(int n)
{
    double s=0,a=0;
    int i;
    for(i=1;i<=n;i+=2)
    {
        a=(double)1/i;
        s+=a;
    }
    return s;
}