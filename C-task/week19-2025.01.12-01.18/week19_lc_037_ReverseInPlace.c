#include <stdio.h>
void reverseString(char *s, int sSize)
{
    int left = 0, right = sSize - 1;
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
int main(void)
{
    char s[1001];
    printf("请输入要反转的字符串(不超过1000个字符): ");
    fgets(s, sizeof(s), stdin);
    int sSize = 0;
    while (s[sSize] != '\0' && s[sSize] != '\n')
    {
        sSize++;
    }
    reverseString(s, sSize);
    printf("反转后: %.*s\n", sSize, s);//从 s 里取出 前 sSize 个字符 打印出来，不管后面有没有 \n 或其他垃圾
    return 0;
}
/*%[最小宽度][.精度]说明符
把 %.*s 拆开看：
%        —— 格式串开始
*        —— “精度”不由字面写出，而是由 参数列表里再传一个 int 进来 指定
.        —— 分隔符，告诉 printf “前面是宽度，后面是精度”
s        —— 说明符，表示要打印的是字符串*/