#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0&&j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
            // nums1[k]=nums1[i];
            // k--;
            // i--;
        }
        else{
            nums1[k--]=nums2[j--];
            // nums1[k]=nums2[j];
            // k--;
            // j--;
        }
    }
    //若nums1还有剩余，不需要再排
    //若 nums2 还有剩余，直接拷贝到前面
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}
int main(void){
    int m,n;
    printf("请输入nums1的有效长度m: ");
    if(scanf("%d",&m)!=1){
        return 0;
    }
    printf("请输入nums2的长度n: ");
    if(scanf("%d",&n)!=1){
        return 0;
    }
    int *nums1=malloc((m+n)*sizeof(int));
    int *nums2=malloc(n*sizeof(int));
    if(!nums1||!nums2){
        return 0;
    }
//     malloc 向系统申请堆内存。
// 申请成功：返回一块可用的起始地址（非 0）。
// 申请失败：返回 NULL（也就是 0）。
// !nums1 就是 nums1 == NULL 的简写，含义是：
// “如果 nums1 没拿到内存，或者 nums2 没拿到内存，就立刻结束程序，避免后面继续用空指针导致崩溃。”
    printf("请按非递减顺序输入%d个整数(nums1): ",m);
    for(int i=0;i<m;i++){
        scanf("%d",&nums1[i]);
    }
    printf("请按非递减顺序输入%d个整数(nums2): ",n);
    for(int j=0;j<n;j++){
        scanf("%d",&nums2[j]);
    }
    merge(nums1,m,nums2,n);
    printf("合并结果: ");
    for(int i=0;i<m+n;i++){
        printf("%d",nums[i]);
    }
    printf("\n");
    free(nums1);
    free(nums2);
    return 0;
}