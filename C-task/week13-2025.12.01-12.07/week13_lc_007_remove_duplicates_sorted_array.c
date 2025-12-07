#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    int k=1;
    for(int i=1;i<numsSize;++i){
        if(nums[i]!=nums[i-1]){
            nums[k++]=nums[i];
        }
    }
    return k;
}
int main(){
    int nums[]={2,2,5,5,7};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int k=removeDuplicates(int* nums, int numsSize);
    printf("k=%d\n",k);
    printf("nums front k elements: ");
    for(int i=0;i<k;++i){
        printf("%d",nums[i]);
    }
    puts("");
    return 0;
}