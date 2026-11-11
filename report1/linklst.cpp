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
    s->top = s->top->next;
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
   else {printf("Stack is empty"); return 0;}
}

bool stack_empty(Stack *s){
    if (s->top->pre == nullptr)
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
    q->end = tmp;
}

int queue_pop(Queue *q){
    if (q->h == q->end) return -1;
    two_way_ListNode *p = q->h->next;
    int data = p->val;
    q->h->next = p->next;
    if (p->next) {
        p->next->pre = q->h;
    } else {
        q->end = q->h; 
    }
    delete p;
    return data;
}

void BSt_push(BoxSt *p, Box a){
    p->data[p->top] = a;
    p->top ++;
}

void BSt_pop(BoxSt *p){
    p->top --;
}

bool BSt_empty(BoxSt *p){
    return p->top == 0;
}

Box BSt_gettop(BoxSt *p){
    return p->data[p->top-1];
}


void bque_push(bqueptr p,Box a){
    p->data[p->r] = a;
    p->r ++;
}

Box bque_pop(bqueptr p){
    Box res = p->data[p->f];
    p->f ++;
    return res;
}

bool bque_empty(bqueptr p){
    bool res = p->f == p->r;
    return res;
}