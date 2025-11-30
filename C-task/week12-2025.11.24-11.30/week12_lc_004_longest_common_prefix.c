#include<stdlib.h>
#include<string.h>
char *longestCommonPrefix(char **strs, int strsSize){
    if(strsSize==0)
        return strdup("");//返回一个长度为 0 的合法空串
    int len=strlen(strs[0]);
    for(int i=0;i<len;++i){
        char c=strs[0][i];
        for(int j=1;j<strsSize;++j){
            if (strs[j][i] != c || strs[j][i] == '\0') {
                char *ans = (char *)malloc(i + 1);
                memcpy(ans, strs[0], i);//只复制 i 个字节，不复制结尾的 \0（memcpy 不会自动加）
                ans[i] = '\0';//把结束符补上
                return ans;
            }
        }
    }
    return strdup(strs[0]);
}