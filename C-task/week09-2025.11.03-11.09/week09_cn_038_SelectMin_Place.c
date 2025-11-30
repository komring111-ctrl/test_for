#include<stdio.h>
#define N 10
void selectionSort(int arr[],int n){
    int i,j,minIndex,temp;
    for(i=0;i<=n-1;i++){
        minIndex=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            
        }
    }
}
int main(){
    int arr[N];
    printf("请输入%d个数字:\n",N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,N);
    printf("排序结果是:\n");
    for(int i=0;i<N;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}