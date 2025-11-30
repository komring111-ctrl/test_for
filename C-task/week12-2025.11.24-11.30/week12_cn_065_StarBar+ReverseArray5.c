#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,j,n;
    printf("请输入7个1-50的整数:\n");
    while(i<7)
    {
        scanf("%d",&n);
        if(n<1||n>50){
            printf("范围1-50,请重新输入:\n");
            continue;
        }
        for(j=0;j<n;j++){
            putchar('*');
        }
        putchar('\n');
        ++i;
    }
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #define M 5;
// int main()
// {
//     int a[M]={1,2,3,4,5};
//     int i,j,t;
//     i=0;
//     j=M-1;
//     while(i<j)
//     {
//         t=*(a+i);
//         *(a+i)=*(a+j);
//         *(a+j)=t;
//         i++;
//         j--;
//     }
//     for(i=0;i<M;i++){
//         printf("%d\n",*(a+i));
//     }
//     return 0;
// }