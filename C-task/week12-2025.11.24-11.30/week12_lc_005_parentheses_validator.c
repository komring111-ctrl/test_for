#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
bool isValid(char*s){
    int n=strlen(s);
    char *st=malloc(n+1);
    int top=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        switch(c){
            case '(':
                st[top]=')';
                top++;
                break;
            case '[':
                st[top]=']';
                top++;
                break;
            case '{':
                st[top]='}';
                top++;
                break;
            default:
                if(top==0||st[--top]!=c){
                    free(st);
                    return false;
                }
        }
    }
    free(st);
    return top==0;
}