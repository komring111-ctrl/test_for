#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    int left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        if (nums[right] != 0)
        {
            nums[left] = nums[right];
            left++;
        }
    }
    while (left < numsSize)
    {
        nums[left] = 0;
        left++;
    }
}
int main()
{
    int nums[100];
    int numsSize;
    printf("请输入数组元素个数: ");
    scanf("%d", &numsSize);
    if (numsSize <= 0 || numsSize > 100)
    {
        printf("数组大小不合法！\n");
        return 1;
    }
    printf("请输入%d个整数(用空格分隔): ", numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("\n原始数组: [");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize - 1)
            printf(", ");
    }
    printf("]\n");
    moveZeroes(nums, numsSize);
    printf("移动零后: [");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize - 1)
            printf(", ");
    }
    printf("]\n");
    return 0;
}