#include <stdio.h>
int hammingDistance(int x, int y)
{
    int xor = x ^ y;
    int count = 0;
    while (xor != 0)
    {
        if (xor % 2 == 1)
        {
            count++;
        }
        xor = xor / 2;
    }
    return count;
}
int main()
{
    int x, y;
    printf("请输入整数x: ");
    scanf("%d", &x);
    printf("请输入整数y: ");
    scanf("%d", &y);
    printf("x=%d,y=%d\n", x, y);
    printf("x^y=%d\n", x ^ y);
    printf("汉明距离=%d\n", hammingDistance(x, y));
    return 0;
}