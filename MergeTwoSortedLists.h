#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1==NULL)
    {
        return l2;
    }
    if (l2==NULL)
    {
        return l1;
    }
    typedef struct ListNode* ptr;
    ptr head,tail;
    if (l1->val<l2->val)
    {
        head=l1;
        l1=l1->next;
    }
    else
    {
        head=l2;
        l2=l2->next;
    }
    tail=head;
    while (l1!=NULL&&l2!=NULL)
    {
        if(l1->val<l2->val)
        {
            tail->next=l1;
            tail=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            tail=l2;
            l2=l2->next;
        }
        
    }
    if (l1==NULL)
    {
        tail->next=l2;
    }
    else
    {
        tail->next=l1;
    }
    return head;
    
}