#include<stdio.h>
int find_char(const char box[],char want)
{
    int count=0;
    for(count=0;box[count]!='\0';count++){
        char inside=box[count];
        if(inside==want)
            return count;//return后跳出循环
    }
    if(want=='0')
        return count;
    return -1;
}
int main(){
    const char word[]="hello world";
    int where=find_char(word,'o');
    if(where>=0)
        printf("字母'o'在第%d个盒子\n",where);
    else
        printf("没有这个字母\n");
    return 0;
}