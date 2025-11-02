#include<stdio.h>
int main(){
    long a,b,c,d,e,x;
    printf("请输入5位数字: ");
    scanf("%ld",&x);
    a=x/10000;
    b=x%10000/1000;
    c=x%1000/100;
    d=x%100/10;
    e=x%10;
    if(a!=0){
        printf("为5位数,逆序为: %ld %ld %ld %ld %ld\n",e,d,c,b,a);
    }else if(b!=0){
        printf("为4位数,逆序为: %ld %ld %ld %ld\n",e,d,c,b);
    }else if(c!=0){
        printf("为3位数,逆序为: %ld %ld %ld\n",e,d,c);
    }else if(d!=0){
        printf("为2位数,逆序为: %ld %ld\n",e,d);
    }else if(e!=0){
        printf("为1位数,逆序为: %ld\n",e);
    }
}