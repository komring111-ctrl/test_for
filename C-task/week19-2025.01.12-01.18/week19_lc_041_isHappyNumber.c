#include <stdio.h>
#include <stdbool.h>
int next(int x)
{
    int sum = 0;
    while (x > 0)
    {
        int d = x % 10;
        sum += d * d;
        x /= 10;
    }
    return sum;
}
bool isHappy(int n)
{
    int slow = n;
    int fast = n;
    do
    {
        slow = next(slow);
        fast = next(next(fast));
    } while (slow != fast);
    return 1;
}
int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    printf("%s\n", isHappy(n) ? "true" : "false");
    return 0;
}