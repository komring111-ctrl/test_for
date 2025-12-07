/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i=digitsSize-1;i>=0;--i){
        if(digits[i]<9){
            digits[i]+=1;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    int* res =malloc((digitsSize+1)*sizeof(int));
    res[0]=1;
    for(int i=1;i<digitsSize+1;++i){
        res[i]=0;
    }
    *returnSize=digitsSize+1;
    return res;
}
int main(){
    int digits[]={9,9,9};
    int returnSize;
    int* ans=plusOne(digits,sizeof(digits)/sizeof(digits[0]),&returnSize);
    printf("Result: ");
    for(int i=0;i<returnSize;++i){
        printf("%d",ans[i]);
    }
    printf("\nLength: %d\n",returnSize);
    free(ans);
    return 0;
}