/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode *cur=&dummy;//cur 是“施工指针”，永远指向“结果链表里当前最后一个结点”
    dummy.next=NULL;//先把哑结点的 next 置空，代表结果链表目前还是空的
    while(list1&&list2){///当两条链都还有结点时，循环比较谁小谁就先接进来。
        if(list1->val<=list2->val){
            cur->next=list1;//把 list1 当前结点接到结果链末尾
            list1=list1->next;//list1 指针往后滑一格，准备下一次比较
        }
        else{
            cur->next=list2;
            list2=list2->next;
        }
        cur=cur->next;// 不管刚才接了谁，cur 自己都要往后挪一格，保持“指向结果链末尾”
    }
    cur->next=list1?list1:list2;//如果 list1 不是 NULL，就返回 list1；
                                //否则返回 list2
    return dummy.next;//哑结点的 next 就是真正结果链表的头指针，把它返回给调用者
}
struct ListNode* newNode(int val){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(*p));
    p->val=val;
    p->next=NULL;
    return p;
}
struct ListNode* buildList(int a[],int n){
    struct ListNode dummy,*tail=&dummy;
    dummy.next=NULL;
    for(int i=0;i<n;++i){
        tail->next=newNode(a[i]);
        tail=tail->next;
    }
    return dummy.next;
}
void printList(struct ListNode *head){
    for(;head;head=head->next){
        printf("%d",head->val);
    }
    printf("\n");
}
int main(){
    int a1[] = {1, 3, 5};
    int a2[] = {2, 4, 6};
    struct ListNode *l1 = buildList(a1, 3);
    struct ListNode *l2 = buildList(a2, 3);
    struct ListNode *merged = mergeTwoLists(l1, l2);
    printList(merged);  
    return 0;
}