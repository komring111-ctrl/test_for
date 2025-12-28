#include <stdbool.h>
#include <string.h>
#include <stdio.h>
bool isIsomorphic(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    char ST[512] = {0};
    char TS[512] = {0};
    strcpy(ST, s);
    strcat(ST, "#");
    strcat(ST, t);
    strcpy(TS, t);
    strcat(TS, "#");
    strcat(TS, s);
    for (int i = 0; ST[i]; ++i)
    {
        unsigned char c1 = (unsigned char)ST[i];
        unsigned char c2 = (unsigned char)TS[i];
        int pos1 = strchr(ST, c1) - ST;
        int pos2 = strchr(TS, c2) - TS;
        if (pos1 != pos2)
            return false;
    }
    return true;
}
int main(void){
    printf("egg vs add :%d\n",isIsomorphic("egg","add"));
    printf("foo vs bar :%d\n",isIsomorphic("foo","bar"));
    printf("paper vs title :%d\n",isIsomorphic("paper","title"));
    return 0;
}