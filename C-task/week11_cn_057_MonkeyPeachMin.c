#include<stdio.h>
int main(){
    int n=0;
    int i,count;
    int found=0;
    while(!found){
        n+=1;
        count=n;
        for(i=0;i<5;i++){
            if((count-1)%5==0){
                count=(count-1)/5*4;
            }else{
                break;
            }
        }
        if(i==5){
            found=1;
        }
    }
    printf("最少有%d个桃子。\n",n);
    return 0;
}