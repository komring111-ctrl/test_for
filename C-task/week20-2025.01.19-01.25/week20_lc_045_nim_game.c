#include <stdio.h>
#include <stdbool.h>
bool canWinNim(int n)
{
    return n % 4 != 0;
}
int main()
{
    int n;
    printf("请输入石头数量 n: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("石头数量必须大于0!\n");
        return 1;
    }
    printf("\n石头数量: %d\n", n);
    bool result = canWinNim(n);
    printf("结果: %s\n", result ? "true(你能赢)" : "false(你会输)");
    printf("\n---分析---\n");
    if (n % 4 == 0)
    {
        printf("%d是4的倍数\n", n);
        printf("无论你怎么拿(1-3块), 对手都能凑成4, 最终你拿最后一块\n");
    }
    else
    {
        printf("%d不是4的倍数\n", n);
        printf("你先拿%d块, 剩下%d块(4的倍数), 对手必败\n", n % 4, n - n % 4);
    }
    return 0;
}