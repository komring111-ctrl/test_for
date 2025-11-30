#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums,int numsSize,int target,int* returnSize)
{
    int *ans=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    for(int i=0;i<numsSize-1;++i){
        for(int j=i+1;j<numsSize;++j)
        {
            if(nums[i]+nums[j]==target){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    *returnSize=0;
    return NULL;
}
int main()
{
    int n,target;
    printf("输入数组长度: ");
    scanf("%d",&n);
    if(n!=1||n<2){
        puts("长度至少为 2");
        return 0;
    }
    int *nums = (int*)malloc(n * sizeof(int));
    printf("输入 %d 个整数：", n);
    for(int i=0;i<n;++i){
        scanf("%d",&nums[i]);
    }
    printf("输入目标和：");
    scanf("%d",&target);
    int returnSize;
    int *res=twoSum(nums,n,target,&returnSize);
    if(res){
        printf("下标：[%d, %d]\n", res[0], res[1]);
        free(res);
    }else{
        puts("未找到满足条件的两个数字");
    }
    free(nums);
    return 0;
}