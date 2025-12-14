int climbStairs(int n) {
    if(n==0||n==1){
        return 1;
    }
    int a=1;
    int b=1;
    for(int i=2;i<=n;i++){
        int next=a+b;
        a=b;
        b=next;
    }
    return b;
}
#include<stdio.h>
int main(void){
    int n;
    printf("请输入台阶数n: ");
    if(scanf("%d",&n)!=1){
        return 0;
    }
//     if (scanf("%d", &n) != 1) return 0; 这一句并不是在“处理 n == 1”，而是在检查 scanf 的返回值：
// scanf 成功读入 1 个整数时返回 1；
// 如果用户直接按了 Ctrl-D（Linux/macOS）或 Ctrl-Z（Windows），导致输入流结束，scanf 会返回 EOF（通常是 -1），此时 n 的值根本不会被写入；
// 如果用户输入了非法字符（比如字母），scanf 返回 0，同样没有给 n 赋有效值。
//if (scanf("%d", &n) != 1) return 0与scanf("%d",n);if(n!=1);是不同的
    printf("共有%lld种走法\n",climbStairs(n));
    return 0;
}