#include <stdio.h>
int thirdMax(int *nums, int numsSize)
{
    int n = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int existed = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] = nums[j])
            {
                existed = 1;
                break;
            }
        }
        if (!existed)
        {
            nums[n++] = nums[i];
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    return (n >= 3) ? nums[2] : nums[0];
}
int main()
{
    int arr[1000];
    int n;
    printf("请输入元素个数(<=1000): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("输入非法！\n");
        return 0;
    }
    printf("请依次输入%d个整数: ", n);
    for (int i = 0; i < n; i++)
    {
        scnaf("%d", &arr[i]);
    }
    int ans = thirdMax(arr, n);
    printf("第三大的数是:%d\n", ans);
    return 0;
}