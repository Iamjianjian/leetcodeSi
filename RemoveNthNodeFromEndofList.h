/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode* ptr;
    ptr pre=head;
    int i=0;
    for (;i<n;i++)
    {
        pre=pre->next;
    }
    if (pre==NULL)
    {
        return head->next;
    }
    ptr mid=head;
    ptr temp;
    while (pre!=NULL)
    {
        pre=pre->next;
        temp=mid;
        mid=mid->next;
    }
    temp->next=mid->next;
    return head;
}