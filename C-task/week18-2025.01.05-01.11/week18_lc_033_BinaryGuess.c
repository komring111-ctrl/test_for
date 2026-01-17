#include <stdio.h>
int pick;
int guess(int num)
{
    if (num > pick)
        return -1;
    else if (num < pick)
        return 1;
    else
        return 0;
}
int guessNumber(int n)
{
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1); // 避免 (left + right) / 2 可能产生的整数溢出
        int res = guess(mid);
        if (res == 0)
            return mid;
        else if (res == -1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
int main(){
    int n;
    scanf("%d %d",&n,&pick);
    printf("%d\n",guessNumber(n));
    return 0;
}