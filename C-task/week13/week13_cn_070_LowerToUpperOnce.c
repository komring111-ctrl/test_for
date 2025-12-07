#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE*fp=NULL;
    char str[50];
    int i,len;
    printf("输入一个字符串: \n");
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]<='z'&&str[i]>='a'){
            str[i]-=32;
        }
        if((fp=fopen("test","w"))==NULL){
            printf("error: cannot open files!\n");
            exit(0);//立即终止整个程序，并把退出码 0 返回给操作系统，表示“正常结束”
            //这里只有当 fopen 失败时才会执行，防止继续往下运行导致段错误或写入空指针
        } 
    }
    fprintf(fp,"%s",str);//把当前整个字符串 str 一次性写进文件 test
    fclose(fp);
    system("pause");
    return 0;
}