#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
bool hasCycle(struct ListNode *head)
{
    if (!head)
        return false;
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
struct ListNode *newNode(int val){
    struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=val;
    p->next=NULL;
    return p;
}
int main(void){
    struct ListNode *n1=newNode(1);
    struct ListNode *n2=newNode(2);
    struct ListNode *n3=newNode(3);
    struct ListNode *n4=newNode(4);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    printf("无环: %s\n",hasCycle(n1)?"true":"false");
    n4->next=n2;
    printf("有环: %s\n",hasCycle(n1)?"true":"false");
    printf("无环: %s\n",hasCycle(NULL)?"true":"false");
    return 0;
}