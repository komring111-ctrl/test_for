#include<stdio.h>
#include<stdlib.h>
struct man{
    char name[20];
    int age;
}
person[3]={{"li",18},{"wang",25},{"sun",22}};
int main(){
    struct man *q=NULL;
    struct man *p=person;
    int i;
    int max_age=0;
    for(i=0;i<3;i++){
        if(p->age>max_age){
            max_age=p->age;
            q=p;
        }
        p++;
    }
    if(q!=NULL){
        printf("%s %d\n",q->name,q->age);
    }else{
        printf("没有找到人员信息。\n");
    }
    return 0;
}