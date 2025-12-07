int hammingWeight(int n) {
    int cnt=0;
    while(n){
        cnt+=n%2;
        n/=2;
    }
    return cnt;
}
#include<stdio.h>
int main(void){
    printf("%d\n",hammingWeight(11));
    printf("%d\n",hammingWeight(128));
    printf("%d\n",hammingWeight(2147483645));
    return 0;
}