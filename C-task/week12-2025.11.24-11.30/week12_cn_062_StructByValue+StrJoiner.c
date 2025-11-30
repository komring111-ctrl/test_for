#include<stdio.h>
struct student;
{
    int x;
    char c;
}a;
f(struct student b);
int main(){
    a.x=3;
    a.c='a';
    f(a);
    printf("%d,%c",a.x,a.c);
    return 0;
}
f(struct student b)
{
    b.x=20;
    b.c='y';
}
//因为 C 语言里结构体变量做实参时是“值传递”——函数得到的是一份副本。
//f(a) 内部改的是那份副本 b，原来的 a 纹丝不动，所以 main 里打印的依旧是 3,a。


// #include<stdio.h>
// #include<std;ib.h>
// #include<string.h>
// char* strconnect(char *str1,char *str2);
// int main(){
//     char str1[20],str2[20];
//     char *str;
//     puts("请输入两个字符串,用回车分开:");
//     scanf("%s%s",str1,str2);
//     str=strconnect(str1,str2);
//     puts(str);
//     return 0;
// }
// char* strconnect(char *str1,char *str2)
// {
//     char*str;
//     str=(char*)malloc(strlen(str1)+strlen(str2)+1); //malloc 得到的内存内容是 未初始化的垃圾值，里面随机是什么都有可能。
//     str[0]='\0';//为了让 strcat 能找到起点   dest 里必须先有一个合法的 '\0'，strcat 才知道“往哪儿接”。
//     strcat(str,str1);
//     strcat(str,str2);
//     return str;
// }