#include<stdbool.h>
#define BASE 1000000
#define SIZE 2000001
bool containsDuplicate(int* nums, int numsSize) {
    static bool hash[SIZE];
    //把整块内存全部清零，让数组每个元素都变成 false（也就是 0）
    memset(hash,0,sizeof(hash));//for (int i = 0; i < SIZE; ++i) hash[i] = false;
    for(int i=0;i<numsSize;i++){
        int idx=nums[i]+BASE;
        if(hash[idx]){
            return true;
        }
        hash[idx]=true;
    }
    return false;
}
int main(void){
    int a[]={1,2,3,1};
    int b[]={1,2,3,4};
    printf("%d\n",containsDuplicate(a,4));
    printf("%d\n",containsDuplicate(b,4));
    return 0;
}