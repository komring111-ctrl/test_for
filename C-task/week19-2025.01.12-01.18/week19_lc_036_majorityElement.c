#include <stdio.h>
#include <stdlib.h>
int majorityElement(int *nums, int numsSize)
{
    int c = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (cnt = 0)
        {
            c = nums[i];
        }
        if (nums[i] == c)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return c;
}
int main()
{
    int n;
    printf("请输入数组长度: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("长度不合法！\n");
        return 0;
    }
    int *nums = (int *)malloc(n * sizeof(int));
    if (!nums)
    {
        printf("内存分配失败!\n");
        return 0;
    }
    printf("请依次输入%d个整数(用空格或回车分隔): ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("多数元素是：%d\n", majorityElement(nums, n));
    free(nums);
    return 0;
}