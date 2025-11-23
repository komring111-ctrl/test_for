#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 20
void swap(char *str1,char *str2);
int main(){
    char str1[MAX_LEN],str2[MAX_LEN],str3[MAX_LEN];
    printf("请输入3个字符串,每个字符串以回车结束:\n");
    fgets(str1,sizeof(str1),stdin);
    str1[strcspn(str1,"\n")]='\0';
    fgets(str2,sizeof(str2),stdin);
    str2[strcspn(str2,"\n")]='\0';
    fgets(str3,sizeof(str3),stdin);
    str3[strcspn(str3,"\n")]='\0';
    if(strcmp(str1,str2)>0){
        swap(str1,str2);
    }
    if(strcmp(str2,str3)>0){
        swap(str2,str3);
    }
    if(strcmp(str1,str2)>0){
        swap(str1,str2);
    }
    printf("排序后的结果为: \n");
    printf("%s\n%s\n%s\n",str1,str2,str3);
    return 0;
}
void swap(char *str1,char *str2){
    char temp[MAX_LEN];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}