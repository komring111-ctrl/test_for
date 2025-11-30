#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filename[256];
    printf("输入你要保存到的文件的名称：\n");
    if (!fgets(filename, sizeof filename, stdin)) return 0;
    //fgets
    //filename->用来存放读入数据的缓冲区
    //sizeof filename->最大可读字节数（包括结尾 \0）,因此最多只能放 n-1 个有效字符。
    //stdin->输入流，通常是 stdin，也可以是任意已打开的 FILE *（文件、管道、socket）
    // 读到 n-1 个字符 → 停止，末尾加 \0，不丢弃行尾剩余字符（留在流里）。
    // 提前遇到 \n → 把 \n 也收进缓冲区，再加 \0。
    // 提前遇到 EOF → 把已读到的字符加 \0 返回；若一个都没读，返回 NULL。
    // 永远自动补 \0，调用者无需手动终止。
    filename[strcspn(filename, "\n")] = 0;   // 去掉末尾换行
//strcspn(s, reject) 扫描 s，返回 第一次出现 reject 字符集里任意字符 的下标
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("fopen"); return EXIT_FAILURE; }

    printf("现在你可以输入你要保存的一些字符，以#结束：\n");
    int ch;
    while ((ch = getchar()) != EOF && ch != '#')
        fputc(ch, fp);

    fclose(fp);
    puts("已保存！");
    return 0;
}