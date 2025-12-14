#include<stdio.h>
#include<stdlib.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ans=(int**)malloc(sizeof(int*)*numRows);
    int* cols=(int*)malloc(sizeof(int)*numRows);
// ans 本身：一次 malloc，得到 numRows 个 int*
// 每个 ans[i]：再分别 malloc，得到 i+1 个 int
// 释放时先逐行 free(ans[i])，再 free(ans) 和 free(returnColumnSizes) 即可
    for(int i=0;i<numRows;i++){
        cols[i]=i+1;
        ans[i]=(int*)malloc(sizeof(int)*cols[i]);
        ans[i][0]=ans[i][i]=1;
        for(int j=1;j<i;j++){
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    *returnSize=numRows;// 一共有多少行
    *returnColumnSizes=cols;//每一行又有几列,负责带出「每行列数数组的首地址」
    return ans;
}
int amin(){
    int numRows;
    printf("numRows= ");
    scanf("%d",&numRows);
    int returnSize;
    int* returnColumnSizes;
    int** triangle=generate(numRows,&returnSize,&returnColumnSizes);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];i++){
            printf("%d",triangle[i][j]);
        }
        printf("\n");
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);
    return 0;
}