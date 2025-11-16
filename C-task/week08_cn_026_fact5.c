#include<stdio.h>
int factorial(int n);
int main(){
    for(int num=0;num<6;num++){
        printf("%d!=%d\n",num,factorial(num));
    }
    return 0;
}
int factorial(int n){
    int result;
    if(n==0){
        result=1;
    }else{
        result=n*factorial(n-1);
    }
    return result;
}