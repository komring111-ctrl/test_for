#include <stdio.h>
int firstUniqChar(char *s)
{
    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        char letter = s[i];
        int index = letter - 'a';
        count[index]++;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        char letter = s[i];
        int index = letter - 'a';
        if (count[index] == 1)
            return i;
    }
    return -1;
}
int main(){
    char str[1000];
    printf("请输入只含小写字母的字符串：");
    if(scanf("%999s",str)!=1){
        printf("输入失败!\n");
        return 0;
    }
    int idx=firstUniqChar(str);
    if(idx==-1){
        printf("没有不重复的字符。\n");
    }
    else{
        printf("第一个不重复字符是'%c',下标为 %d。\n",str[idx],idx);
    }
    return 0;
}