#include <stdio.h>
#include <stdbool.h>
bool isUgly(int n)
{
    if (n <= 0)
        return false;
    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;
    while (n % 5 == 0)
        n /= 5;
    if (n == 1)
        return true;
    else
        return false;
}
int main()
{
    int num;
    printf("请输入一个整数: ");
    if (scanf("%d", &num) == 1)
    {
        printf("%d %s丑数\n", num, isUgly(num) ? "是" : "不是");
    }
    else
    {
        printf("输入格式错误!\n");
    }
    return 0;
}