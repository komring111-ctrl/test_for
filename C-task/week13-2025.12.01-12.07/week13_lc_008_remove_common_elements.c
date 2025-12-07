#include<stdio.h>
#include<stdlib.h>
int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    for(int i=0;i<numsSize;++i){
        if(nums[i]!=val){
            nums[k++]=nums[i];
        }
    }
    return k;
}
int cmp(const void* a,const void *b){
    return (*(int*)a-*(int*)b);//(int*)a 把 void 指针强转为 int 指针
                               //*(int*)a  解引用，拿到第一个整数
}
int main(){
    int nums[]={0,1,2,2,3,0,4,2};
    int val=2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k=removeElement(nums,numsSize,val);
    qsort(nums, k, sizeof(int), cmp);//把 nums 数组里前 k 个 int 型元素，用我们刚才写的 cmp 规则，从小到大重新排列
    printf("k=%d\n",k);
    printf("sorted front k elements: ");
    for(int i=0;i<k;++i){
        printf("%d",nums[i]);
    }
    puts("");
    return 0;
}