#include<stdio.h>
#define MAX
#define MAXIMUM(x,y) ((x)>(y)?(x):(y))
#define MINIMUM(x,y) ((x)>(y)?(y):(x))
int main(){
    int a=10,b=20;
#ifdef MAX  //if defined(X)	如果宏 X 已定义，就编译下面那段代码
    printf("更大的数字是%d\n",MAXIMUM(a,b));
#else
    printf("更小的数字是%d\n",MINIMUM(a,b));
#endif  //end if	结束条件编译块（必须有）
#ifndef MIN  //if not defined(X)	如果宏 X 没定义，就编译下面那段代码
    printf("更小的数字是%d\n",MINIMUM(a,b));
#else
    printf("更大的数字是%d\n",MAXIMUM(a,b));
#endif
#undef MAX  //undefine	取消宏 X 的定义（之后 #ifdef X 就为假）
#ifdef MAX
    printf("更大的数字是%d\n",MAXIMUM(a,b));
#else
    printf("更小的数字是%d\n",MINIMUM(a,b));
#endif
#define MIN 
#ifndef MIN
    printf("更小的数字是%d\n",MINIMUM(a,b));
#else
    printf("更大的数字是%d\n",MAXIMUM(a,b));
#endif
    return 0;
}