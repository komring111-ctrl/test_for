#include <stdio.h>
int missingNumber(int *nums, int numsSize)
{
    int n = numsSize;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        actualSum += nums[i];
    }
    return expectedSum - actualSum;
}
int main()
{
    int nums[100];
    int numsSize;
    printf("请输入数组元素个数 n: ");
    scanf("%d", &numsSize);
    printf("请输入%d个整数(范围[0,%d], 缺失一个数：", numsSize, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("\n输入数组: [");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize - 1)
            printf(", ");
    }
    printf("]\n");
    int result = missingNumber(nums, numsSize);
    printf("缺失的数字: %d\n", result);
    return 0;
}