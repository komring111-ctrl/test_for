#include<stdio.h>
int main(int agrc,char*agrv[])
{
    long sum=4,s=4;
    int j;
    for(j=2;j<=8;j++)
    {
        printf("%d位数为奇数的个数%ld\n",j-1,s);
        if(j<=2){
            s*=7;
        }else{
            s*=8;
        }
        sum+=s;
    }
    printf("%d位数为奇数的个数%ld\n",j-1,s);
    printf("奇数的总个数为：%ld\n",sum);
    return 0;
}



// #include<stdio.h>
// #include<stdlib>
// int main(){
//     int p,i;
//     long int sum=9;
//     printf("请输入一个素数:\n");
//     scanf("%d",&p);
//     for(i=1;;i++)
//     {
//         if(sum%p==0)break;
//         else sum=sum*10+9;
//     }
//     printf("素数%d能被%d个9组成的数%ld整除",p,i,sum);
//     return 0;
// }