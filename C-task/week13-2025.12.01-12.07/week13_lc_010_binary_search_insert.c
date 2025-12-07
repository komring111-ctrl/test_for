/*“请必须使用时间复杂度为 O(log n) 的算法”这句话就是强制你用「二分查找」——
除此之外的任何线性扫描（for/while 从头到尾）都不被允许，因为它们的复杂度是 O(n)。
O(log n) 的含义：
n 是数组长度
每做一次判断，就把搜索范围砍掉一半
最多砍 log₂n 次，所以运行时间与 n 呈对数关系，比线性快得多
在有序数组里，只有二分查找能达到这个复杂度。*/
#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int left=0,right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}
int main(){
    int nums[]={1,3,5,6};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int target=5;
    printf("index=%d\n",searchInsert(nums,numsSize,target));
    target=2;
    printf("index=%d\n",searchInsert(nums,numsSize,target));
    target=7;
    printf("index=%d\n",searchInsert(nums,numsSize,target));
    target=0;
    printf("index=%d\n",searchInsert(nums,numsSize,target));
    return 0;
}