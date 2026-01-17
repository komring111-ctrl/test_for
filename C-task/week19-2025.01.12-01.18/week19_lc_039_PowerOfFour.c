#include <stdio.h>
#include <stdbool.h>
bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0 && (n & 0x55555555) == n;
}
int msin()
{
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Input error!\n");
        return 0;
    }
    if (isPowerOfFour(n))
        printf("%d is a power of 4.\n", n);
    else
        printf("%d is NOT a power of 4.\n", n);
    return 0;
}