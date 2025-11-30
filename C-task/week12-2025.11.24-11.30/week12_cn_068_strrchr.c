#include<stdio.h>
int find_last_char(const char box[],char want)
{
    int last=-1;
    int i;
    for(i=0;box[i]!='\0';i++){
        if(box[i]==want){
            last=i;
        }
    }
    if(want=='\0'){
        return i;
    }
    return last;
}
int main(){
    const char word[]="hello world";
    int where=find_last_char(word,'o');
    if(where!=-1){
        printf("最后一个'o'在第%d个盒子",where);
    }
    else{
        printf("没有这个字母\n");
    }
    return 0;
}