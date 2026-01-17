#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL)
    {
        struct ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
struct ListNode *createList(int *arr, int n)
{
    if (n == 0)
        return NULL;
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }
    return head;
}
void printList(struct ListNode *head)
{
    while (head)
    {
        printf("%d", head->val);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
void freeList(struct ListNode *head)
{
    while (head)
    {
        struct ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    struct ListNode *head1 = createList(arr1, n1);
    printf("Original liat: ");
    printList(head1);
    head1 = reverseList(head1);
    printf("Reversed list: ");
    printList(head1);
    freeList(head1);
    return 0;
}