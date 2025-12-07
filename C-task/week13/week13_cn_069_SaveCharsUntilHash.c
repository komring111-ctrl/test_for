#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE*fp=NULL;
    char filename[25];
    char ch;
    printf("输入你要保存到的文件的名称: \n");
    gets(filename);
    if((fp=fopen(filename,"w"))==NULL);
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    printf("现在你可以输入你要保存的一些字符, 以#结束：\n");
    getchar();
//  getchar()   作用：把上一次输入时留在输入缓冲区里的 回车符 吃掉。
//     背景：第 14 行 gets(filename); 读文件名时，你敲完文件名会按一次回车，这个回车符（\n）仍然留在缓冲区里。
// 如果不先清掉它，第 19 行的 while((ch=getchar())!='#') 会立即读到这个 \n，把它当成正文写进文件，结果文件开头就多了一个空行。
// 因此这里多调用一次 getchar() 把 \n 取走，保证后面真正开始读用户要保存的内容。
    while((ch=getchar())!='#'){
        fputc(ch,fp);//把刚刚读到的字符 ch 写入文件
    }
    fclose(fp);
    system("pause");
    return 0;
}