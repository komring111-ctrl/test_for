#include<stdio.h>
#include<math.h>
int main(){
    int n=0;
    for(int i=2;i<=100;i++){
        int is_prime=1;
        int k=(int)sqrt(i);
        for(int j=2;j<=k;j++){
            if(i%j==0){
                is_prime=0;
                break;
            }
        }
        if(is_prime){
            printf("%d ",i);
            n++;
            if(n%5==0){
                printf("\n");
            }
        }
    }
    return 0;
}