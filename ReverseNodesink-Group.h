#include<stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// https://leetcode.com/problems/reverse-nodes-in-k-group/
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode* ptr;
typedef struct ListNode Node;
struct ListNode* reverseKGroupHelper(struct ListNode* head, int k) {// reverse  k node  and unchange head
    ptr pre=head,mid=head->next,tail;
    int i;
    for(i=1;i<k;i++)
    {
        tail=mid->next;
        mid->next=pre;
        pre=mid;
        mid=tail;
    }
    return pre;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k==1||head==NULL||head->next==NULL)// zero elements one elements or do nothing
    {
        return head;
    }
    int i=0;
    ptr result=head;
    for (i=1;i<k;i++)//the ptr return
    {
        result=result->next;
        if(result==NULL)
        {
            return head;
        }
    }
    Node tempNode;
    ptr pre=&tempNode,h=head,t,tt;
    while(true)
    {
        t=h;
        for(i=1;i<k;i++)// each k group reverse ,t over tail
        {
            if(t->next==NULL)// not enough k node
            {
                return result;
            }
            t=t->next;
        }
        tt=t->next;
        reverseKGroupHelper(h,k);
        h->next=tt;
        pre->next=t;
        pre=h;
        h=tt;
        if(h==NULL)
        {
            return result;
        }
    }

}