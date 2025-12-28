#include <stdlib.h>
#include <stdbool.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
bool containsDuplicate(int *nums, int numsSize)
{
    if (numsSize < 2)
        return false;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}
int main(void)
{
    int a[] = {1, 2, 3, 1};
    int b[] = {1, 2, 3, 4};
    printf("%d\n", containsDuplicate(a, 4));
    printf("%d\n", containsDuplicate(b, 4));
    return 0;
}