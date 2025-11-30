#include<stdio.h>
#include<string.h>
int romanToInt(char *s){
    int val[128]={0};
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;
    int n=strlen(s);
    int ret=val[s[n-1]];
    for(int i=n-2;i>=0;--i){
        if(val[s[i]]<val[s[i+1]])
            ret-=val[s[i]];
        else
            ret+=val[s[i]];
    }
    return ret;
}
int main(void){
    char buf[16];
    while(scanf("%15s",buf)==1){
        printf("%d\n",romanToInt(buf));
    }
    return 0;
}