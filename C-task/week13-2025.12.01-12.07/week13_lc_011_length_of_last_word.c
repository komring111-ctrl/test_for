#include<stio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int end=len-1;
    while(end>=0&&s[end]==' '){
        --end;
    }
    if(end<0){
        return 0;
    }
    int start=end;
    while(start>=0&&s[start]!=' '){
        --start;
    }
    return end-start;
}
int main(){
    char s[]="Hello World";
    printf("last word length=%d\n",lengthOfLastWord(s));
    char s2[]="   fly me   to   the  moon  ";
    printf("last word length=%d\n",lengthOfLastWord(s));
    char s3[]="a  ";
    printf("last word length=%d\n",lengthOfLastWord(s));
    return 0;
}