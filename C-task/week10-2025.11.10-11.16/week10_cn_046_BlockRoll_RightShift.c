#include<stdio.h>
void shiftArray(int arr[],int n,int m){
    int temp[m];
    for(int i=n-m,j=0;i<n;i++,j++){
        temp[j]=arr[i];//暂存末尾m个元素,i=4,5.6
    }
    for(int i=n-m-1;i>=0;i--){
        arr[i+m]=arr[i];//n=7,m=3,i=3->i+m=6
    }
    for(int i=0;i<m;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int n,m;
    printf("请输入整数个数n: ");
    scanf("%d",&n);
    printf("请输入向后移动的位置m: ");
    scanf("%d",&m);
    int arr[n];
    printf("请输入%d个整数: ",n);
    fpr(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    shiftArray(arr,n,m);
    printf("移动后的数组: ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}