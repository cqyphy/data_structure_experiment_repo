#include "linklist.h"
#include <stdio.h>

void createnode(ListNode* &h,int data)
{
    h = new ListNode;
    h->val = data;
}

void dropnode(ListNode *pre,ListNode *p){
    pre->next = p->next;
    p->next = nullptr;
    delete p;
}

void init_stack(Stack *s){
    s->top = new two_way_ListNode;
}

void stack_push(Stack *s, int data){
    two_way_ListNode *n = new two_way_ListNode;
    n->val = data;
    n->pre = s->top;
    s->top->next = n;
}

int stack_pop(Stack *s){
   if (s->top->pre)
   {
        int a = s->top->val;
        two_way_ListNode *tmp = s->top;
        s->top = s->top->pre;
        delete tmp;
        return a;
   }
   else printf("Stack is empty");
}

bool stack_empty(Stack *s){
    if (s->top->val == 0)
    {
        return true;
    }
    else return false;
}

void init_queue(Queue *q){
    q->h = new two_way_ListNode;
    q->end = q->h;
}

void queue_push(Queue *q, int a){
    two_way_ListNode *tmp = new two_way_ListNode;
    tmp->val = a;
    tmp->pre = q->end;
    q->end->next = tmp;
}

int queue_pop(Queue *q){
    two_way_ListNode *p = q->h->next;
    int data = p->val;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete p;
    return data;
}