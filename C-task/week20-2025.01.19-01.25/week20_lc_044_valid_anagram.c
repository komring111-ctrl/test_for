#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
    {
        return false;
    }
    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char s[1000];
    char t[1000];
    printf("请输入字符串 s: ");
    scanf("%s", s);
    printf("请输入字符串 t: ");
    scanf("%s", t);
    printf("\n输入:\n");
    printf("s=\"%s\"\n", s);
    printf("s=\"%s\"\n", t);
    bool result = isAnagram(s, t);
    printf("\n输出: %s\n", result ? "true" : "false");
    return 0;
}