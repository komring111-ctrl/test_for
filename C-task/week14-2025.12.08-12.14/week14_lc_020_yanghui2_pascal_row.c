#include<stdio.h>
#include<stdlib.h>
int* getRow(int rowIndex, int* returnSize) {
    int n=rowIndex;
    int* row=malloc(sizeof(int)*(n+1));
    if(!row){
        *returnSize=0;
        return NULL;
    }
    row[0]=1;
    for(int k=1;k<=n;k++){
        row[k]=(long long)row[k-1]*(n-k+1)/k;
    }
    *returnSize=n+1;
    return row;
}
int main(void){
    int idx;
    if(scanf("%d",&idx)!=1){
        return 0;
    }
    int size;
    int* row=getRow(idx,&size);
    if(!row){
        return 0;
    }
    for(int i=0;i<size;i++){//0->n有n+1个(第n行元素个数)
        printf("%d%c",row[i],i+1==size?'\n':' ');
    }
    free(row);
    return 0;
}