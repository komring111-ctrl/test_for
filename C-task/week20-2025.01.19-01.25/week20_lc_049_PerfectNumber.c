#include <stdio.h>
#include <stdbool.h>
bool checkPerfectNumber(int num)
{
    if (num <= 1)
    {
        return false;
    }
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int num;
    printf("请输入一个正整数：");
    scanf("%d", &num);
    printf("\n%d的正因子(除自身外): ", num);
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            printf("%d", i);
            sum = sum + i;
        }
    }
    printf("\n因子之和=%d\n", sum);
    bool result = checkPerfectNumber(num);
    if (result)
    {
        printf("%d是完美数!\n", num);
    }
    else
    {
        printf("%d不是完美数。\n", num);
    }
    return 0;
}