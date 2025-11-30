#include<stdio.h>
#include<stdlib>
#include<time.h>
int ask_to_play_again(){
    char begin;
    printf("需要挑战最高级别不?Y/N \n");
    scanf(" %c",&begin);
    if(begin=='Y'||begin='y'){
        return 1;
    }
    printf("谢谢,再见!\n");
    return 0;
}
void caizi(void){
    int n;
    int count=1;
    srand((unsigned int)time(NULL));
    int m=(rand()%100)+1;
    printf("游戏开始,请输入数字:\n");
    while(1){
        scanf("%d",&n);
        if(n==m){
            printf("猜中了,使用了%d次!\n",count);
            if(count==1){
                printf("你是神级人物了!膜拜\n");
            }else if(count<=5){
                printf("你是王级人物了!非常赞\n");
            }else if(count<=10){
                printf("你是大师级人物了!狂赞\n");
            }else if(count<=15){
                printf("你是钻石级人物了!怒赞\n");
            }else {
                printf("你的技术还有待提高哦!\n");
            }
            if(ask_to_play_again()){
                caizi();
            }
            break;
        }else if(n<m){
            puts("太小了!");
            puts("重新输入:");
        }else{
            puts("太大了!");
            puts("重新输入:");
        }
        count++;
    }
}
int main(){
    caizi();
    return 0;
}