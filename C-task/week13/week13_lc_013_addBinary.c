#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* addBinary(char* a, char* b) {
    int lenA=strlen(a);
    int lenB=strlen(b);
    int maxLen=lenA>lenB?lenA:lenB;
    char* res=(char*)malloc(maxLen+2);
    if(!res){//res 是调用 malloc 得到的指针  if (!res) 就是“如果 res 是空指针”——也就是内存分配失败
        return NULL;
    }
    int carry=0;
    int i=lenA-1,j=lenB-1,k=0;
    while(i>=0||j>=0||carry){
        int bitA=(i>=0)?(a[i--]-'0'):0;
        int bitB=(j>=0)?(b[j--]-'0'):0;
        int sum=bitA+bitB+carry;
        res[k++]=(sum&1)+'0';
        carry=sum>>1;//当前位 → 立刻写下来   进位 → 先记在草稿纸上，下一列再用
    }
    // | 意义       | 数学写法      | 位运算写法  |
    // | --------   | ---------    | ---------- |
    // |取余数(当前位)| `sum % 2`   | `sum & 1`  |
    // | 取商(进位)  | `sum / 2`    | `sum >> 1` |
    res[k]='\0';
    for(int left=0,right=k-1;left<right;++left,--right){
        char tmp = res[left];
        res[left] = res[right];
        res[right] = tmp;
    }
    return res;
}
int main(){
    char* a="1010";
    char* b="1011";
    char* sum=addBinary(a,b);
    printf("%s\n",sum);
    free(sum);
    return 0;
}