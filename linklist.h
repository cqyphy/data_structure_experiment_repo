#pragma once
#define Maxsize 1000

//定义链表
typedef struct 
{
    int val = 0;
    ListNode *next = nullptr;
} ListNode;

void createnode(ListNode* &h,int data);
void dropnode(ListNode*pre,ListNode *p);//链表的基本操作

//双向链表（用于实现栈和队列的链式储存结构）
typedef struct 
{
    int val = 0;
    two_way_ListNode *pre = nullptr;
    two_way_ListNode *next = nullptr;
}two_way_ListNode;

//定义栈
typedef struct 
{
    two_way_ListNode *top = nullptr;
}Stack;
//栈的基本操作
void init_stack(Stack *s);
void stack_push(Stack *s, int data);
int stack_pop(Stack *s);
bool stack_empty(Stack *s);

//定义队列
typedef struct 
{
    two_way_ListNode *h;
    two_way_ListNode *end;
}Queue;
//队列的基本操作
void init_queue(Queue *q);
void queue_push(Queue *q, int a);
int queue_pop(Queue *q);