/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL)
    {
        return NULL;
    }
    typedef struct ListNode* ptr;
    struct ListNode forgeNode;
    forgeNode.next=head;
    ptr temp=&forgeNode;
    ptr t1,t2;
    if(head->next!=NULL)
    {
        head=head->next;
    }
    while(temp->next!=NULL&&temp->next->next!=NULL)
    {
        t1=temp->next;
        t2=temp->next->next;
        temp->next=t2;
        t1->next=t2->next;
        t2->next=t1;
        temp=t1;
    }
    return head;
}