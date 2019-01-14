// https://leetcode.com/problems/add-two-numbers/
#include<malloc.h>
 struct ListNode {
     int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a=0;
    int temp;
    ListNode*hh,*t;
    ListNode* h=(ListNode*)malloc(sizeof(ListNode));
    hh=h;
    while(l1!=nullptr&&l2!=nullptr)
    {
        temp=(l1->val+l2->val+a);
        h->val=temp%10;
        a=temp/10;
        h->next=(ListNode*)malloc(sizeof(ListNode));
        t=h;
        h=h->next;
        l1=l1->next;
        l2=l2->next;
    }
    if (l1==nullptr&&l2==nullptr&&a==0)
    {
        free(h);
        t->next=nullptr;
        return hh;
    }
    if (l1==nullptr&&l2==nullptr)
    {
        h->val=1;
        h->next=nullptr;
        return hh;
    }
    if(l1==nullptr)
    {
        l1=l2;
    }
    while(l1!=nullptr)
    {
        temp=(a+l1->val);
        l1=l1->next;
        h->val=temp%10;
        a=temp/10;
        t=h;
        h->next=(ListNode*)malloc(sizeof(ListNode));
        h=h->next;
    }
    if(a==0)
    {
        free(h);
        t->next=nullptr;
        return hh;
    }
    h->val=1;
    h->next=nullptr;
    return hh;
}