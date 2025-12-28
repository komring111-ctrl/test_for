#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define BASE 0
#define SIZE 2000001
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (k <= 0 || numsSize < 2)
        return false;
    bool *window = calloc(SIZE, sizeof(bool));
    int left = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int idx = (nums[i] % SIZE + SIZE) % SIZE; // 保证非负     把任意 int 映射到 0..SIZE-1
        if (window[idx])
        {
            free(window);
            return true;
        }
        window[idx] = true;
        if (i - left >= k)
        {
            int leftIdx = (nums[left] % SIZE + SIZE) % SIZE;
            window[leftIdx] = false;
            ++left;
        }
    }
    free(window);
    return false;
}
int main(void)
{
    int a[] = {1, 2, 3, 1};
    int b[] = {1, 0, 1, 1};
    int c[] = {1, 2, 3, 4};
    printf("a[] k=3->%d (expect 1)\n", containsNearbyDuplicate(a, 4, 3));
    printf("b[] k=1->%d (expect 1)\n", containsNearbyDuplicate(b, 4, 1));
    printf("c[] k=2->%d (expect 0)\n", containsNearbyDuplicate(c, 4, 2));
}

// bool *window = calloc(SIZE, sizeof(bool));
//  calloc 是什么？
//  C 标准库函数，专门 申请内存 + 自动清零。
//  原型：void *calloc(size_t 个数, 每个字节大小);
//  SIZE 是多少？
//  宏定义 2000001，表示要 200 万零 1 个 布尔格子。
//  sizeof(bool) 是多少？
//  在主流编译器里是 1 字节，所以总共申请 200 万零 1 字节 ≈ 2 MB。
//  返回值 bool *window
//  calloc 返回 void *，这里自动转成 bool *，取名 window。
//  你可以把 window 当成 超大型 bool 数组，下标范围 0 … 2000000。
//  因为清零过，每个元素初始都是 false，后续只要 window[idx] = true; 就相当于“插旗”。
