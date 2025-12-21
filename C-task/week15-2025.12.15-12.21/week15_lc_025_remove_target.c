#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head,int val){
    while(head!=NULL&&head->val==val){
        struct ListNode* garbage=head;
        head=head->next;
        free(garbage);
    }
    if(head==NULL){
        return NULL;
    }
    struct ListNode* prev=head;
    struct ListNode* cur=head->next;
    while(cur!=NULL){
        if(cur->val==val){
            prev->next=cur->next;
            free(cur);
            cur=prev->next;
        }
        else{
            prev=cur;
            cur=cur->next;
        }
    }
    return head;
}
struct ListNode* creatList(void){
    struct ListNode *head=NULL,*tail=NULL;
    int x;
    printf("请输入链表元素，以-1结束: \n");
    while(scanf("%d",&x)==1&&x!=-1){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=x;
        node->next=NULL;
        if(!head){
            head=tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
    return head;
}
void printList(struct ListNode* head){
    while(head){
        printf("%d",head->val);
        head=head->next;
    }
    printf("\n");
}
void freeList(struct ListNode* head){
    while(head){
        struct ListNode* tmp=head;
        head=head->next;
        free(tmp);
    }
}
int main(void){
    struct ListNode* head=creatList();
    int val;
    printf("请输入要删除的值：");
    scanf("%d",&val);
    printf("删除前");
    printList(head);
    head=removeElements(head,val);
    printf("删除后");
    printList(head);
    freeList(head);
    return 0;
}