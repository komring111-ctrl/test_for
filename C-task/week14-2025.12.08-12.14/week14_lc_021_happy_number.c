#include<stdio.h>
#include<stdbool.h>
static int next_sum(int n){
    int sum=0;
    while(n){
        int d=n%10;// 取最低位
        sum+=d*d;// 把这位的平方累加
        n/=10;// 去掉最低位
    }
    return sum;
}
bool isHappy(int n) {
    int slow=n;
    int fast=n;
    do{
        slow=next_sum(slow);
        fast=next_sum(next_sum(fast));
    }while(slow!=fast);
    return slow==1;
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1){
        return 0;
    }
    printf("%s\n",isHappy(n)?"true":"false");
    return 0;
}
// 当相遇值确实是 1 时
// slow == 1 → 真 → isHappy 返回 true
// 于是 ? 运算符取 "true"，打印出来
// 当相遇值是 4、16、37…任何非 1 值时
// slow == 1 → 假 → isHappy 返回 false
// 于是 ? 运算符取 "false"，打印出来
// isHappy(n) ? "true" : "false"
// 完全取决于 slow==1 的真假，没有任何矛盾