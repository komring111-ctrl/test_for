#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
    int res=0;
    for(int i=0;i<numsSize;++i){
        res=res^nums[i];//相同为1，不同为0
    }
    // res ^= x 就是“如果 x 第一次来，就留下；如果第二次来，就把第一次的 x 清掉”
    // 全部扫完，没被清掉的那个数就是答案
    return res;
}
int main(void){
    int n;
    printf("请输入数组长度: ");
    if(scanf("%d",&n)!=1||n<=0){
        printf("长度非法！\n");
        return 0;
    }
    int nums[100000];
    printf("请依次输入%d个整数(空格或回车分隔):\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("只出现一次的元素是: %d\n",singleNumber(nums,n));
    return 0;
}