#include <stdio.h>
int addDigits(int num)
{
    while (num >= 10)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10; // 个位
            num /= 10;       // 去掉个位
        }
        num = sum;
    }
    return num;
}
int main()
{
    unsigned int num;
    if (scanf("%u", &num) != 1)
        return 0;
    printf("%d\n", addDigits((int)num));
    return 0;
}
/*把 int 换成 unsigned int（或 uint32_t）只有一个目的：
保证右移是“逻辑右移”（高位永远补 0），而不是“算术右移”（高位补符号位）。
在“数字 → 十六进制字符串”这类位运算题目里，我们需要一位一位地把高位往低位搬，再取低 4 位。
如果变量是有符号负数，算术右移会把符号位 1 一直右移，导致死循环或者结果多出连续的 f。
举个 8-bit 的直观例子（32-bit 同理）：
表格
复制
操作	signed char (-1)	unsigned char (255)
二进制初始	1111 1111	1111 1111
右移 1 位	1111 1111 （算术，补1）	0111 1111 （逻辑，补0）
可以看到：
对 signed 做 >> 永远得不到 0，循环退不出；
对 unsigned 做 >> 高位补 0，最终会变成 0，循环能正常结束。*/