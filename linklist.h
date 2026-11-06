#pragma once
#define Maxsize 1000

typedef struct node//定义链表
{
    int val = 0;
    ListNode *next = nullptr;
} ListNode;

void createnode(ListNode* &h,int data);
void dropnode(ListNode*pre,ListNode *p);//链表的基本操作

typedef struct node2
{
    int val = 0;
    two_way_ListNode *pre = nullptr;
    two_way_ListNode *next = nullptr;
}two_way_ListNode;

typedef struct stack
{
    two_way_ListNode *top = nullptr;
}Stack;

void init_stack(Stack *s);
void stack_push(Stack *s, int data);
int stack_pop(Stack *s);

typedef struct queue
{
    two_way_ListNode *h;
    two_way_ListNode *end;
}Queue;

void init_queue(Queue *q);
void queue_push(Queue *q, int a);
int queue_pop(Queue *q);