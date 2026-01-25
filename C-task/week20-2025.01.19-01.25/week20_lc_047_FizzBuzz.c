#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **fizzBuzz(int n, int *returnSize)
{
    char **answer = (char **)malloc(n * sizeof(char *));
    for (int i = 1; i <= n; i++)
    {
        answer[i - 1] = (char *)malloc(9 * sizeof(char));
        if (i % 3 == 0 && i % 5 == 0)
        {
            strcpy(answer[i - 1], "FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            strcpy(answer[i - 1], "Fizz");
        }
        else if (i % 5 == 0)
        {
            strcpy(answer[i - 1], "Buzz");
        }
        else
        {
            sprintf(answer[i - 1], "%d", i);//将整数转换为字符串
        }
    }
    *returnSize = n;
    return answer;
}
int main()
{
    int n;
    printf("请输入整数 n: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("n必须大于0!\n");
        return 1;
    }
    int returnSize;
    char **result = fizzBuzz(n, &returnSize);
    printf("\n输出: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);
    return 0;
}