#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fa,*fb,*fc;
    int i,j,k;
    char str[100],str1[100];
    char tem;
    if((fa=fopen("A.txt","r"))==NULL)
    {
        printf("error: cannot open A file!\n");
        exit(0);
    }
    fgets(str,99,fa);// 从文件指针 fa 指向的文件里 最多读取 98 个字符（留 1 字节给 '\0'），存到字符数组 str 中
                     //读取过程遇到 换行符 或 EOF 也会停止，并在 str 末尾自动补 '\0'
    fclose(fa);
    if((fb=fopen("B.txt","r"))=NULL)
    {
        printf("error: cannot open B file!\n");
        exit(0);
    }
    fgets(str1,100,fb);
    fclose(fb);
    strcat(str,str1);
    for(i=strlen(str)-1;i>1;i--){
        for(j=0;j<i;j++){
            if(str[j]>str[j+1])
            {
                tem=str[j];
                str[j]=str[j+1];
                str[j+1]=tem;
            }
        }
    }
    if((fc=fopen("C.txt","w"))==NULL)
    {
        printf("error: cannot open C file!\n");
        exit(0);
    }
    fputs(str,fc);//把整个字符串 str（从首字符到 '\0' 之前的全部字符）一次性写进文件指针 fc 指向的文件；
                  //不会自动补换行，也不会写结尾的 '\0'
                  //fputc(ch,fc)
                  //只写单个字符 ch 到文件，必须逐字调用
    fclose(fc);
    system("pause");
    return 0;
}