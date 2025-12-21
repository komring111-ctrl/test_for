#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode *deleteDuplicates(struct ListNode* head){
    if(!head){
        return NULL;
    }
    struct ListNode *cur=head;
    while(cur->next){
        if(cur->val==cur->next->val){
            struct ListNode *del=cur->next;
            cur->next=del->next;
            free(del);
        }
        else{
            cur=cur->next;
        }
    }
    return head;
}
struct ListNode* createList(){
    struct ListNode *head =NULL,*tail=NULL;
    int x;
    while(scanf("%d",&x)&&x!=-1){
        struct ListNode *node=(struct ListNode*)malloc(sizeof(struct ListNode));
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
void printList(struct ListNode *head){
    while(head){
        printf("%d",head->val);
        head=head->next;
    }
    printf("\n");
}
void freeList(struct ListNode *head){
    while(head){
        struct ListNode *tmp=head;
        head=head->next;
        free(tmp);
    }
}
int main(){
    printf("请输入升序列表，以-1结束: \n");
    struct ListNode *head=createList();
    head=deleteDuplicates(head);
    printf("去重后链表: \n");
    printList(head);
    freeList(head);
    return 0;
}