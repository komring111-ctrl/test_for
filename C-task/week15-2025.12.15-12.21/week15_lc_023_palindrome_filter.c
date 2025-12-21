#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char *s)
{
    int start = 0;
    int end = strlen(s) - 1;
    while (start < end)
    {
        while (start < end)
        {
            unsigned char c = s[start];
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                break;
            start++;
        }
        while (start < end)
        {
            unsigned char c = s[end];
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                break;
            end--;
        }
        unsigned char leftChar = s[start];
        unsigned char rightChar = s[end];
        if (leftChar >= 'A' && leftChar <= 'Z')
            leftChar += 32;
        if (rightChar >= 'A' && rightChar <= 'Z')
            rightChar += 32;
        if (leftChar != rightChar)
            return false;
        start++;
        end--;
    }
    return true;
}
int main(void){
    char *cases[]={
        "A man,a plan, acanal:Panama",
        "race a car",
        " ",
        "No 'x' in Nixon"
    };
    for(int i=0;i<4;++i){
        printf("\"%s\"->%s\n",cases[i],isPalindrome(cases[i])?"true":"false");
    }
    return 0;
}